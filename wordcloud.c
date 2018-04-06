/*
 *  Comp220 - wordcloud.c
 *    
 *
 *  Author: Tim Wriglesworth, Karan Nedungadi
 *  Date: Mar. 2017 // edited in April
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "treemap.h"
#include "hashmap.h"
#include "map.h"

//function prototypes
FILE* open (char*);





int main (int argc, char* argv[])  
{
	
char* filename;          //get user input
filename = argv[1];
	
	if (argc <2)
	{
		printf("usage error: filename.txt");   // print some usage handling
		exit(-1);
	}
   FILE* f = open(filename);     //call my function
   
   
   
   
   
   
   
   
   fclose(f);
   }
   
   
   
   
   
   
   
   
   
   
  
   FILE* open(char* filename)     //open the file and check existence
	{
	   FILE* file = fopen(filename, "r");
	   if (file == NULL) {
		  printf("Error: file does not exist: %s \n", filename);
		  exit(-1);
	   }
	   return file;