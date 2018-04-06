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
Node_t* findLargestNode(map_t map);
bstNode_t* findInsertionPoint(map_t map, keytype value);
void traverseInOrder(map_t map, keytype* array);
bstNode_t* findParent(map_t map, char* key);

/*
 * Constructor - return a new, empty map
 * POST:  mapSize(map) == 0
 */
 bstNode_t nodeCreate(int value, keytype key){
	bstNode_t root;
	root.entry.value = 0;
	root.entry->key = NULL;
	root.start->left = NULL;
	map.start->right = NULL;
	return map;
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
void mapInsert(map_t* map, char* key, int value){
	map_t curr = findInsertionPoint(map,key);
	if(mapHasKey(value)){
		curr->entry->value = value;
	}
	else{
		curr = nodeCreate(value,key);	
	}
}

bstNode_t* findParent(map_t map, char* key)
{
	map_t parent;
		if(mapIsEmpty(map)){
		return NULL;
	}
	else if(map->left->entry.key == k || map->right->entry.key == k){
		return(map);
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
* Finds the largest node in the tree.
*/
bstNode_t* findLargestNode(map_t map){
	if mapIsEmpty(map){
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
 //CHARMAINE IS WORKING ON THIS!
void entryDelete(map_t* map, keytype key); //differnt type names between keytype and char* key....
{
	map_t cur;
	if(mapHasKey(&map, key)){
		if( key < map->key)
			mapDelete(map->left, key);
		else if(key> map->key)
			mapDelete( map->right, key);
		else if(map->left && map->right){
			cur = find
			findLargestNode(map);
			cur
			
		}
		

}


/*
* PRE: HasKey(key)
* returns the value associated with the given key
*/
keytype mapGet(map_t map, keytype key){
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
	if( mapGet(map, key) != -1){
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
		mamClear(&curr->right);
		free(curr);
	}
	*map = NULL;
}


/*
* returns a dynamic array containing all the Map Keys (in any sequence)
* it is the caller's responsibility to free the returned array.
*/
keytype* keySet(map_t* map){
	keytype* array;
	int i =0;
	array = malloc(sizeof(keytype)*mapSize(map)+1);
	traverseInOrder(map, array);
	array[mapSize(map)+1] = NULL;
	return array;
}


/*********************
 * Helper Functions
 *********************/
 
 bool bstIsEmpty(map_t tree){
 	return tree == NULL;
 }
 

bstNode_t* findInsertionPoint(map_t* map, keytype key){
	if(mapIsEmpty(map)){
		return NULL;
	}
	else if(map->entry.key == k){
		return *map;
	}
	else if(map->entry.key > k){
		bstFind(map->left, k);
	}
	else if(map->entry.key < k){
		bstFind(map->right, k);
	}
	return NULL;
}
 
 void traverseInOrder(map_t map, keytype* array){
	if(map != NULL){
		traverseInOrder(map->left);
		array[i] = map->entry->key[i];
		traverseInOrder(map->right);
	}
}

 