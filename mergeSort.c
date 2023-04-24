#include<stdio.h>

void merge(int arr[],int start,int mid,int end){
	int n1 = mid - start + 1;
	int n2 = end - mid;
	
	int i,j,k;
	
	int arr1[n1],arr2[n2];
	
	for(i=0;i<n1;i++){
		arr1[i] = arr[start+i];
	}
	
	for(j=0;j<n2;j++){
		arr2[j] = arr[mid+1+j];
	}
	
	i=0,j=0,k=start;
	
	while(i<n1 && j<n2){
		if(arr1[i]<arr2[j]){
			arr[k] = arr1[i];
			i++;
		}
		else{
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		arr[k] = arr1[i];
		i++;
		k++;
	}
	
	while(j<n2){
		arr[k] = arr2[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[],int start,int end){
	if(start<end){
		int mid = (start + end) / 2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}


int main(){
	int arr[] = {12,98,34,45,64,78,36};
	int length = sizeof(arr)/sizeof(int);
	int i;
	
	mergeSort(arr,0,length-1);
	
	for(i=0;i<length;i++){
		printf("%d\n",arr[i]);
	}
	
	return 0;
}
