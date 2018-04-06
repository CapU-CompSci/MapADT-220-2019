/* This will be the .c file corresponding with the hashmap.h file 
*
*   Authors: Reece Whitehead, Artur Shadnik, Greagorey Markerian    
*   Date: April 5, 2018
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "hashmap.h"
#include "map.h"

#define COL_SIZE 20
#define ARRAY_SIZE 100

long Hmapfunction( keytype Key);
int mapindex(keytype Key);








  //Authors: Braeden Norman, Artur Shadnik
  // Hashing algortihm by Dan Bernstein, via http://www.cse.yorku.ca/~oz/hash.html
  
 long Hmapfunction( keytype Key){
     unsigned long hash = 5381;
     int c;
     
     while( c = *Key++){
         hash = (( hash<<5 ) + hash) + c;
     }
     return hash;
 }

//Please review and test





    
 //Author: Greagorey Markerian

 int mapindex(keytype Key)
 {
     long hash = Hmapfunction(Key);
     int index = hash%ARRAY_SIZE;
     return index;
}
//Please Review and test





//Author: Greagorey Markerian
void mapInsert( map_t* mapref, entry_t entry)
{
    map_t map = *mapref;
    int index = mapindex(entry.key);
    int counter = 0;
    
    while(map->hashtable[index][counter].key!=NULL)
    {
        counter++;
    }
    map->hashtable[index][counter]=entry;
}








    /*
    * Author:Reece Whitehead
    * Edit:
    * last changed: 4/5/2017
    */
    
    map_t mapCreate(){
        map_t map;
        map = calloc(1,sizeof(Hmap)); //im assuming this sets all values to NULL
        return map;
    }
    
    
    
    
    
    
    
    
    
    
     /*
    * Author:Reece Whitehead
    * Edit:
    * last changed: 4/5/2017
    */
    
    int mapGet(map_t map, keytype key){
        
        if(mapHasKey(map, key)){
            int index = mapindex(key);
            int counter = 0;
    
            while(map->hashtable[index][counter].key != key){
            counter++;
            }
            return map->hashtable[index][counter].value;
            
            
        }
        
        printf("ERROR: key does not exist within map");
        return 0;
        
}


//Please review and test





// Author: Artur Shadnik

void entryDelete(map_t* map, keytype key){
    if (!mapHasKey(map, key)){
        return;
    }
    else{
        int c =0;
        int i = mapindex(key);
   
        while(map->hashtable[i][c].key!=NULL){
            if(map->hashtable[index][counter].key == key){
                free(map->key);
                free(map->value);
                map_t = {NULL, NULL}
            }
            c++;
        }
    }
}

//Please review and test

//author: Greagorey Markerian

bool mapHasKey(map_t map, keytype key)
{
    int counter =0;
    
    int index = mapindex(key);
   
    while(map->hashtable[index][counter].key!=NULL)
    {
        if(map->hashtable[index][counter].key == key)
        {
            return true;
        }
        counter++;
    }
    
    return false;
    
}

    //Please review and test

//Author: Artur Shadnik

void mapClear(map_t * map){
    int i, c;
    for(i = 0; i < ARRAY_SIZE; i++){
        for(c = 0; c < COL_SIZE; c++){
            free(map->key);
            free(map->value);
            map_t = {NULL, NULL}
        }
    }
}

  //Please review and test