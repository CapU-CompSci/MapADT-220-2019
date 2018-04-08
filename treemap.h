/*
 * Struct Definitions of Binary Search Tree
 *
 * 
 *
 * Author: Charmaine Neufeld
 * Date: April 5, 2018
 */

 
#include <stdio.h>
#include <stdlib.h>

typedef char* keytype;
typedef int valuetype;

struct entry{
	keytype key;
	valuetype value;
};
typedef struct entry entry_t;


struct bstNode{
	entry_t entry;
	struct bstNode* left;
	struct bstNode* right;
};
typedef struct bstNode bstNode_t;

typedef bstNode_t* BinaryTree;

typedef BinaryTree map_t;