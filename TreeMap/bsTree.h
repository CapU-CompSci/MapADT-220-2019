/*
 *
 * COMP 220 Project 4: Private API for bsTree ADT
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

struct bsTree_s {
    btNode* root;
};
typedef struct bsTree_s bsTree;

