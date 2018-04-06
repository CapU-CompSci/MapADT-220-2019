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
    
 
    //DELETE MAP
    mapClear(*map);
    assert(mapIsEmpty(map));
}