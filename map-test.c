/*
 *  Comp220  Test Driver which will work for EITHER treemap and hashmap
 *  
 *
 *  Author: Robert Bell, Ben Hynes, Keaton Armstrong
 *  Date:  April
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#ifdef HASHMAP
#include "hashmap.h"
#else
#include "treemap.h"
#endif
#include "map.h"


int main ()
{
    //MAP CREATION
    map_t map = mapCreate();
    assert(mapSize(map)==0);
    printf("Testing...\n");

    //INSERT
    mapInsert(&map,"a",1);
    mapInsert(&map,"b",2);
    mapInsert(&map,"c",3);
    mapInsert(&map,"d",4);
    printf("mapInsert works\n");

    //SIZE
    printf("The map contains %d keypairs\n", mapSize(map));
    assert(mapSize(map) == 4);
    
    //GET
    assert(mapGet(map,"a") == 1);
    assert(mapGet(map,"b") == 2);
    assert(mapGet(map,"c") == 3);
    assert(mapGet(map,"d") == 4);
    printf("mapGet works\n");
    
    //HASKEY?
    assert(mapHasKey(map,"a"));
    assert(mapHasKey(map,"b"));
    assert(mapHasKey(map,"c"));
    assert(mapHasKey(map,"d"));
    printf("mapHasKey works\n");

    //REMOVE
    //mapRemove(&map,"b");
    //assert(!mapHasKey(map,"a"));
    //assert(mapSize(map) == 3);
    
    //DELETE MAP
    mapClear(&map);
    assert(mapSize(map)==0);
    
} 