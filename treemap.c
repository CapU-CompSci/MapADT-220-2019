/*
 * Comp220 - treemap.c
 * Implementation of treemap ADT
 *
 * Authors: Andre Wakkary, Karan Nedungadi, Levi Holmes, Joshua Yeh, Charmaine Neufeld, Keaton Armstrong
 * Date: April 5, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "treemap.h"
#include "map.h"

/******************************************
 * ----- HELPER FUNCTION PROTOTYPES ----- *
 ******************************************/

// ----- FINDERS -----
bstNode_t* entryFind(map_t t, keytype key);
bstNode_t* findSmallestNode(map_t node);
bstNode_t* findInsertionPoint(map_t map, keytype key);
bstNode_t* findLargestNode(map_t map);
bstNode_t* findParent(map_t map, keytype key);

// ----- DELETERS -----
void leafDelete(map_t* cur, map_t parent);
void oneChildDelete(map_t* cur, map_t parent);
void twoChildDelete(map_t* cur, map_t parent);

// ----- MISC. HELPERS -----
int keyCompare(keytype insertkey, keytype mapkey);
bool mapIsEmpty(map_t tree);
void getEntries(map_t map, entry_t* entries[]);
void traverseInOrder(map_t map, entry_t* entries[], int index);
void mapPrint(map_t map);
int keyCompare(keytype insertkey,keytype mapkey);

/*****************************
 * ----- MAP FUNCTIONS ----- *
 *****************************/

/*
 * Constructor (of node) - return a new, node with given vakue and key
 */
