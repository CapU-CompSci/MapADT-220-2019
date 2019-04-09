/*
 *  HashMap Dependancy : Linked List
 *
 *  Author:  Keyann Al-Kheder
 *  
 */



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "linkedList.h"




/*
 * Constructor - return a node 
 * POST:  Node: [Value][NULL-]
 */
Node_t* nodeCreate(char* key, int value) {
  Node_t* node = malloc(sizeof(Node_t));
  node->hash_key = malloc(sizeof(strlen(key) + 1));
  strcpy(node->hash_key, key);
  node->value = value;
  node->next = NULL;
  return node;
}


/*
 * Constructor - return a new, empty list 
 * POST:  isEmpty(list) == NULL
 */
linkedList llCreate(){
	linkedList llist = {NULL, NULL};    // taken from the stanford link on moodle, for linked lists.
	return llist;
}


/*
 * Output a text representation of a node
 */
void printNode(Node_t*node){
	printf("[%s][%d]%s", node->hash_key, node->value, node->next ? "-->" : "--|"); //taken from your code in class
}

/*
 * Output a text representation of the list
 */
void printList(linkedList list){

	Node_t* cur = list.head;
	printf("\nList:  ");

	while (cur != NULL){
		printNode(cur);
		cur = cur->next;
	}
	printf("\n\n");
}


/*
 * Returns True if the list is empty
 */
bool isEmpty(const linkedList list){
	return list.head == NULL;
}


/*
 * Append the given item to the list 
 * POST: Linked List list grows by 1 node, which the tail now points too.
 */
void llAppend(linkedList* list, char* key, int data){

	Node_t* newNode = nodeCreate(key, data);

	if (isEmpty(*list)){
		list->head = newNode;
	}
	else{
		list->tail->next = newNode;
	}
	list->tail = newNode;
}



/*
*	Destructor Function
*	POST: isEmpty(list) == True
*/
void llDelete(linkedList* list){
	
	Node_t* cur = list->head;

	while(cur != NULL){
		cur = cur->next;
		free(list->head);
		list->head = cur;
	}
	list->tail = NULL;
}


int main(){
	return 0;
}
