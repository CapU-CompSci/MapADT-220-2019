/*
 *  Comp220 - Test Driver which will work for EITHER treemap and hashmap
 *  
 *
 *  Author: Robert Bell, Ben Hynes, Keaton Armstrong
 *  Date:  April
 */
 /*Notes: Try making the file, the entry types and map type are undefined, 
 should this file include the other .h files? but then we have two places where entry and map
 are defiend.
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
    
    //INSERT
    mapInsert(map,"a", 1);
    mapInsert(map,"b",2);
    mapInsert(map,"c",3);
    mapInsert(map,"d",4);
    
    assert(mapSize(map) == 4);
    
    assert(mapGet(map,"a") == 1);
    assert(mapGet(map,"b") == 2);
    assert(mapGet(map,"c") == 3);
    assert(mapGet(map,"d") == 4);

    assert(mapHasKey(map,"a"));
    assert(mapHasKey(map,"b"));
    assert(mapHasKey(map,"c"));
    assert(mapHasKey(map,"d"));
    
    mapRemove(&map,"a");
    assert(!mapHasKey(map,"a"));
    assert(mapSize(map) == 3);

    //DELETE MAP
    mapClear(*map);
    assert(mapIsEmpty(map));
}