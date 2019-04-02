/*
* Hashmap ADT- public API for hashmap implementation
* Author: Cap Comp220 Spring 2019
* Date: April 1st,2019
*
*/

/*
 * POST: Get(key) == value()
 * sets the value for key if HasKey(key), otherwise inserts a new value in Map
 */
 void Insert(char* key, int value);
 
/*
 * POST: HasKey(key) == false
 * removes the (key, value) pair from the Map, no effect if !HasKey(key)
 */
void Remove(char* key);

/* 
 * PRE: HasKey(key)
 * returns the value associated with the given key
 */
int Get(char* key);

/* 
 * returns true iff the Map contains the given key
 */
bool HasKey(char* key);

/*
 * returns the number of (key, value) pairs in the Map
 */
int Size(void);

/*
 * POST: Size() == 0
 * removes all items from the Map (without creating memory leaks!)
 */
void Clear(void);

/*
 * returns a dynamic array containing all the Map Keys (in any sequence)
 * it is the caller's responsibility to free the returned array.
 */
char** KeySet(void);
