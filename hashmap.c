/* This will be the .c file corresponding with the hashmap.h file 
 *
 *   Authors: Reece Whitehead, Artur Shadnik, Greagorey Markerian, Joseph Fall 
 *   Date: April 5, 2018
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "hashmap.h"
#include "map.h"

#define COL_SIZE 20
#define ARRAY_SIZE 100

unsigned long Hmapfunction( keytype Key);
int mapindex(keytype Key);
entry_t* htGetBin(map_t map, keytype key);
bool htBinIsEmpty(entry_t* bin);
keytype deepCopy(keytype key);
bool keysEqual(keytype key1,keytype key2);

/*
 * Authors: Braeden Norman, Artur Shadnik
 * Credit: Hashing algortihm by Dan Bernstein, via http://www.cse.yorku.ca/~oz/hash.html
 * Last Changed: 2018/04/06
 */
unsigned long Hmapfunction( keytype Key)
{
    unsigned long hash = 5381;
    int c;
    
    while( c = *Key++) {
        hash = (( hash<<5 ) + hash) + c;
    }
    return hash;
}


//Author: Greagorey Markerian
// Return the index in the hash table where the given key belongs.
int mapindex(keytype Key)
{
    unsigned long hash = Hmapfunction(Key);
    int index = hash%ARRAY_SIZE;
    return abs(index);  // abs is probably redundant now -- fixed by using unsigned.
}

// Return true iff the given hash table bin is empty
bool htBinIsEmpty(entry_t* bin) 
{
    return bin->key == NULL;
} 

// Return a pointer to the "bin" in the hashtable where the key is found, 
//   or a pointer to the empty "bin" where the key should have been found,
//   or NULL if the hash table row would overflow if that key were inserted.
entry_t* htGetBin(map_t map, keytype key) 
{
    int index = mapindex(key);
    int counter = 0;

    for (counter=0; counter < COL_SIZE; counter++) {
        if (htBinIsEmpty(&(map->hashtable[index][counter])) ||
            keysEqual(map->hashtable[index][counter].key, key) )
            return &(map->hashtable[index][counter]);
    }
    return NULL; // overflow -- key not found, no empty bins to put it in.
}


/*
 * Author: Greagorey Markerian
 * Edited by: Reece Whitehead
 * Needs to be reviewed and tested
 */
void mapInsert(map_t* mapref, keytype key, valuetype value)
{
    map_t map = *mapref;
    entry_t* entry = htGetBin(map, key);
    if (entry == NULL) {
        printf("Hash Map Overflow for key %s \n", key);
        assert(entry != NULL);
    }
    entry->key = deepCopy(key);
    entry->value = value;
}

/*
 * Author:Reece Whitehead
 * Edit:
 * last changed: 4/5/2018
 */
map_t mapCreate()
{
    map_t map;
    map = calloc(1,sizeof(Hmap)); // assumes all hashtable values set to NULL
    return map;
}
    
    
    
    
    
    
/*
 * Author:Reece Whitehead
 * Edit:
 * last changed: 4/9/2018
 */
int mapGet(map_t map, keytype key)
{
    entry_t* entry = htGetBin(map, key);
    assert(entry != NULL);  
    return entry->value;
}









/*
 * Author: Artur Shadnik
 * Edited by: Reece Whitehead
 * Last Changed: 2018/04/05
 * Needs to be reviewed and tested
 */
 
void mapRemove(map_t* mapref, keytype key)
{
    map_t map = *mapref;
    if (!mapHasKey(map, key)) {
        return;
    }
    else {
        int c;
        int i = mapindex(key);
        int t;
       
        
       
        while(map->hashtable[i][c].key!=NULL) {  
            if(keysEqual(map->hashtable[i][c].key, key)) {   
                
                //map->hashtable[i][c].key = '\0';
                //map->hashtable[i][c].value = 0;
                for(t=c;t<COL_SIZE-1;t++){
                    
                    map->hashtable[i][t] = map->hashtable[i][t+1]; //I think this should work for deleting an entry at a found index by overwriting the data with whatever is left of it
                    //I do this to keep the overflow bin compressed to the left side of the array
                }
            }
        }
    }
}





/*
 * Author: Greagorey Markerian
 * Last Changed: 2018/04/05
 * Needs to be reviewed and tested
 */
bool mapHasKey(map_t map, keytype key)
{
    entry_t* entry = htGetBin(map, key);
    return entry != NULL && !htBinIsEmpty(entry);
}

/*
 * Author: Artur Shadnik
 * Edited by: Reece Whitehead
 * Last Changed: 2018/04/05
 * Needs to be reviewed and tested
 */
void mapClear(map_t* mapref)
{
    map_t map = *mapref;
    int i, c;
    for(i = 0; i < ARRAY_SIZE-1; i++) {
        for(c = 0; c < COL_SIZE-1; c++) {
            
            map->hashtable[i][c].key = '\0';
            map->hashtable[i][c].value =0;

        }
    }
}


/*
 * Author: Braeden Norman
 * Last Changed: 2018/04/06
 * Needs to be reviewed and tested
 */
int mapSize(map_t map)
{
    int i, c, size = 0;
    for(i=0; i<ARRAY_SIZE-1; i++) {
        for(c=0; !htBinIsEmpty(&map->hashtable[i][c]); c++) {
            size++;
        }
    }
    return size;
}




  /*
  *Author: Reece Whitehead + Greagorey+ Joseph Fall
  *
  *Last edited: 4/10/2018
  */
keytype deepCopy(keytype key){
    keytype newKey = calloc(strlen(key), sizeof(char));
    strcpy(newKey, key);
    return newKey;
    
    
}

  /*
  *Author: Reece Whitehead + Greagorey+ Joseph Fall
  *
  *Last edited: 4/10/2018
  */

bool keysEqual(keytype key1,keytype key2){
    return (strcmp(key1, key2)==0);
}


/*
 * Author: Ricky Cheung
 * Last edited: 4/12/2018
 * Small Edit by: Reece Whitehead
 * Prints a text representation of the hash table for debugging purposes
 */
void mapPrint(map_t map){
    int i, c;
    printf("===MAP: HASH TABLE===\n");
    for( i = 0; i < ARRAY_SIZE-1; i++ ){
        for( c = 0; c < COL_SIZE-1; c++ ){
            if( !htBinIsEmpty(&map->hashtable[i][c]) ){
                printf("[bucket:%d; key:%s; value:%d]\n", i, map->hashtable[i][c].key, map->hashtable[i][c].value);
            }
        }
    }
    printf("=====================\n");
}

/*
 * Author: Ricky Cheung
 * Last edited: 4/11/2018
 *
 * returns a dynamic array containing all the Map Keys (in any sequence)
 * it is the caller's responsibility to free the returned array.
 */
keytype* mapKeySet(map_t map){
    int size = mapSize(map);
    int i, c;
    int arrIndex = 0;
    keytype* keys = calloc(size, sizeof(keytype));
    for( i=0; i < ARRAY_SIZE; i++ ){
        for( c=0; c < COL_SIZE; c++ ){
            if ( !htBinIsEmpty(&map->hashtable[i][c]) ){
                keys[arrIndex] = map->hashtable[i][c].key;
                arrIndex++;
            }
        }
    }
    return keys;
}