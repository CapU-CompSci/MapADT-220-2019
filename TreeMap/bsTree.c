







#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "bsTree.h"







































btNode* bstFindkey(btNode* root, char* key) {
    /*
    *   If strcmp returns a negative number, it means the 
    *   first string is bigger, ex: first string is aaa
    *   and the second value is zzz
    */
    
    if ( strcmp(root -> key, key) == 0 ){
        return root;
    }
    
    if (strcmp(root -> key, key) < 0) {
        return bstFindkey(root -> left, key);
    }
    
    if (strcmp(root -> key, key) > 0) {
        return bstFindkey(root -> right, key);
    }
    
    else //Key does not exist
        return NULL;
}