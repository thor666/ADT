#ifndef _LIST_H
#define _LIST_H //define _LIST_H if its not defined. 

typedef struct node node;

struct node
{
        int elem;
        node *next;
};

//In each case the lnodeptr * is pointer to pointer to node. Also its the pointer to pointer to the first node in the list.

int list_push(node **, int); //Compulsory!
void list_pop(node **); //Compulsory!
void list_delete(node **); //Compulsory! This will delete the list. Be careful while freeing the memory.
int list_length(node **); //Compulsory! Returns the length of the list.
void list_add(node **, node **); //Optional, This one concatenates another list.
void list_sub(node **, node *); //Optional, This one removes/cut thhe list.
void list_to_array(node **, int *); //Optional, but try to implement
#endif
/******************************************************************/