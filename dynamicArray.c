#include<stdio.h>
#include<stdlib.h>

typedef struct Array{
	int* array;
	size_t size,used;
}Array;


void initArray(Array *a,int initialSize){
	a->array = malloc(initialSize * sizeof(int));
	
	a->size = initialSize;
	a->used = 0;
}

void insertArray(Array *a,int element){
	if(a->used == a->size){
		a->size *= 2;
		a->array = realloc(a->array,a->size * sizeof(int));
	}
	a->array[a->used++] = element;
}

void freeArray(Array *a){
	free(a->array);
	a->array = NULL;
	a->used =0; 
	a->size = 0;
}

int main(){
	Array a;
	int i;
	
	initArray(&a,10);
	for(i=0;i<100;i++){
		insertArray(&a,i+1);	
	}
	
	for(i=0;i<100;i++){
		printf("%d\n",a.array[i]);
	}
	
	
	return 0;
}
