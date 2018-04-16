/*
 *  Public API for simple Binary Search Tree that stores a frequency histogram
 *    - Entries are count-string pairs, stored in descending count order
 */
#include <stdbool.h>
typedef int KeyType;
typedef char* ValueType;

struct Entry_s {
	KeyType key;
	ValueType value;
};
typedef struct Entry_s Entry_t;

struct ftNode{
	Entry_t entry;
	struct ftNode* left;
	struct ftNode* right;
};
typedef struct ftNode ftNode_t;

typedef ftNode_t* FreqTree_t;

/*
 * Create and return an empty Frequncy Tree
 */
FreqTree_t ftCreate();

/*
 * Empty and free all dynamic memory associated with the tree
 */
void ftDestroy(FreqTree_t* tree);

/*
 * Print a graphical representation of the frequencies stdout
 * Only the top n frequent entries are printed, if n > 0
 */
void ftPrint(const FreqTree_t tree, int n);

/* 
 *  Return the number of nodes in the given tree, including the root node
 */
int ftSize(const FreqTree_t tree);

/*
 * Return true if ftSize(tree) == 0, false otherwise.
 */
bool ftIsEmpty(const FreqTree_t tree);

/*
 * Insert the given key into the given tree
 */
void ftInsert(FreqTree_t* tree, KeyType key, ValueType value);
