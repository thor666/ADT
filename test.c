#include<stdio.h>
#include "list.h"

    #include<stdio.h>
#include "list.h"

        int main(void)
        {
            node *first = NULL;
            node *first2=NULL;

            list_push(&first, 1);
            list_push(&first, 2);
            list_push(&first, 3);
            list_push(&first, 4);

            list_pop(&first);
            list_pop(&first);

            list_delete(&first);

            list_push(&first, 1);
            list_push(&first, 2);
            list_push(&first, 3);
            list_push(&first, 4);

            int count;
            count=list_length(&first);
            printf("\n%d\n", count);

            list_push(&first2, 5);
            list_push(&first2, 6);
            list_push(&first2, 7);
            list_push(&first2, 8);

            count=list_length(&first2);
            printf("\n%d\n", count);

            list_add(&first, &first2);

            list_to_array(&first, &count);

            return 0;
        }

       