bstNode_t* nodeCreate(valuetype value, keytype key){
	bstNode_t* node = malloc(sizeof(bstNode_t));
	node->entry.value = value;
	node->entry.key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/*
 * Constructor - return a new, empty map
 * POST:  mapSize(map) == 0
 */
map_t mapCreate(){
	map_t map = NULL;
	return map;
}

/*
* POST: Get(key) == value
* sets the value for key if HasKey(key), otherwise inserts a new value in Map
*/
void mapInsert(map_t* map, keytype key, valuetype value){
	bstNode_t* curr = *map;
	
	if(curr == NULL){
	
		*map = nodeCreate(value,key);
		return;
	}
	if(keyCompare(key, curr->entry.key)<0)
	{
		mapInsert(&curr->left, key, value);
	}
	else if(keyCompare(key, curr->entry.key)>0)
	{
		mapInsert(&curr->right, key, value);
	}
}

/*
 * removes the (key, value) pair from the Map, no effect if !HasKey(key)
 * POST: HasKey(key) == false
 */
void mapRemove(map_t* mapref, keytype key){ //differnt type names between keytype and char* key....
	map_t map = *mapref;
	if(!mapHasKey(map, key)){
		return;
	}
	map_t cur;
	bstNode_t* parent = findParent(map, key); // IMPROVE: just findParent, then cur is one of its children!
	
	if(parent == NULL){  //if parent is the root (Needs to change/checked/evaluated)
		parent = map;
		cur = map;
	}
	else if(!mapIsEmpty(parent->left) && parent->left->entry.key == key){
		cur = parent->left;
	}
	else{
		cur = parent->right;
	}
	
	if(cur->left == NULL && cur->right == NULL){
		leafDelete(&cur, parent);
		return;
	}
	else if(cur->left != NULL && cur->right != NULL){
		twoChildDelete(&cur, parent);
		return;
	}
	else if(cur->left == NULL || cur->right == NULL){
		oneChildDelete(&cur, parent);
		return;
	}
}

/*
* PRE: HasKey(key)
* returns the value associated with the given key
*/
valuetype mapGet(map_t map, keytype key){
	assert(mapHasKey(map,key));
	return entryFind(map,key)->entry.value;
}

/*
* returns true iff the Map contains the given key
*/
bool mapHasKey(map_t map, keytype key){
	if(entryFind(map,key) == NULL){	//if entry does not exist		
		return false;
	}
	return(entryFind(map,key)->entry.key == key);
}

/*
 *returns the number of (key, value) pairs in the Map
 */
int mapSize(map_t map){
	if(mapIsEmpty(map)){
		return 0;
	}
	return 1 + mapSize(map->left) + mapSize(map->right);
}

/*
* POST: Size() == 0
* removes all items from the Map (without creating memory leaks!)
*/
void mapClear(map_t * map){
	map_t curr = *map;
	if(curr != NULL){
		mapClear(&curr->left);
		mapClear(&curr->right);
		free(curr);
	}
	*map = NULL;
}

/*
* returns a dynamic array containing all the Map Keys (in any sequence)
* it is the caller's responsibility to free the returned array.
* Use of a List ADT here would help reduce complexity as current algoirthm needs to manage dynamic arrays
*/
keytype* mapKeySet(map_t* mapref)
{
	map_t map = *mapref;
	int size = mapSize(map);
	// Get pointers to all the entries
	entry_t** entries = calloc(size, sizeof(entry_t*));
	getEntries(map, entries);
	// Extract the keys	
	keytype* keys = calloc(size, sizeof(keytype));
	int i = 0;
	for(i=0; i<size; i++){
		keys[i] = entries[i]->key;
	}
	free(entries);

	return keys;
}

/*********************************
 *  ----- HELPER FUNCTIONS ----- *
 *********************************/
 
// ----- FINDERS -----
 
/*
 * Helper function for finding a key in tree
 */
bstNode_t* entryFind(map_t t, keytype key){
	if(t == NULL){
		return NULL;	
	}
	if(keyCompare(key, t->entry.key)==0){
		return (t);
	}
	if(keyCompare(key,t->entry.key)<0){
		return entryFind(t->left,key);
	}
	if(keyCompare(key,t->entry.key)>0){
		return entryFind(t->right,key);
	}
	
}
 
/*
 * finds the smallest node in the tree.
 */
bstNode_t* findSmallestNode(map_t node){ //check
	if(mapIsEmpty(node)){
		return NULL;
	}
	if(mapIsEmpty(node->left)){
		return node;
	}
	findSmallestNode(node->left);
} 
 
/*
 * Finds the appropirate pointer to insert the given key in the tree.
 */
bstNode_t* findInsertionPoint(map_t map, keytype key){ 
	// needs work -- this algorithm needs to return a pointer to an insertion point, not just NULL!
	//    have a look at the code we wrote for the BST in lab9.
	bstNode_t* curr = map;
	if(curr == NULL)
	{
		return curr;
	}
	if(keyCompare(key, curr->entry.key)<0)
	{
		return findInsertionPoint(map->left, key);
	}
	else if (keyCompare(key, curr->entry.key)>0)
	{
		return findInsertionPoint(map->right, key);
	}
	return NULL;
}

/*
 * Finds the largest node in the tree.
 */
bstNode_t* findLargestNode(map_t map){
	if(mapIsEmpty(map)){
		return NULL;
	}
	if(mapIsEmpty(map->right)){
		return(map);
	}
	return findLargestNode(map->right);
}

/*
 * Finds the parent node of the given key.
 */
bstNode_t* findParent(map_t map, keytype key){
	bstNode_t* parent = map;
	if(mapIsEmpty(map)){//
		return NULL;
	}
	else if(!mapIsEmpty(map->left) && keyCompare(key, parent->left->entry.key) == 0 || !mapIsEmpty(map->right) && keyCompare(key, parent->right->entry.key) == 0){
		return(parent);	
	}
	else if(keyCompare(key,parent->entry.key)<0){
		return findParent(parent->left,key);
	}
	else if(keyCompare(key,parent->entry.key)>0){
		return findParent(parent->right,key);
	}
	
	return NULL;
}

// ----- DELETERS -----

/*
 *Helper function to delete leaf node
 */
void leafDelete(map_t* cur, map_t parent){
	bstNode_t* curr = *cur;
	if(parent->left = curr){
		parent->left = NULL;
	}
	else{
		parent->right = NULL;
	}
	free(curr);
}

/*
 *Helper function to delete one child node
 */
void oneChildDelete(map_t* cur, map_t parent){
	bstNode_t* curr = *cur;
	if(curr->left != NULL){
		parent->left = curr->left;
	}
	else{
		parent->right = curr->right;
	}
	free(curr);
	
}

/*
 *Helper function to delete two child node
 */
void twoChildDelete(map_t* mapref, map_t parent){
	map_t map = *mapref;
	if(keyCompare(parent->entry.key, map->entry.key)>0){
		bstNode_t* smallest = findSmallestNode(parent->right);
		bstNode_t* smallestparent = findParent(map, smallest->entry.key);
		parent->entry = smallest->entry;
		smallestparent->left = NULL;
		free(smallest);
		return;

	}
	else if(keyCompare(parent->entry.key, map->entry.key)<0){
		bstNode_t* largest = findLargestNode(parent->left);
		bstNode_t* largestparent = findParent(map, largest->entry.key);
		parent->entry = largest->entry;
		largestparent->right = NULL;
		free(largest);
		return;
	}
}

// ----- MISC. HELPERS -----
/*
 *returns 1 if insertkey>mapkey, -1 if insertkey<mapkey, and 0 if ==
 */

int keyCompare(keytype insertkey, keytype mapkey){
	return strcmp( insertkey, mapkey);
}
/*
* returns tree if the tree is empty.
*/
bool mapIsEmpty(map_t tree){
	return tree == NULL;
}

/*
* helper function:  generate a list of all entries in the map.
* PRE: entries array is sized >= mapSize(map)
* POST: entries array is filled with pointers to map entries, in "in order" sequence
*/
void getEntries(map_t map, entry_t* entries[]){
	traverseInOrder(map, entries, 0);
}

/*
* helper function:  traverse the tree to generate the list of entries.
* PRE: entries array is sized >= mapSize(map);  0 <= index < mapSize(map)
* POST: entries array is filled with pointers to map entries, in "in order" sequence
*/
void traverseInOrder(map_t map, entry_t* entries[], int index){
	
	if(map != NULL){  
		if(!mapIsEmpty(map->left)){
			traverseInOrder(map->left, entries, index);
			index++;
		}
		entries[index] = &(map->entry);
	// a pointer to the entry, not a copy!
		index++;
		if(!mapIsEmpty(map->right)){
			traverseInOrder(map->right, entries, index);
		}
	}							
}

/*
 * helper function:  Prints the map in order
 * 
 */
void mapPrint(map_t map)
{
	if(map != NULL){
		mapPrint(map->left);
		printf("|%s|\t|%d|\n\n", map->entry.key, map->entry.value);
		mapPrint(map->right);
	}
}

