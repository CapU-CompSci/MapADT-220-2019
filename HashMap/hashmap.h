/*
* Hashmap ADT- public API for hashmap implementation
* Author: Cap Comp220 Spring 2019
* Date: April 1st,2019
*
*/

struct node_s{
	int data;
	struct node_s* next;
};
typedef struct node_s Node_t;

struct list_s{
	Node_t* head;
	Node_t* tail;
};
typedef struct list_s List_t;

struct hastable_s
{
    int key;
    List_t list;
}
typedef struct hastable_s Hashtable_t;

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

/*
 * Creates a hashtable and return it
 */
Hashtable_t hashContructor(int length);

/*
 * Destroys a hashtabe
 */
 void hashDestructor(hastable_t* hashtable_p);

