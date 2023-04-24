#include<stdio.h>
#include <stdlib.h>
#define SIZE 100

// Not a real hash table

typedef struct hashItem{
	int key;
	int value;
} hashItem;

typedef struct hashTable{
	hashItem* items[SIZE];
} hashTable;

int findHashCode(int key){
	return key % SIZE;
}

void insertItem(hashTable* table,int key,int value){
	hashItem* newItem = (hashItem*) malloc(sizeof(hashItem));
	newItem->key = key;
	newItem->value = value;
	
	int hashIndex = findHashCode(key);
	
	table->items[hashIndex] = newItem;
	
}

int getItem(hashTable* table,int key){
	int hashIndex = findHashCode(key);
	return table->items[hashIndex]->value;
}


int main(){
	hashTable* dict = (hashTable*)malloc(sizeof(hashTable));
	
	insertItem(dict,12,240);
	insertItem(dict,45,20);
	insertItem(dict,12,1200);
	
	printf("%d",getItem(dict,12));
	
	return 0;
}
