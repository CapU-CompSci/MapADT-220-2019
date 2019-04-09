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

/*
 * Creates new node with given key
 * POST: Count == 1 , btNode.key == key, btNodeRight/Left == NULL
 */
btNode* btNodecreate(char* key);

/*
 *Deletes given Node
 *POST: node_p == NULL
 */
void btNodeDestroy(btNode** node_p);



/*
 * Inserts data into the tree
 * does nothing if key is already present
 */
void bstInsert(bsTree* tree_p, char* key);

/*
 * finds a node in the tree given the key
 * returns a pointer to the node if found else NULL
 */
 
btNode* bstFindkey(btNode root, char* key);
/*
 * create a new empty tree
 * POST: Return Empty Tree
*/
bsTree bstCreate();

/*
 * destroy the whole tree
 *
*/
void bstDestroy(bsTree* tree);





