#ifndef _HASHMAP_H
#define _HASHMAP_H //define _LIST_H if its not defined.




void init();//initialises the table to NULL

int hash_func(int);//the hash function used for computing the hash value

void insert(int);//inserts the key into the table

void search(int);// finds if the given element is present in the table

void delete(int);// deletes the given element from the table

//int hashMap_push(int num, node **start)


#endif
