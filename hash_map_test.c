#include <stdio.h>
#include "list.h"
#include "hash_map.h"


int main()
{
	int array[20]={1, 23, 67, 90, 45, 13, 45, 20, 3, 4, 4, 6, 4, 23, 34, 56, 89, 90, 76, 2};

	init();
	int i;
	for(i=0; i<20; i++){
		insert(array[i]);
	}

	display();

	return 0;
}