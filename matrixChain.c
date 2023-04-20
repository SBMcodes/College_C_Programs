#include<stdio.h>

// What is Matrix Chain Multiplication problem and how to solve it?
// In this problem we have to find the most efficent way to multiply
// a given set of matrices Basically we have to find in which sequence
// we should do matrix multiplication so that we able to minmize the
// number of multiplication operation
// Example: If we are given an array like this: [1,2,3,4] this
// array shows we are given 3 matrices with 1x2 2x3 and 3x4 dimension
// matrices Now we can multiply the matrices in order by (AB)C or A(BC)
// The first order will result in 18 (1*2*3 + 2*3*4) number of multiplication operation
// whereas the second one results in 32 (1*2*4 + 2*3*4) number of multiplication operation
// so clearly first order is better
// Now how we should solve this problem
// We can use dynamic programming to solve this problem
// There are two possible approaches either we go through recursive way or we go through tabulated way
// We will use tabulated approach here Note that this approach is a bottom up approach
// First we make a cost matrix of n order where n is the (total number of matrices + 1)
// As this is a bottom up approach we will first solve all the bottom diagonal calculations (2 matrices)
// i.e. 1 with 2; 2 with 3; 3 with 4; and so on then we will move on to (min cost for multiplying 3 matrices) 
// 1 with 3; 2 with 4; and so on at the end we will find 1 with 4;


int findMatrixChainMup(int arr[],int size){
	int matrix[size][size];
	int i,j,q,length;
	
	for(i=1;i<size;i++){
		matrix[i][i] = 0; //filling all the diagonal elements with 0
	}
	
	for(length=0;length<size;length++){
		
	}
	
	return 0;
}


int main(){
	int arr[] = {2,3,4,5}; // represents 2x3 3x4 4x5 matrix
	int size = sizeof(arr)/sizeof(int);
	int minNum = findMatrixChainMup(arr,size);
	printf("Minimum number of multiplication required is: %d",minNum);
	return 0;
}
