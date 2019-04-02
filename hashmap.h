/*
* Hashmap ADT- public API for hashmap implementation
* Author: Cap Comp220 Spring 2019
* Date: April 1st,2019
*
*/

/*
 * POST: Get(key) == value()
 * Sets the value for key if HasKey(key), otherwise inserts a new value in Map
 */
 void Insert(char* key, int value);
 
/*
 * POST: HasKey(key) == false
 * Removes the (key, value) pair from the Map, no effect if !HasKey(key)
 */
void Remove(char* key);

/* 
 * PRE: HasKey(key)
 * Returns the value associated with the given key
 */
int Get(char* key);

/* 
 * Returns true if the Map contains the given key
 */
bool HasKey(char* key);

/*
 * Returns the number of (key, value) pairs in the Map
 */
int Size(void);

/*
 * POST: Size() == 0
 * Removes all items from the Map
 */
void Clear(void);

/*
 * Returns a dynamic array containing all the Map Keys (in any sequence)
 * Returned array must be freed by client
 */
char** KeySet(void);

