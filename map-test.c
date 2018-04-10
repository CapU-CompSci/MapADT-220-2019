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
    
    //keytype* testMap = mapKeySet(&map);
    //assert(*testMap[1] == 2);
    keytype* set = mapKeySet(&map);
    map_t map2 = mapCreate();
    
    
    mapInsert(&map2,set[0], 1);
    mapInsert(&map2,set[1], 2);
    mapInsert(&map2,set[2], 3);
    mapInsert(&map2,set[3], 4);
    assert(mapHasKey(map2,"a"));
    assert(mapHasKey(map2,"b"));
    assert(mapHasKey(map2,"c"));
    assert(mapHasKey(map2,"d"));
    printf("mapKeySet works\n");
    
    //REMOVE
    /*
    mapRemove(&map,"b");
    assert(!mapHasKey(map,"b"));
    assert(mapSize(map) == 3);
    printf("mapRemove works\n");
    */
    //DELETE MAP
    mapClear(&map);
    assert(mapSize(map)==0);
    
} 