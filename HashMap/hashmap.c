/*
*  COMP 220 Project 4: Hashmap ADT implemation 
*  Author: Cap Comp220 Spring 2019
*  Date: April 1, 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashmap.h"
#include "linkedList.h"

Hashmap_t hashConstructor(int cap)
{
    Hashmap_t new;
    new.map = (linkedList*)calloc(cap, sizeof(linkedList)):
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
        llDelete(hashmap.map[i]);
    }
}

void hashDestructor(Hashmap_t hashmap)
{
    Clear(Hashmap_t hashmap)
    hashmap.map == NULL;
    hashmap.capacity == 0;
}

bool HasKey(Hashmap_t hashmap, char* key)
{
   return findKey(hashmap.map[getIndex(key, hashmap.capacity)]);
}