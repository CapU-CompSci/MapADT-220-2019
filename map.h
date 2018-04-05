/*
 *  Comp220 - Map.h
 *    Public API for a Map ADT
 *
 *  Author: J. Fall, Tim Wriglesworth
 *  Date: Mar. 2017 // edited in April
 */
 
 
 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//DATA TYPES IN THE MAP

/*******************
 * PRIVATE TYPE DECLARATION
 ********************/

typedef char* keytype;
typedef struct key_s key_t;


struct node_s{
	char* key;
	node_t* left; //needs to be named
	node_t* right; // needs to be named
};

typedef struct map_s map_t;
struct map_s{
	node_t* start;
}



/*********************
 *  PUBLIC INTERFACE
 *********************/

/*
 * Constructor - return a new, empty map
 * POST:  mapSize(map) == 0
 */
map_t mapCreate();

/*
* POST: Get(key) == value
* sets the value for key if HasKey(key), otherwise inserts a new value in Map
*/
void mapInsert(keytype key, int value);
 
    
/*
 * removes the (key, value) pair from the Map, no effect if !HasKey(key)
 * POST: HasKey(key) == false
 */
void mapDelete(keytype key);




/*
* removes the (key, value) pair from the Map, no effect if !HasKey(key)
* POST: HasKey(key) == false
*/

//void mapDelete(map_t* map, keytype key); //differnt type names between keytype and char* key....



/*
* PRE: HasKey(key)
* returns the value associated with the given key
*/
void mapGet(map_t map, keytype key);  



/*
* returns true iff the Map contains the given key
*/
bool mapHasKey(map_t map, keytype key);


/*
 *returns the number of (key, value) pairs in the Map
 */
int mapSize(map_t map);

/*
* POST: Size() == 0
* removes all items from the Map (without creating memory leaks!)
*/
void mapClear(map_t * map);


/*
* returns a dynamic array containing all the Map Keys (in any sequence)
* it is the caller's responsibility to free the returned array.
*/
keytype keySet(map);





