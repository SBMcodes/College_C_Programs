#include<stdio.h>
#define INFINITY 9999999

// ©SBM
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


int findMinCost(int arr[],int size){
	
	//Here size -> Total Matrices + 1
	int matrix[size][size];
	int i,k,row,col,cost,length;
	
	for(i=1;i<size;i++){
		matrix[i][i] = 0; //filling all the diagonal elements with 0
	}
	
	// Looping from length to total number of matrices as the cost of 1 matrice is 0 (Base)
	for(length=2;length<size;length++){
		
		// Notice that row number will decrease with increasing length as diagonal size get decreased
		for(row=1;row<=size-length;row++){
			
			// Notice that there is only one column for a particular row and length as its a diagonal
			col = row + length - 1;
			
			printf("row:%d\n",row);
			printf("col:%d\n\n",col);
			
			// Setting the value of matrix row and col to infinity before updating it with min cost
			matrix[row][col] = INFINITY;
			
			// Trying to find min cost by checking all possible combinations
			for(k=row;k<col;k++){
				
				printf("row: %d\n",row);
				printf("k: %d\n",k);
				printf("Value: %d\n",matrix[row][k]);
				
				
				printf("k+1: %d\n",k+1);
				printf("col: %d\n",col);
				printf("Value: %d\n\n",matrix[k+1][col]);
				
				
				
				// Lets understand this with an example if we are trying to find for row 1 col 4 (1-4)
				// then we will check for mincosts 1-1 + 2-4 + cost of multiplying previous two matrices
				// & 1-2 + 3-4 + cost of multiplying previous two matrices & 
				// 1-3 + 4 -4 + cost of multiplying previous two matrices whichever has
				// min cost will be updated in the cost matrix
				cost = matrix[row][k] + matrix[k+1][col] + arr[row-1]*arr[k]*arr[col];
				
				// if cost is less than current min cost then we will update it
				if(cost<matrix[row][col]){
					matrix[row][col] = cost;
				}
			}
		}
	}
	
	return matrix[1][size-1];
}


int main(){
	int arr[] = {2,3,4,5,6}; // represents 2x3 3x4 4x5 5x6 matrix
	int size = sizeof(arr)/sizeof(int);
	int minNum = findMinCost(arr,size);
	printf("Minimum number of multiplication required is: %d",minNum);
	return 0;
}
