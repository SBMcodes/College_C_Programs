#include <stdio.h>
#define SIZE 6


// ©SBM
// What is knapsack(fractional) problem and how to solve it?
// In this problem we are given a knapsack a fancy word for bag and n number of objects
// with a given weight and a profit Knapsack has limit to how much weight it can carry
// We have to put objects in knapsack in such a way such that we able to maximize profit
// So at the end its a maximization problem and we will use greedy method to solve this problem





// We can take all of this as user input but i have taken it like this
float weight[SIZE] = {45,20,98,32,64,70}; // All the weights of 6 objects
float profit[SIZE] = {12,6,65,20,28,32}; // All the profits of 6 objects
float ratio[SIZE]; // Ratio of profit and weight of objects
int capacity = 200; //Capacity of the bag i.e. TotalWeight it can carry





// Helper function to swap any two numbers in an array
void swap(float* arr,int index1,int index2){
	float temp;
	temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}


// Helper function to print any float array
void printArr(float* arr){
	int i;
	for(i=0;i<SIZE;i++){
		printf("%f\n",arr[i]);
	}
}



void knapsack(){
	float fract[SIZE], // Array to store the fraction of the weight of each obj we are taking in our knapsack
	totalProfit = 0;
	
	int i,j,capacityLeft;
	capacityLeft = capacity; // How much capacity is left in bag after storing a object
	
	
	
	
	for(i=0;i<SIZE;i++)
		fract[i] = 0;
	
	
	// As the arrays are already sorted accorading to profit ratio 
	// so we can directly add objects to the knapsack one by one
	// we will go out of the loop once we encounter a object whose weight
	// is greater than the capacity left Later we will only add fraction of the object to our knapsack
	// to fill the knapsack
	for(i=0;i<SIZE;i++){
		if(weight[i]>capacityLeft)
			break;
		else{
			fract[i] = 1;
			totalProfit = totalProfit + profit[i];
			capacityLeft = capacityLeft - weight[i];
		}
	}
	
	// If objects are still left to be added then we will check
	// how much fraction of the weight we can add to the knapsack
	// and then we will add it
	if(i<SIZE){
		fract[i] = capacityLeft / weight[i];
		totalProfit = totalProfit + (profit[i] * fract[i]);
	}
	
	printf("Maximum Profit: %f",totalProfit);
}


int main(){
	int i,j,min,temp;
	
//	Finding ratio for profit and weight
	for(i=0;i<SIZE;i++){
		ratio[i] = profit[i]/weight[i];
	}
	
//	Using selection sort to sort weight profit and ratio accorading to the ratio in descending order
	for(i=0;i<SIZE;i++){
		min = i;
		for(j=i+1;j<SIZE;j++){
			if(ratio[j]>ratio[min]){
				min = j;
			}
		}
		
		swap(ratio,i,min);
		swap(profit,i,min);
		swap(weight,i,min);
	}
	
	// Calling knapsack to get the maximum profit and fraction of weight of each object we should store
	knapsack();
	
	
	return 0;
}
