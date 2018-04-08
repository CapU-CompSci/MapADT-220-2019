/*
 * Comp220 - treemap.c
 * Implementation of treemap ADT
 *
 * Authors: Andre Wakkary, Karan Nedungadi, Levi Holmes, Joshua Yeh, Charmaine Neufeld
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
bool bstIsEmpty(map_t tree);
map_t findLargestNode(map_t map);
map_t findInsertionPoint(map_t map, keytype key);
void traverseInOrder(map_t map, keytype* array);
map_t findParent(map_t map, char* key);
map_t findSmallestNode(map_t);
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
	map_t curr = findInsertionPoint(*map,key);
	if(mapHasKey(*map,key)){
		curr->entry.value = value;
	}
	else{
		curr = nodeCreate(value,key);	
	}
}

map_t findParent(map_t map, char* key)
{
	map_t parent;
		if(mapIsEmpty(map)){
		return NULL;
	}
	else if(map->left->entry.key == key || map->right->entry.key == key){
		return(map);
	}
	else if(map->entry.key > key){
		bstFind(map->left, key);
	}
	else if(map->entry.key < key){
		bstFind(map->right, key);
	}
	return NULL;
}


/*
* Finds the largest node in the tree.
*/
map_t findLargestNode(map_t map){
	if(mapIsEmpty(map)){
		return NULL;
	}
	if(mapIsEmpty(map->right)){
		return(map);
	}
	findLargestNode(map->right);
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
	map_t parent = findParent(*map, key);
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
		map_t smallest = findSmallestNode(*map);
		cur->entry = smallest->entry;
		entryDelete(&map, smallest->entry.key);
		return;
	}
}


/*
* PRE: HasKey(key)
* returns the value associated with the given key
*/
int mapGet(map_t map, keytype key){
	if(mapIsEmpty(map)){
		return NULL;
	}
	else if(map->entry.key == k){
		return(map->entry.value);
	}
	else if(map->entry.key > k){
		bstFind(map->left, k);
	}
	else if(map->entry.key < k){
		bstFind(map->right, k);
	}
	return NULL;
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
	if(maptIsEmpty(map)){
		return 0;
	}
	return 1 + bstSize(map->left) + bstSize(map->right);
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
*/
keytype mapKeySet(map_t* map){
	keytype array;
	int i;
	array = malloc(sizeof(keytype)*mapSize(map)+1);
	int size = sizeof(mapSize);
	for(i=0; i<size-1; i++){
		array[i] = traverseInOrder(map);
	}

	array[mapSize(map)+1] = NULL;
	return array;
}


/*********************
 * Helper Functions
 *********************/
 
 bool bstIsEmpty(map_t tree){
 	return tree == NULL;
 }
 

map_t findInsertionPoint(map_t map, keytype key){
	if(mapIsEmpty(map)){
		return NULL;
	}
	else if(map->entry.key == key){
		return map;
	}
	else if(map->entry.key > key){
		findInsertionPoint(map->left, key);
	}
	else if(map->entry.key < key){
		findInsertionPoint(map->right, key);
	}
	return NULL;
}
 
 void traverseInOrder(map_t map){
	if(map != NULL){
		traverseInOrder(map->left);
		return key;
		traverseInOrder(map->right);	
	}										
}										
											
map_t findSmallestNode(map_t node){			//check
	if(mapIsEmpty(node)){
		return NULL;
	}
	if(mapIsEmpty(node->left)){
		return node;
	}
	findSmallestNode(node->left);
} 