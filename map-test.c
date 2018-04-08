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
#include <map.h>

int main ()
{
    //MAP CREATION
    map_t map = mapCreate();
    assert(mapIsEmpty(map));
    
    //INSERT
    //mapInsert(&map,entry); //what is entry_type and where is it created?
    
    //GET
    //mapGet(map, keytype key); //need to find out how the entry and keys work
    
    //HASKEY?
    //assert(mapHasKey(map, key)); //again finding out how keys work
    
    //SIZE
    printf("The map contains %d keypairs", mapSize(map));
 
    //DELETE MAP
    mapClear(*map);
    assert(mapIsEmpty(map));
}