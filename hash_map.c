/*
        DESCRIPTION: program that implements hash tables using the division function
        AUTHOR: Varsha Rao
        EMAIL: bvr.6894@gmail.com
        VERSION:2.0
*/

#include <stdio.h>
#include "list.h"
#include "hash_map.h"
#include "list.c"

#define M 11; 

node * array[11];

int hash_func(int elem)
{
	return elem%M;
}

void init()
{
	int i=0;
	while(i<11)
	{
		array[i++] = NULL;
	}
}
void insert(int elem)
{
	int j = hash_func(elem);

	hashMap_push(&array[j], elem);
}

void search(int elem)
{
	int j= hash_func(elem);

	list_search(&array[j], elem);
}

void display()
{
	int i;

	for(i=0; i<11; i++){

		printf("Displaying the map with index %d\n", i);
		list_length(&array[i]);
	}
}

void delete(int elem)
{
	int j =hash_func(elem);
	list_remove(&array[j], elem);
}

int hashMap_push(node **first, int elem)
{
	node *temp, *ptr;
	ptr = (node *)malloc(sizeof(node));
	
	if(ptr==NULL){
		return -1;	//memory allocation failure
	}
		else{
		ptr->elem = elem;
		ptr->next=NULL;

		if(*first==NULL){
			printf("List is empty\n");
			*first = ptr;
			printf(" first node with value %d inserted\n", ptr->elem);			
		}

		else{
			temp = *first;
			
			while(temp->next!=NULL){
				if(elem==temp->next->elem){
					printf("Cannot insert %d its a duplicate\n", elem);
					return 1;
				}
				temp = temp->next;			
			}

			temp->next = ptr; 
			printf("Node with value %d inserted \n", elem);
				
		}
		free(ptr);
		free(temp);
		return 0;
	}
}

