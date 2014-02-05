/*
        DESCRIPTION: program that implements linked list operation: push, pop, delete and length
        AUTHOR: Varsha Rao
        EMAIL: bvr.6894@gmail.com
        VERSION:2.0
*/
        #include "list.h"
        #include <stdio.h>
        #include <stdlib.h>

        /*inserts the given integer at the end of list*/
        int list_push(node ** first, int elem)
        {
        	node * temp;
        	node * ptr;

        	ptr=(node*)malloc(sizeof(node));

        	if(ptr==NULL)
        		return -1; //error in memory allocation
        	else{
        		ptr->elem=elem;
        		ptr->next=NULL;

        		if(*first==NULL){
        			printf("\n list is empty");
        			*first=ptr;
                    printf("\n first node with %d inserted", ptr->elem);
        		}
        		else{
        			temp=*first;

        			while(temp->next!=NULL){
        				temp=temp->next;
        			}
        			temp->next=ptr;
        			printf("\n inserted the node with value %d", elem);
        		}
                free(ptr);
                free(temp);
                return 0;
        	}
        }

        /* removes the last integer from the list*/
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
                printf("\n node with value %d is popped", ptr->elem);
                free(ptr);
                free(temp);
        	}
        }

        /* deletes the whole list */
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


/* displays all the elements and returns the length */
int list_length(node **first)
{
	node * ptr;

    ptr = *first;
    int count=0;
    while(ptr!= NULL)
    {
        printf("\n elements :%d",ptr->elem);
        ptr = ptr->next;
        count++;
    }
    printf("length is %d \n",count);
    free(ptr);
    return count;
}

/* concatenates two lists*/
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
    free(temp2);
}

void list_sub(node ** first, node* ref)
{
    node *temp;
    temp=*first;

    while(temp->next!=ref){
        temp=temp->next;
        }
    temp->next=NULL;
    free(temp);
}

void list_to_array(node ** first, int * len)
{
    node *temp;
    temp=*first;

    int array[*len], i=0;
    while(temp!=NULL){
        array[i]=temp->elem;
        i++;
        temp=temp->next;
        }

    for(i=0; i<*len; i++)
    {
        printf("%d\n", array[i]);
    }
    free(temp);
}

/* looks through the whole list to find if the given integer is present */
int list_search(node ** first, int elem)
{
    node *temp;
    temp=*first;
    int i=0;

    while(temp!=NULL){
        if(temp->elem==elem){
            printf("Node with value %d found succesfully\n", elem);
            return i;
        }
        else{
            i++;
            temp=temp->next;
        }
    }
    printf("search unsuccessful\n");
    free(temp);
    return 0;
}

/*deletes the node contatining the given element*/
void list_remove(node **first, int elem)
{
    node *temp1, *ptr, *temp2;
    temp1=*first;
    temp2=temp1->next;
    int flag=0;

    if((temp2->elem)==elem){
        *first=(temp1->next);
        ptr=temp1;
        free(ptr);
        printf("node with value %d deleted\n", elem);
        flag=1;
    }

    else{
        while(temp2!=NULL){
            if(temp2->elem==elem && temp2->next!=NULL){
                temp1->next=temp2->next;
                ptr=temp2;
                free(ptr);
                printf("node with value %d deleted\n", elem);
                flag=1;
                break;
            }
            else if(temp2->elem==elem && temp2->next==NULL){
                temp1->next=NULL;
                ptr=temp2;
                free(ptr);
                printf("node with value %d deleted\n", elem);
                flag=1;
                break;
            }
            temp1=temp2->next;
            temp2=temp2->next;
        }
    }
    if(flag==0){
        printf("Node does not exists..\n");
    }
}
