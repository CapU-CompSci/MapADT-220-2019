/*
 *  Comp220 - Map.h
 *    Public API for a Map ADT
 *
 *  Author: J. Fall
 *  Date: Mar. 2017
 */
 
 /*
  * Sets the value for key if HasKey(key), otherwise inserts a new value in Map
  *  POST: Get(key) == value
  */
void mapInsert(char* key, int value);
    
/*
 * removes the (key, value) pair from the Map, no effect if !HasKey(key)
 * POST: HasKey(key) == false
 */
void mapDelete(char* key);

    
    

