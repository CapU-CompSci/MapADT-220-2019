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

#include "freqTree.h"


//function prototypes
FILE* open (char*);
void removePunc(char* word);
void shiftLeft(char* word, int index);

#define MAX_WORD_LENGTH 127
#define WORD_FORMAT "%127s"  // must match MAX_WORD_LENGTH
#define WORDCLOUD_SIZE 25


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
	fclose(f);

	//FOR DEBUGGING:
	//mapPrint(wordmap);
	
	// Assemble and Print the Frequency-Ordered word list
	FreqTree_t frequencies = ftCreate();
	keytype* words = mapKeySet(wordmap);
	int i;
	int n = mapSize(wordmap);
	for (i=0; i<n; i++) {
		ftInsert(&frequencies, mapGet(wordmap, words[i]), words[i]);
	}

	printf("WordCloud Frequencies \n");
	ftPrint(frequencies, WORDCLOUD_SIZE);

	// Clean up dynamic structures
	free(words);
	mapClear(&wordmap);
	ftDestroy(&frequencies);
}

//removes all non-alphabetic character (e.g., punction) from input string
void removePunc(char* word){
 	int i;
 	for(i=0; i<strlen(word); i++){
 		if ( !isalpha(word[i])) 
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

//open the file and check existence
FILE* open(char* filename){
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error: file does not exist: %s \n", filename);
		exit(-1);
	}
	return file;
}