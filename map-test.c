/*
 *  Comp220 - Test Driver which will work for EITHER treemap and hashmap
 *  
 *
 *  Author: Robert Bell, Ben Hynes
 *  Date:  April
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "map.h"


int main ()
{
    //MAP CREATION
    map_t map = mapCreate();
    assert(mapIsEmpty(map));
    
    entry_t entryA = {"a",1};
    entry_t entryB = {"b",2};
    entry_t entryC = {"c",3};
    entry_t entryD = {"d",4};

    //INSERT
    mapInsert(map,entryA);
    mapInsert(map,entryB);
    mapInsert(map,entryC);
    mapInsert(map,entryD);
    
    assert(mapSize(map) == 4);
    
    assert(mapGet(map,"a") == 1);
    assert(mapGet(map,"b") == 2);
    assert(mapGet(map,"c") == 3);
    assert(mapGet(map,"d") == 4);

    assert(mapHasKey(map,"a"));
    assert(mapHasKey(map,"b"));
    assert(mapHasKey(map,"c"));
    assert(mapHasKey(map,"d"));




 
    //DELETE MAP
    mapClear(*map);
    assert(mapIsEmpty(map));
}