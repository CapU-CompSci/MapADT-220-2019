/*
 *  Comp220 - wordcloud.c
 *    
 *
 *  Author: Tim Wriglesworth, Karan Nedungadi
 *  Date: Mar. 2017 // edited in April 06
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "treemap.h"
#include "hashmap.h"
#include "map.h"


//PSUEDO CODE
   //create new treemap
   //parse each word in file
   //remove any punction found in parsed word
   //inert word in tree -> insert will either update val or insert new word
   // print inorder of tree

//function prototypes
FILE* open (char*);
void nodePrint (bstNode_t Node);
void inorderPrint(map_t treemap);
void removePunc(char* word);
void shiftLeft(char* word, int index);


int main (int argc, char* argv[])  
{
	
char* filename; //get user input
filename = argv[1];
	
	if (argc <2){
		printf("usage error: filename.txt");   // print some usage handling
		exit(-1);
	}
	FILE* f = open(filename);     //call my function
	
	wordtree = mapCreate();
	char* word;
	int count = 1;
	
	while(fscanf(f, " %127s", &word) == 1){
		removePunc(word);
		mapInsert(wordtree, word, count);  //still needs work
		}
		
		printf("WordCloud Frequency \n");
		//print tabular form needs formatting..
		inorderPrint(wordtree);
		
		fclose(f);
		printf("\nIn order Finished...")
}

//removes all punction from input string
void removePunc(char* word){
 	int i;
 	char c = word[0]; //first character
 	
 	for(i=0; i<strlen(word); i++){
 		if (c == ispunc(word[i]))
 		shiftLeft(word, i);
 	}
}


// shifts characters following index 1 place to left, 
// "overwriting" the item at pos. index, shortening string by 1 
void shiftLeft(char* word, int index){
	int i;
	for (i=index; i<strlen(word); i++){
		word[i]= word[i+1]
	}
}


//prints the binary search tree from lowest to largest key value
void inorderPrint(map_t treemap){
   	
   	if(!mapIsEmpty(treemap)){
   		inorderPrint(tree->left)
   		nodePrint(*treemap);
   		inorderPrint(tree->right);
   	}
}

// prints the key-value pair for the respective node in the tree
void nodePrint (bstNode_t Node){
	printf("---%s" node.entry.key);
	printf("---%d",node.entry.value);
}


//open the file and check existence
FILE* open(char* filename){
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error: file does not exist: %s \n", filename);
		exit(-1);
	}
	return file;
}