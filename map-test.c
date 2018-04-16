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
#include <string.h>
#include <assert.h>
#ifdef HASHMAP
#include "hashmap.h"
#else
#include "treemap.h"
#endif
#include "map.h"

typedef struct mapEntry {
    char* key;
    int value;
} E_t;

const E_t TEST_DATA[] = {
    {"d", 1}, {"b", 2}, {"a", 3}, {"c", 4}, 
    {"g", 5}, {"f", 6}, {"e", 7}, {"h", 8}
};
int NUM_TESTS = 8;

int main ()
{
    //MAP CREATION
    map_t map = mapCreate();
    assert(mapSize(map)==0);
    printf("Testing...\n");

    //INSERT
    int i;
    for (i=0; i<NUM_TESTS; i++)
        mapInsert(&map,TEST_DATA[i].key, TEST_DATA[i].value);
    printf("mapInsert works\n");
    int size = NUM_TESTS;
    
    //SIZE
    printf("The map contains %d keypairs\n", mapSize(map));
    assert(mapSize(map) == size);

    //HASKEY?
    assert(mapHasKey(map,"d"));
    assert(mapHasKey(map,"a"));
    assert(mapHasKey(map,"e"));
    assert(mapHasKey(map,"h"));
    printf("mapHasKey works\n");
    
    //GET
    for (i=0; i<NUM_TESTS; i++)
        assert(mapGet(map,TEST_DATA[i].key) == TEST_DATA[i].value);
    printf("mapGet works\n");

    //MAPKEYSET
    keytype* keySet = mapKeySet(map);
    for(i=0; i<NUM_TESTS; i++) {
        printf("i %d, key %s\n", i, keySet[i]);  fflush(stdout);
        assert(mapHasKey(map, keySet[i]));
    }
    free(keySet);
    printf("mapKeySet works\n");
    
    //REMOVE
    mapPrint(map);
    printf("\n Removing nodes a, f, and e: \n");
    mapRemove(&map,"a");
    size--;
    assert(!mapHasKey(map, "a"));
    
    mapRemove(&map,"f");
    size--;
    assert(!mapHasKey(map,"f"));

    mapRemove(&map,"e");
    size--;
    assert(!mapHasKey(map,"e"));
    assert(mapSize(map) == size);
    mapPrint(map);    

    //DELETE MAP
    mapClear(&map);
    assert(mapSize(map)==0);

    // DEEP COPY OF DATA
    printf("\n Testing for key deep copy and deep comparison: \n");
    char key[10];
    int value = 1;
    strncpy(key, "one", 9);
    mapInsert(&map, key, value);
    strncpy(key, "two", 9);
    value = 2;
    mapInsert(&map, key, value);
    strncpy(key, "three", 9);
    value = 3;
    mapInsert(&map, key, value);
    strncpy(key, "four", 9);
    value = 4;
    mapInsert(&map, key, value);
    assert(mapGet(map, "one") == 1);
    assert(mapGet(map, "two") == 2);
    assert(mapGet(map, "three") == 3);
    assert(mapGet(map, "four") == 4);
    
    mapClear(&map);    
} 