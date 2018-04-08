/*
 *  Comp220 - Map.h
 *    Public API for a Map ADT
 *
 *  Author: J. Fall, Tim Wriglesworth Robert Bell
 *  Date: Apr. 2017
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



/*********************
 *  PUBLIC INTERFACE
 *********************/

/*
 * Constructor - return a new, empty map
 * POST:  mapSize(map) == 0
 */
map_t mapCreate();

/*
* POST: mapGet(key) == value
* sets the value for key if mapHasKey(key), otherwise inserts a new value in Map
*/
void mapInsert( map_t* map, keytype key, valuetype value);
 
    
/*
* removes the (key, value) pair from the Map, no effect if !mapHasKey(key)
* POST: mapHasKey(key) == false
*/
void entryDelete(map_t* map, keytype key);


/*
* PRE: mapHasKey(key)
* returns the value associated with the given key
*/
int mapGet(map_t map, keytype key);


/*
* returns true iff the Map contains the given key
*/
bool mapHasKey(map_t map, keytype key);


/*
 * Returns the number of (key, value) pairs in the Map
 */
int mapSize(map_t map);

/*
* POST: mapSize() == 0
* removes all items from the Map (without creating memory leaks!)
*/
void mapClear(map_t * map);


/*
* returns a dynamic array containing all the Map Keys (in any sequence)
* it is the caller's responsibility to free the returned array.
*/
keytype mapKeySet(map_t * map);
