#include<stdio.h>


int max,max1,min,min1;
void findminmax(int arr[],int low,int high){
	//NegativeCase
	if(low>high){
		return;
	}
	
	//Diff==0 Case
	if(low==high){
		if(arr[low]>max){
			max = arr[low];
		}
		if(arr[low]<min){
			min = arr[low];
		}
		return;
	}
	
	//Diff==1 Case
	if(high-low==1){
		
		if(arr[low]>max){
			max = arr[low];
		}
		else if(arr[high]>max){
			max = arr[high];
		}
		
		if(arr[low]<min){
			min = arr[low];
		}
		else if(arr[high]<min){
			min = arr[high];
		}
		
	}
	
	int mid = (low+high) / 2;
	
	findminmax(arr,low,mid);
	max1 = max;
	min1 = min;
	findminmax(arr,mid+1,high);
	
	if(max1>max){
		max = max1;
	}
	if(min1<min){
		min = min1;
	}
}


int main(){
	int arr[] = {1,2,3,4,5,-4,2};
	int n = sizeof(arr)/sizeof(int);
	
	max= arr[0];
	min = arr[0];
	
	findminmax(arr,0,n-1);
	
	printf("%d\t%d",max,min);
	
	return 0;
}
