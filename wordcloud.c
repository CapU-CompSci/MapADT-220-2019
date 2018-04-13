/*
 *  Comp220 - wordcloud.c
 *    
 *
 *  Author: Tim Wriglesworth, Karan Nedungadi, Joseph Fall
 *  Date: Apr. 2017
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#ifdef HASHMAP
  #include "hashmap.h"
#else
  #include "treemap.h"
#endif
#include "map.h"


//PSUEDO CODE
   //create new treemap
   //parse each word in file
   //remove any punction found in parsed word
   //inert word in tree -> insert will either update val or insert new word
   // print inorder of tree

//function prototypes
FILE* open (char*);
// void nodePrint (bstNode_t Node);
void inorderPrint(map_t treemap);
void removePunc(char* word);
void shiftLeft(char* word, int index);

#define MAX_WORD_LENGTH 127
#define WORD_FORMAT "%127s"  // must match MAX_WORD_LENGTH

int main (int argc, char* argv[])  
{
	if (argc <2){
		printf("usage error: filename.txt");   // print some usage handling
		exit(-1);
	}
	char* filename; //get user input
	filename = argv[1];
	FILE* f = open(filename);     //call my function
	
	map_t wordmap = mapCreate();
	char word[MAX_WORD_LENGTH + 1];
	
	while(fscanf(f, WORD_FORMAT, word) == 1) {
		int count=0;
		if(mapHasKey(wordmap, word)) {
			count = mapGet(wordmap, word) + 1;
		}
		else {
			count = 1;
		}
		removePunc(word);
		mapInsert(&wordmap, word, count);  
	}
	
	//FOR DEBUGGING:
	mapPrint(wordmap);




/*Attempt at printing the data in order based on frequency
Does not work atm, i need to make a copy of the string cointaining keys so i can remove a key after it is printed 
was getting segmentation faults or other errors when i tried to do as above


Author: Reece Whitehead
/*
	keytype* keylist = mapKeySet(&wordmap);
	//keytype list = *keylist;
	keytype reallist;
	
	//strcpy(reallist,*keylist);

	
	int highVal = 0;
	char* highKey = '\0';
	int i=0;
	int q=0;
	int index=0;
	
	while(keylist[i] != '\0'){
		//printf(" %s\n\n", keylist[i]);
		i++;
	}
	
	char list[i];
	
							//(mapHasKey(wordmap, &list[q]) &&

	int p;
	int t=0;

	while(t<i){
	
		highVal = 0;
		q=0;
		while(q<i){
			
			
			if(highVal < mapGet(wordmap, keylist[q])){
				printf("\n%d\n", q);
				printf("%s", keylist[q]);
				highVal = mapGet(wordmap,keylist[q]);
				highKey = keylist[q];
				index = q;
			}
			

			q++;
		
		}
//	printf(" %s-----%d\n", highKey, highVal);
//	keylist[index] = '\0';
		 
		t++;
	}




*/
	
	printf("WordCloud Frequency \n");
	// TODO: print tabular form needs formatting...
	
	// This idea won't work:  "InOrder" is a tree concept - Maps are like Sets, they don't have an order!
	// Besides, even in the treemap implementation, it is sorted in alphabetic order, not frequency order!
	//inorderPrint(wordmap);
	
	fclose(f);
	printf("\nIn order Finished...");
//	free(keylist);
}

//removes all punction from input string
void removePunc(char* word){
 	int i;
 	for(i=0; i<strlen(word); i++){
 		if ( ispunct(word[i])) 
 			shiftLeft(word, i);
 	}
}


// shifts characters following index 1 place to left, 
// "overwriting" the item at pos. index, shortening string by 1 
void shiftLeft(char* word, int index){
	int i;
	for (i=index; i<strlen(word); i++){
		word[i]= word[i+1];
	}
}


//prints the binary search tree from lowest to largest key value
void inorderPrint(map_t treemap){
	printf ("Not implemented yet!\n");
   	/*  This uses non-public members of tree implementation -- not part of Map API!
   	if(!mapIsEmpty(treemap)){
   		inorderPrint(tree->left)
   		nodePrint(*treemap);
   		inorderPrint(tree->right);
   	}
   	*/
}
/*  Implementation details of treemap do not belong here!
// prints the key-value pair for the respective node in the tree
void nodePrint (bstNode_t Node){
	printf("---%s" node.entry.key);
	printf("---%d",node.entry.value);
}
*/

//open the file and check existence
FILE* open(char* filename){
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error: file does not exist: %s \n", filename);
		exit(-1);
	}
	return file;
}