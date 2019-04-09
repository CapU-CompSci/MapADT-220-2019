


/*******************
 * PRIVATE TYPE DECLARATION
 ********************/
struct  Node {
	char* hash_key;					//Hash Key	
    int value;					//Hash Value
    struct Node* next;			//pointer to the next node	
};									
typedef struct Node Node_t;	


/*******************
 * PRIVATE TYPE DECLARATION
 ********************/
struct list_s{
	Node_t* head;				//pointer to the head node
	Node_t*tail;				//pointer to the tail node
};
typedef struct list_s linkedList;



/*
 * Constructor - return a node 
 * POST:  Node: [Value][NULL-]
 */
Node_t* nodeCreate(int value);


/*
 * Constructor - return a new, empty list 
 * POST:  isEmpty(list) == NULL
 */
linkedList llCreate();

/*
 * Output a text representation of a node
 */
void printNode(Node_t*node);

/*
 * Output a text representation of the list
 */
void printList(linkedList list);


/*
 * Returns True is the list is empty, False otherwise 
 */
bool isEmpty(const linkedList list);

/*
 * Append the given item to the list 
 * POST: Linked List list grows by 1 node, which the tail now points too.
 */
void llAppend(linkedList* list, int data);



/*
*	Destructor Function
*	POST: isEmpty(list) == True
*/
void llDelete(linkedList* list);
