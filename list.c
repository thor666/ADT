/*
        DESCRIPTION: program that implements linked list operation: push, pop, delete and length
        AUTHOR: Varsha Rao
        EMAIL: bvr.6894@gmail.com
        VERSION:1.0
*/
        #include "list.h"

        #include <stdio.h>

        int list_push(node ** first, int elem)
        {
        	node * temp;
        	node * ptr;

        	ptr=(node*)malloc(sizeof(node));

        	if(ptr==NULL)
        		return 0;
        	else{
        		ptr->elem=elem;
        		ptr->next=NULL;
        		if(*first==NULL){
        			printf("\n list is empty");
        			*first=ptr;
                    printf("\n inserted");
        		}
        		else{
        			temp=*first;
        			while(temp->next!=NULL){
        				temp=temp->next;
        			}
        			temp->next=ptr;
        			printf("\n inserted");
        		}
        	}
        }

        void list_pop(node ** first)
        {
        	node * temp;
        	node * ptr;

        	temp=*first;
        	if(*first==NULL)
        		printf("\n list is empty");
        	else{
        		while(temp->next->next!=NULL){
        			temp=temp->next;
        		}
                ptr=temp->next;
                temp->next=NULL;
        		free(ptr);
                printf("\n popped");
        	}
        }

        void list_delete(node ** first)
        {
        	
            int count=list_length(first);
            int i;
            for(i=1; i<count; i++){
                list_pop(first);
            }
            node * temp;
            temp=*first;
            *first=NULL;
            free(temp);
            printf("%d\n", list_length(first) );
        }

int list_length(node ** first)
{
	node * ptr;

    ptr = *first;
    int count=0;
    while(ptr!= NULL)
    {
        printf("\n elements %d",ptr->elem);
        ptr = ptr->next;
        count++;
    }
    return count;
}

void list_add(node ** first1, node ** first2)
{
    node *temp;
    temp=*first1;

    while(temp->next!=NULL){
                        temp=temp->next;
                        printf("%d\n",temp->elem);
                    }
                    temp->next=*first2;

                    int c=list_length(&first1);
                    printf("\nlength %d\n",c);
}

void list_sub(node ** first, node* ref)
{
    node *temp;
    temp=*first;

    while(temp->next!=ref){
                        temp=temp->next;
                    }
                    temp->next=NULL;
}

void list_to_array(node ** first, int * len)
{
    node *temp;
    temp=*first;

    int array[*len], i=0;
    while(temp->next!=NULL){
                        temp=temp->next;
                        array[i]=temp->elem;
                        i++;
                    }

    for(i=0; i<*len; i++)
    {
        printf("%d\n", array[i]);
    }
}
