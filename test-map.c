/*****************************
 * 
 *  Test (Ignore this)
 * 
 * ****************************/

#include <stdio.h>
#include <stdlib.h>
#include <treemap.h>
#include <map.h>

bstNode_t nodeCreate(int value, keytype key){
	bstNode_t map;
	map.entry.value = 0;
	map.entry->key = NULL;
	map.start->left = NULL;
	map.start->right = NULL;
	return map;
}


void mapInsert(map_t* map, char* key, int value){
	BinaryTree curr = findInsertionPoint(map,key);
	if(mapHasKey(value)){
		curr->entry->value = value;
	}
	else{
		curr = nodeCreate(value,key);	
	}
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

BinaryTree mapCreate(){
	BinaryTree map = NULL;
	return map;
}

keytype mapGet(map_t map, keytype key) {
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


bool mapHasKey(map_t map, keytype key){
	int val = mapGet(map, key);
	if( val != -1){
		return true;
	}
	return false;
}

int main(){
    BinaryTree map = mapCreate();
    mapInsert(&map,"e",10);
    mapInsert(&map,"e",20);
    assert(map->entry->value == 20);
}




