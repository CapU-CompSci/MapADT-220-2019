/*
 * Comp220 - freqtree.c
 * Implementation of frequency tree ADT
 *
 * Authors: J. Fall
 * Date: April 15, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "freqTree.h"

//------ BT NODE --------
ftNode_t* ftnodeCreate(Entry_t entry) 
{
    ftNode_t* node = malloc(sizeof(ftNode_t));
    node->entry = entry;
    node->left= NULL;
    node->right= NULL;
    return node;
}

void ftnodePrint(ftNode_t node) 
{
    printf("%6d\t%s\n", node.entry.key, node.entry.value);
}

/*
 * Create and return an empty Frequncy Tree
 */
FreqTree_t ftCreate() 
{
	return (FreqTree_t) NULL;
}

/*
 * Empty and free all dynamic memory associated with the tree
 */
void ftDestroy(FreqTree_t* treeref)
{
   FreqTree_t tree = *treeref;
   if (!ftIsEmpty(tree)) {
      ftDestroy(&tree->left);
      tree->left = NULL;
      ftDestroy(&tree->right);
      tree->right = NULL;
      free(tree);
      *treeref = NULL;
   }   
}

/*
 * Helper: Print the first n nodes from the tree
 */
void ftPrintSubTree(const FreqTree_t tree, int* n)
{
   if (!ftIsEmpty(tree)) {
      ftPrintSubTree(tree->left, n);
      ftnodePrint(*tree);
      (*n)--;
      ftPrintSubTree(tree->right, n);
   }
}

/*
 * Print a graphical representation of the frequencies stdout
 * Only the top n frequent entries are printed, if n > 0
 */
void ftPrint(const FreqTree_t tree, int n)
{
   printf("Count \t  Word\n");
   printf("_____ \t ------ \n");
   ftPrintSubTree(tree, &n);
}
/* 
 *  Return the number of nodes in the given tree, including the root node
 */
int ftSize(const FreqTree_t tree)
{
   if ( ftIsEmpty(tree) )
      return 0;
   else
      return ftSize(tree->left) + ftSize(tree->right) + 1;
}

/*
 * Return true if ftSize(tree) == 0, false otherwise.
 */
bool ftIsEmpty(const FreqTree_t tree)
{
   return tree == NULL;
}

/*
 * Insert the given key into the given tree
 */
void ftInsert(FreqTree_t* treeref, KeyType key, ValueType value)
{
   FreqTree_t tree = *treeref;
   Entry_t entry = {key, value};
   
   if ( ftIsEmpty(tree) )
      *treeref = ftnodeCreate(entry);
   else if (key > tree->entry.key)
      ftInsert(&tree->left, key, value);
   else // duplicate inserts are essential since frequencies can be duplicated!
      ftInsert(&tree->right, key, value);
}
