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


struct entry{
	char* key;
	int value;
};
typedef struct entry entry_t;


struct bstNode{
	entry_t entry;
	struct bstNode* left;
	struct bstNode* right;
};
typedef struct bstNode bstNode_t;

typedef bstNode_t* BinaryTree;