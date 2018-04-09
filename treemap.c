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

#include "treemap.h"
#include "map.h"

/*********************
 *  PRIVATE IMPLEMENTATION
 *********************/

// HELPER FUNCTION PROTOTYPES
bstNode_t* bstFind(BinaryTree t, keytype key);
bool mapIsEmpty(map_t tree);
bstNode_t* findLargestNode(map_t map);
bstNode_t* findInsertionPoint(map_t map, keytype key);
void getEntries(map_t map, entry_t* entries[]);
void traverseInOrder(map_t map, entry_t* entries[], int* index);
bstNode_t* findParent(map_t map, keytype key);
bstNode_t* findSmallestNode(map_t);
bstNode_t* nodeCreate(valuetype value, keytype key);


/*
 * Constructor (of node) - return a new, node with given vakue and key
 */
bstNode_t* nodeCreate(valuetype value, keytype key){
	bstNode_t* node = malloc(sizeof(bstNode_t));
	node->entry.value = 0;
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
	bstNode_t* curr = findInsertionPoint(*map,key);
	if(mapHasKey(*map, key)){
		curr->entry.value = value;
	}
	else{
		curr = nodeCreate(value,key);	
	}
}


/*
* Helper function. 
* Finds the parent node of the given key.
*/
bstNode_t* findParent(map_t map, keytype key)
{
	bstNode_t* parent;
		if(mapIsEmpty(map)){
		return NULL;
	}
	else if(map->left->entry.key == key || map->right->entry.key == key){
		return(map);
	}
	else if(map->entry.key > key){
		bstFind(map->left, key);  // BUGS!  see  #59
	}
	else if(map->entry.key < key){
		bstFind(map->right, key);
	}
	return NULL;
}


/*
* helper function.
* Finds the largest node in the tree.
*/
bstNode_t* findLargestNode(map_t map){
	if(mapIsEmpty(map)){
		return NULL;
	}
	if(mapIsEmpty(map->right)){
		return(map);
	}
	findLargestNode(map->right);  // BUG -- forgot return!!
}
 
    
/*
 * removes the (key, value) pair from the Map, no effect if !HasKey(key)
 * POST: HasKey(key) == false
 */
void mapRemove(map_t* map, keytype key){ //differnt type names between keytype and char* key....
	if(!mapHasKey(*map, key)){
		return;
	}
	map_t cur = findInsertionPoint(*map,key); //used to be mapFind(map, key);
	bstNode_t* parent = findParent(*map, key);
	if(cur->left == NULL && cur->right == NULL){ // ----- CASE 1: Node to be deleted is a leaf node ----
		if(parent->left = cur){
			parent->left = NULL;
		}
		else{
			parent->right = NULL;
		}
		free(cur);
		return;
	}
	else if(cur->left == NULL || cur->right == NULL){ // ----- CASE 2: Node to be deleted has one child ----
		if(cur->left != NULL){
			parent->left = cur->left;
		}
		else{
			parent->right = cur->right;
		}
		free(cur);
		return;
	}	
	else if (cur->left != NULL && cur->right != NULL){ // ----- CASE 3: Node to be deleted has two children
		bstNode_t* smallest = findSmallestNode(*map);
		cur->entry = smallest->entry;
		entryDelete(&map, smallest->entry.key);
		return;
	}
}//might what to make 3 different functions for the 3 cases, looks convaluted

/*
 * Helper function for finding a key in tree
 */
bstNode_t* bstFind(BinaryTree t, keytype key){
	if(t->entry.key == key)
		return (t);
	if(t->entry.key > key)
		return bstFind(t->left,key);
	if(t->entry.key < key)
		return bstFind(t->right,key);
		
}
/*
* PRE: HasKey(key)
* returns the value associated with the given key
*/
int mapGet(map_t map, keytype key){
	assert(mapHasKey(map,key));
	
	return bstFind(map,key)->entry.value;
}


/*
* returns true iff the Map contains the given key
*/
bool mapHasKey(map_t map, keytype key){
	if(mapGet(map, key) != -1){
		return true;
	}
	return false;
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
	int i;
	for(i=0; i<size; i++){
		keys[i] = entries[i]->key;
	}
	free(entries);

	return keys;
}


/*
* helper function.
* returns tree if the tree is empty.
*/
bool mapIsEmpty(map_t tree)
{
	return tree == NULL;
}
 
 
 /*
* helper function.
* Finds the appropirate node to insert the given key in the tree.
*/
bstNode_t* findInsertionPoint(map_t map, keytype key){ 
	// needs work -- this algorithm needs to return a pointer to an insertion point, not just NULL!
	//    have a look at the code we wrote for the BST in lab9.
	if(mapIsEmpty(map)){
		return NULL;
	}
	else if(map->entry.key == key){
		return map;
	}
	else if(map->entry.key > key){
		findInsertionPoint(map->left, key);  // BUG: missing return
	}
	else if(map->entry.key < key){
		findInsertionPoint(map->right, key);
	}
	return NULL;
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
void traverseInOrder(map_t map, entry_t* entries[], int* index){
	if(map != NULL){  
		traverseInOrder(map->left, entries, index);
		entries[*index] = &(map->entry); // a pointer to the entry, not a copy!
		(*index)++;
		traverseInOrder(map->right, entries, index);
	}									
}


/*
* helper function.
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