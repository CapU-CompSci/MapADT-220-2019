
/* 
 *  Definition of HashMap
 *
 *
 * Author: Artur Shadnik, Braeden Noman, Reece Whitehead,Greagorey Markerian
 * Date: April 5th
 *
 */
 
 
 #define COL_SIZE 20
 #define ARRAY_SIZE 100

 
 typedef char* keytype;
 
 typedef struct{
     keytype key;
     int value;
 }entry_t;

 typedef struct{
     entry_t hashtable[ARRAY_SIZE][COL_SIZE];
 }Hmap;
 

 typedef Hmap* map_t;
 