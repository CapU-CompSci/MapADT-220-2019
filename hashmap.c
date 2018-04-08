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

#include "hashmap.h"
#include "map.h"

#define COL_SIZE 20
#define ARRAY_SIZE 100

long Hmapfunction( keytype Key);
int mapindex(keytype Key);

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
    return index;
}
//Please Review and test



/*
 * Author: Greagorey Markerian
 * Needs to be reviewed and tested
 */
void mapInsert(map_t* mapref, keytype key, valuetype value)
{
    map_t map = *mapref;
    int index = mapindex(key);
    int counter = 0;
    
    while(map->hashtable[index][counter].key!=NULL) {
        counter++;
        assert(counter < COL_SIZE); // TODO: better error handling required for column overflow.
    }
    // TODO: CRITICAL - an Entry constructor to allocate dynamic memory for deep-copy of key!
    map->hashtable[index][counter] = {key, value};
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
 * last changed: 4/5/2018
 */
int mapGet(map_t map, keytype key)
{
    if(mapHasKey(map, key)) {  // PRE-condition -- just assert it.
        int index = mapindex(key);
        int counter = 0;

        while(map->hashtable[index][counter].key != key) {
            counter++;
        }
        return map->hashtable[index][counter].value;
    }

    // TODO: simply assert PRE-condition at top of function instead.
    printf("ERROR: key does not exist within map");
    return 0;
}

/*
 * Author: Artur Shadnik
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
        int c =0;
        int i = mapindex(key);
   
        while(map->hashtable[i][c].key!=NULL) {  // BUG: just loop over all bins
            if(map->hashtable[i][c].key == key) {
                ; /*  This code is just plain wrong! The map struct has one member: a hashtable.
                free(map->key);
                free(map->value);
                map_t = {NULL, NULL}
                */
            }
            c++;
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
   
    while(map->hashtable[index][counter].key!=NULL) { // BUG: just loop over all bins.
        if(map->hashtable[index][counter].key == key) {
            return true;
        }
        counter++;
    }
    
    return false;
}

/*
 * Author: Artur Shadnik
 * Last Changed: 2018/04/05
 * Needs to be reviewed and tested
 */
void mapClear(map_t* mapref)
{
    map_t map = *mapref;
    int i, c;
    for(i = 0; i < ARRAY_SIZE; i++) {
        for(c = 0; c < COL_SIZE; c++) {
            ; /*  BUG: This code is just plain wrong! The map struct has one member: a hashtable.
            free(map->key);
            free(map->value);
            map_t = {NULL, NULL}
            */
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
    for(i=0; i<ARRAY_SIZE; i++) {
        for(c=0; map->hashtable[i][c].key!=NULL; c++) {
            size++;
        }
    }
    // BUG:  no return statement!
}
