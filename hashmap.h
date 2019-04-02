/*
* Hashmap ADT- public API for hashmap implementation
* Author: Louis Chuang
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
