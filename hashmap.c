/* This will be the .c file corresponding with the hashmap.h file 
*
*   Authors: Reece Whitehead, Artur Shadnik     
*
*/

 #define COL_SIZE 20
 #define ARRAY_SIZE 100












 /* 
  * Hashing algortihm by Dan Bernstein, via http://www.cse.yorku.ca/~oz/hash.html
  */
 long Hmapfunction(unsigned Keytype Key){
     unsigned long hash = 5381;
     int c;
     
     while( c = *Key++){
         hash = (( hash<<5 ) + hash) + c;
     }
     return hash;
 }
    
    
    
    
    
    
    
    Hash_Array Hmapcreate()