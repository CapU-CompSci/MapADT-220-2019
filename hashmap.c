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

long Hmapfunction( keytype Key);
int mapindex(keytype Key);
keytype deepCopy(keytype key);
bool keysEqual(keytype key1,keytype key2);

/*
 * Authors: Braeden Norman, Artur Shadnik
 * Credit: Hashing algortihm by Dan Bernstein, via http://www.cse.yorku.ca/~oz/hash.html
 * Last Changed: 2018/04/06
 */
long Hmapfunction( keytype Key)
{
    unsigned long hash = 5381;
    int c;
    
    while( c = *Key++) {
        hash = (( hash<<5 ) + hash) + c;
    }
    return hash;
}
//Please review and test


//Author: Greagorey Markerian

int mapindex(keytype Key)
{
    long hash = Hmapfunction(Key);
    int index = hash%ARRAY_SIZE;
    return abs(index);  //TEMPORARY FIX: returns abs(index) to prevent accessing
                        //                  negative indices of an array
}
//Please Review and test



/*
 * Author: Greagorey Markerian
 * Edited by: Reece Whitehead
 * Needs to be reviewed and tested
 */
void mapInsert(map_t* mapref, keytype key, valuetype value)
{
    map_t map = *mapref;
    int index = mapindex(key);
    int counter = 0;
    
    keytype KEY = deepCopy(key);
    
    while(map->hashtable[index][counter].key!=NULL && !keysEqual(map->hashtable[index][counter].key, KEY)) {
    
        if(counter >= COL_SIZE)
        {
            printf("Overflow");
            assert(counter < COL_SIZE);
        }
        else
        {
            counter++;
        }
     
        
    }   
    entry_t entry = {KEY, value};
    map->hashtable[index][counter] = entry;
 
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
    assert(mapHasKey(map, key));  
    int index = mapindex(key);
    int counter = 0;

    while(keysEqual(map->hashtable[index][counter].key, key)==0) {
        counter++;
    }
    return map->hashtable[index][counter].value;
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
    int counter =0;
    int index = mapindex(key);
    keytype KEY = deepCopy(key);
   
    while(map->hashtable[index][counter].key!=NULL) { // BUG: just loop over all bins.
        if(keysEqual(map->hashtable[index][counter].key, KEY)) { //UPDATE: arent these correct since we search only where the index is -Greg
            return true;                                    //If there are more than one key, it will still give the same index.
        }
        counter++;
    }
    
    return false;
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
        for(c=0; map->hashtable[i][c].key!=NULL; c++) {
            size++;
        }
    }
    // BUG:  no return statement!
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
 * Last edited: 4/10/2018
 *
 * Prints a text representation of the hash table for debugging purposes
 */
void mapPrint(map_t map){
    int i, c;
    printf("===MAP: HASH TABLE===\n");
    for( i = 0; i < ARRAY_SIZE; i++ ){
        for( c = 0; c < COL_SIZE; c++ ){
            if( map->hashtable[i][c].key != NULL ){
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
keytype* mapKeySet(map_t * map){
    map_t mapCur = * map;
    int size = mapSize(mapCur);
    int i, c;
    int arrIndex = 0;
    keytype* keys = calloc(size, sizeof(keytype));
    for( i=0; i < ARRAY_SIZE; i++ ){
        for( c=0; c < COL_SIZE; c++ ){
            if ( mapCur->hashtable[i][c].key != NULL ){
                keys[arrIndex] = mapCur->hashtable[i][c].key;
                arrIndex++;
            }
        }
    }
    return keys;
}