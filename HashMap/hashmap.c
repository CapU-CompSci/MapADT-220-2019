/*
*  COMP 220 Project 4: Hashmap ADT implemation 
*  Author: Cap Comp220 Spring 2019
*  Date: April 1, 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"
#include "hashmap.h"


Hashmap_t hashConstructor(int cap)
{
    Hashmap_t new;
    new.map = (linkedList*)calloc(cap, sizeof(linkedList));
    new.capacity = cap;
    return new;
}

/*
 * calculate hash for given key
 */
unsigned long Hash(char* key){                 //djb2 algorithm first created by Dan Bernstein
    unsigned long hash = 5381;
    int c;
    while (c = *key++){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

/*
 *  calculate the index of an element given it's hash
 */
int getIndex(char* key, int arraySize){
    unsigned long hash = Hash(key);
    int index = hash % arraySize;
    return index;    
}

void Clear(Hashmap_t hashmap)
{
    int i;
    for(i=0; i<hashmap.capacity; i++)
    {
        llDelete(&hashmap.map[i]);
    }
}

void hashDestructor(Hashmap_t hashmap)
{
    Clear(hashmap);
    hashmap.map = NULL;
    hashmap.capacity = 0;
}

bool HasKey(Hashmap_t hashmap, char* key)
{
    int index = getIndex(key, hashmap.capacity);
    linkedList list = hashmap.map[index]; 
    return findKey(&list, key);
}

int Get(char* key, Hashmap_t hashmap)
{
	int index = getIndex(key, hashmap.capacity); 
	Node_t* node = find(&hashmap.map[index], key);
	return node->frequency; 
}

int size(Hashmap_t hashmap)
{
	int count; 
	int num = 0;

	for( count = 0; count < hashmap.capacity; count++)
	{
		if(&hashmap.map[count] != 0)
		{
			num = num + hashmap.map[count].capacity;
		}
	}
	return num;
}	

char* retrieveKey(char* inFile){
    FILE *fp;
    char* key;
    fp = fopen(inFile, "r");
    fscanf(fp, "%127s", &key);
    return key;
}