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
   //insert word in tree and update value
   //inert word in tree -> insert will either update val or insert new word
   //ispunc() iff yes shift left (use A1 algorithm)  
   // print indorder of treee

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
	
	while(f!=EOF){
		fscanf(f, " %127s", &word); // reads all chars until white space
		removePunc(word);
		mapInsert(wordtree, word, count);  //assuming insert updates value(which is count))
		}
		
		printf("WordCloud Frequency \n");
		//print tabular form needs formatting..
		inorderPrint(wordtree);
		
		fclose(f);
		printf("\nIn order Finished...")
}

void removePunc(char* word){
 	int i;
 	char c = word[0]; //first character

     for(i=0; i<strlen(word); i++){
 		if (c == ispunc(word[i]))
 		shiftLeft(word, i);
     }
}

void shiftLeft(char* word, int index){
	int i;
	for (i=index; i<strlen(word); i++){
		word[i]= word[i+1]
	}
}


void inorderPrint(map_t treemap){
   	
   	if(mapIsEmpty(treemap)){
   		inorderPrint(tree->left)
   		nodePrint(*treemap);
   		inorderPrint(tree->right);
   	}
}


void nodePrint (bstNode_t Node){
	printf("---%s" node.entry.key);
	printf("---%d",node.entry.value);
}


FILE* open(char* filename)     //open the file and check existence
{
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error: file does not exist: %s \n", filename);
		exit(-1);
	}
	return file;
}