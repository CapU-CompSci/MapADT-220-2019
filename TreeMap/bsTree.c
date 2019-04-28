/*
 *
 * COMP 220 Project 4: Private Implementation for bsTree ADT
 * Author: Cap Comp220 Spring 2019
 * Date: April 1, 2019
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "bsTree.h"

/*
 * Creates new node with given key
 * POST: Count == 1 , btNode.key == key, btNodeRight/Left == NULL
 */
btNode* btNodecreate(char* key)
{
    btNode* newNode = malloc(sizeof(btNode));
    newNode->key = malloc(strlen(key)*sizeof(char)+1);
    strcpy(newNode->key, key);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


/*
 *Deletes given Node
 *POST: node_p == NULL
 */
void btNodeDestroy(btNode** node_p){
    btNode* node = *node_p;
    if(node!=NULL){
        btNodeDestroy(&node->left);
        btNodeDestroy(&node->right);
        free(node);
        *node_p = NULL;
    }
}



/*
 * Inserts data into the tree
 */
void bstInsert(bsTree* tree_p, char* key){
    btNode* target = bstFindkey(tree_p,key);        //if exist in tree, increment count
    if(target!=NULL){
        target->count++;
    }else{
    	if(*tree_p == NULL){
    		*tree_p = btNodecreate(key);
    	}
    	if(strcmp((*tree_p)->key, key) < 0){
    		bstInsert(&(*tree_p)->left, key);
    	}{
    	if(strcmp((*tree_p)->key, key) > 0)
    		bstInsert(&(*tree_p)->right, key);
    	}
    }
}

/*
 * finds a node in the tree given the key
 * returns a pointer to node if found, else return NULL
 */
btNode* bstFindkey(btNode* root, char* key) {
    /*
    *   If strcmp(str1,str2) returns a negative number, it means the 
    *   first string's ASCII is smaller and also is bigger if we consider
    *   a to be the biggest and z be the smallest letter, ex: first string
    *   is aaa and the second string is zzz (ASCII of a is less than z)
    *   So if the we are looking for aaa and the node's string is ccc, we go 
    *   to the right node.
    */
    if(root==NULL){             //empty tree
        return NULL;
    }else{
        if ( strcmp(root -> key, key) == 0 ){       //found
            return root;
        }
        
        if (strcmp(root -> key, key) < 0) {
            return bstFindkey(root -> left, key);
        }
        
        if (strcmp(root -> key, key) > 0) {
            return bstFindkey(root -> right, key);
        }
    }
    return NULL;                //key not found
}

/*
 * create a new empty tree
 * POST: Return Empty Tree
*/
bsTree bstCreate()
{
    return NULL;
}

/*
 * destroy the whole tree
 *
*/
void bstDestroy(bsTree* tree){
    btNodeDestroy(tree);
}


/*
 *finds if tree is empty or not
 *POST: True if tree empty , False if Tree not empty
*/
bool bstIsEmpty( bsTree tree){
    if(tree==NULL){
        return true;
    }
    return false;
}


/*
* Checks every node for the max count,
* in the end, the node has the max count
*/
void findMax(btNode* root, btNode* node){
    if (root -> count > node -> count){
        node = root;
    }
    
    if (root -> left != NULL){
        findMax (root -> left , node);
    }
    
    if (root -> right != NULL){
        findMax (root -> right, node);
    }
    
}

void printMax(btNode* root){
    //A node that will be the address to the node with max Count
    //Uses a dummy key ex: ___
    btNode* node = btNodecreate("___"); 
    node -> count = 0;
    
    //After the next function, the adress node is referring to is the
    // node with the max count in all of the tree.
    findMax(root, node);
    
    printf("%s \t %d \t \n", node -> key, node -> count);
    
    //Deletes the node 
    //NOT SURE IF THIS WORKS WITH THE FUNCTION BELOW
        //  AND REALLY DELETES THE NODE CORRECTLY
    btNodeDestroy(**node);
}


void printTree(btNode* root){
    
    printf("Word \t Count \t \n");
    
    while (root != NULL){
        printMax(root);
    }
    
    printf("\nEnd of the tree.");
}