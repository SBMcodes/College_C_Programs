#include<stdio.h>

int partition(int arr[],int start,int end){
	//End should be the last index of the array
	int i=start,j=end;
	int pivot = arr[start];
	
	
	while(i<j){
		while(arr[i]<=pivot && i<=end){
			i++;
		}
	
		while(arr[j]>pivot && j>=start){
			j--;
		}
		
		if(i<j){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	
	int temp = arr[j];
	arr[j] = arr[start];
	arr[start] = temp;
	
	return j;
	
}


void quickSort(int arr[],int start,int end){
	if(start<end){
		int partLoc = partition(arr,start,end);
		quickSort(arr,start,partLoc-1);
		quickSort(arr,partLoc+1,end);
	}
}

void printArr(int arr[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\n",arr[i]);
	}
}


int main(){
	int arr[] = {7,1,5,3,6,4,24,84,-45};
	
	quickSort(arr,0,sizeof(arr)/sizeof(int)-1);
	
	printArr(arr,sizeof(arr)/sizeof(int));
	
	
	return 0;
}
