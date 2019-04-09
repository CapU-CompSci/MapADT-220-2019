/************************************************************************
*	Coures: COMP 220													*
*	Aurhtor: Che-Hao chuang												*
*	Date: March 26th, 2019												*
*																		*
*	Lab9															*
*																		*
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/***********node functions************/
struct node{
	int key;
	struct node* left;
	struct node* right;
};
typedef struct node node_t;
node_t* nodeCreate(int data){
	node_t* new = malloc(sizeof(node_t));
	new->key = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}
int Size(node_t* tree){
	if(tree == NULL){
		return 0;
	}else{
		return 1 + Size(tree->left)+Size(tree->right);
	}
}
int Height(node_t* tree){
	
	if(tree == NULL){
		return 0;
	}else{
		int lHeight = Height(tree->left);
		int rHeight = Height(tree->right);
		if(lHeight > rHeight){
			return (lHeight+1);
		}
		return (rHeight+1);
	}
}
void printTabLevel(int num){				//helper function for level print
	for(int i = 0; i <num; i++){
		printf("	");
	}
}
void PrintInOrder(node_t* tree, int level){
	if(tree != NULL){
		PrintInOrder(tree->right,level+1);
		printTabLevel(level);
		printf("[%d]\n",tree->key);
		PrintInOrder(tree->left,level+1);
	}else{
		printf("");
	}
}
void PrintPreOrder(node_t* tree){
	if(tree != NULL){
		printf("%d\n",tree->key);
		PrintPreOrder(tree->right);
		PrintPreOrder(tree->left);
	}else{
		printf("");
	}
}
void PrintPostOrder(node_t* tree){
	if(tree != NULL){
		PrintPostOrder(tree->left);
		PrintPostOrder(tree->right);
		printf("%d\n",tree->key);
	}else{
		printf("");
	}
}
void Destroy(node_t** tree_p){
	node_t* tree = *tree_p;
	if(tree != NULL){
		Destroy(&tree->left);
		Destroy(&tree->right);
		free(tree);
		*tree_p = NULL;
	}
}
/***********node functions************/


/***********tree functions************/
typedef node_t* BinarySearchTree_t;
BinarySearchTree_t btCreate(){
	return NULL;
}
bool btIsEmpty(BinarySearchTree_t tree){
	if(tree==NULL){
		return true;
	}
	return false;
}
int btSize(BinarySearchTree_t tree){
	return Size(tree);
}
int btHeight(BinarySearchTree_t tree){
	return Height(tree);
}
void btPrint(BinarySearchTree_t tree){
	PrintInOrder(tree,0);
	printf("\n");
}
void btDestroy(BinarySearchTree_t* tree_p){
	Destroy(tree_p);
}
void bstInsert(BinarySearchTree_t* tree_ref, int k){
	BinarySearchTree_t tree = *tree_ref;
	if(btIsEmpty(tree)){
		*tree_ref = nodeCreate(k);
	}else{
		if(tree->key > k){
			bstInsert(&tree->left,k);
		}else{
			bstInsert(&tree->right,k);
		}
	}
}
BinarySearchTree_t btFind(BinarySearchTree_t tree, int k){
	if(btIsEmpty(tree)){
		return NULL;
	}
	if(tree->key == k){
		return tree;
	}
	if(tree->key > k){
		return btFind(tree->left,k);
	}else{
		return btFind(tree->right,k);
	}
}


/***********tree functions************/




void main(){
	
	BinarySearchTree_t tree = btCreate();
	assert(btIsEmpty(tree));
	assert(btHeight(tree) == 0);
	bstInsert(&tree, 10);
	bstInsert(&tree, 13);
	bstInsert(&tree, 7);
	printf("\nTree:\n");
	btPrint(tree);
	assert(!btIsEmpty(tree));
	assert(btSize(tree) == 3);
	assert(btHeight(tree) == 2);
	
	
	bstInsert(&tree, 9);
	bstInsert(&tree, 5);
	bstInsert(&tree, 3);
	bstInsert(&tree, 11);
	bstInsert(&tree, 14);
	bstInsert(&tree, 12);
	bstInsert(&tree, 8);
	bstInsert(&tree, 4);
	bstInsert(&tree, 2);
	printf("\nTree:\n");
	btPrint(tree);
	assert(btSize(tree) == 12);
	assert(btHeight(tree) == 5);
	
	
	BinarySearchTree_t resultOne = btFind(tree,9);
	printf("Found %d.......\n",resultOne->key);
	BinarySearchTree_t resultTwo = btFind(tree,50);
	assert(resultTwo == NULL);
	printf("Didn't found 50........\n");
	
	
	btDestroy(&tree);
	btPrint(tree);
	printf("DONE!\n");
}
s