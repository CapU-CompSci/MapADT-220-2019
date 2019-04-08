/*
 *
 * COMP 220 Project 4: Public API for TreeMap ADT
 * Author: Cap Comp220 Spring 2019
 * Date: April 1, 2019
 *
 */

struct btNode_s {

    char* key;
	int count;
	struct btNode_s* right;
	struct btNode_s* left;
};
typedef struct btNode_s btNode;


/*
 *POST: Get(key) == value
 *Sets the value for key if HasKey(key), otherwise inserts a new value in Map
 */
void Insert(char* key,int value);


/*
 *POST: HasKey(key) == false
 *removes the (key, value) pair from the Map, no effect if !HasKey(key)
 */
void Remove(char* key);


/*
 *PRE: HasKey(key)
 *Returns the value associated with the given key
 */
int Get(char* key);
