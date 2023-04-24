#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

// ©SBM
// What is 15 puzzle problem and how to solve it?
// In this problem we are given a 4x4 matrix where one cell is empty(0)
// and other cells are filled up from 1 to 15 We have to solve reorder the
// cells so that all numbers from 1 to 15 are ordered and at 16th there exists
// the empty space We use branch and bound technique to solve this problem
// where we check the empty cell by moving it all the 4 direction and see which gives
// us minimum number of errors and we move the cell in that direction On next iteration
// we make sure to not go back to position where we came back from By error we mean
// the total number of positions where the number is not at its place


// Count total no of errors in a matrix by comparing it with target matrix
int countErrors(int firstMat[SIZE][SIZE]){
	int secMat[SIZE][SIZE] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,0},
	};
	int i,j;
	int count=0;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(firstMat[i][j]!=secMat[i][j]){
				count++;
			}
		}
	}
	
	return count;
}

// Move the empty value(0) up/down/left/right
int moveMat(int mat[SIZE][SIZE],int dir){
	int i,j,x,y,temp;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(mat[i][j] == 0){
				x=i;
				y=j;
			}
		}
	}
	
	// Move empty space up
	if(dir==0){
		if(x-1>=0){
			temp = mat[x-1][y];
			mat[x-1][y] = mat[x][y];
			mat[x][y] = temp;
			
			return 1;
		}
		else{
			return -1;
		}
	}
	// Move empty space down
	else if(dir == 1){
		
		if(x+1<=SIZE-1){
			temp = mat[x+1][y];
			mat[x+1][y] = mat[x][y];
			mat[x][y] = temp;
			
			return 1;
		}
		else{
			return -1;
		}
		
	}
	// Move empty space left
	else if(dir == 2){
		if(y-1>=0){
			temp = mat[x][y-1];
			mat[x][y-1] = mat[x][y];
			mat[x][y] = temp;
			
			return 1;
		}
		else{
			return -1;
		}
	}
	// Move empty space right
	else if(dir == 3){
		if(y+1<=SIZE-1){
			temp = mat[x][y+1];
			mat[x][y+1] = mat[x][y];
			mat[x][y] = temp;
			
			return 1;
		}
		else{
			return -1;
		}
	}
}

// Returns Total no of error by moving the empty value up/down/left/right
int countErrorByMoving(int tempMat[SIZE][SIZE],int dir){
	int movable = moveMat(tempMat,dir);
	if(movable==-1){
		return 999999999;
	}
	int count = countErrors(tempMat);
	return count;
}


// Iniitialize a matrix with the values present in current matrix
void initTempMat(int tempMat[SIZE][SIZE],int curMat[SIZE][SIZE]){
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			tempMat[i][j] = curMat[i][j];
		}
	}
}

void printMatrix(int mat[SIZE][SIZE]){
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%d  ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}




int main(){
	int curMatrix[SIZE][SIZE] = {
	{1,2,3,4},
	{5,6,0,8},
	{9,10,7,11},
	{13,14,15,12},
	};
	int targetMatrix[SIZE][SIZE] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,0},
	};
	int tempMat[SIZE][SIZE];
	
	
	
	int choice=0; // Choice 0: move up 1: move down 2: move left 3: move right
	int prevChoice = -1;
	int minError = 999999999;
	int tempError;
	
	int count;
	
	while(countErrors(curMatrix)!=0){
		minError = 999999999;
		
		
		initTempMat(tempMat,curMatrix);
		// Check errors for moving up
		if(prevChoice!=0){
			tempError = countErrorByMoving(tempMat,0);
			printf("Total Error if moved %d: %d\n",0,tempError);
			if(tempError<minError){
				choice = 0;
				minError = tempError;
			}
		}
		
		
		initTempMat(tempMat,curMatrix);
		// Check errors for moving down
		if(prevChoice!=1){
			tempError = countErrorByMoving(tempMat,1);
			printf("Total Error if moved %d: %d\n",1,tempError);
			if(tempError<minError){
				choice = 1;
				minError = tempError;
			}
		}
		
		
		initTempMat(tempMat,curMatrix);
		// Check errors for moving left
		if(prevChoice!=2){
			tempError = countErrorByMoving(tempMat,2);
			printf("Total Error if moved %d: %d\n",2,tempError);
			if(tempError<minError){
				choice = 2;
				minError = tempError;
			}
		}
		
		
		initTempMat(tempMat,curMatrix);
		// Check errors for moving right
		if(prevChoice!=3){
			tempError = countErrorByMoving(tempMat,3);
			printf("Total Error if moved %d: %d\n",3,tempError);
			if(tempError<minError){
				choice = 3;
				minError = tempError;
			}
		}
		
		if(choice==0){
			prevChoice=1;
		}
		else if(choice==1){
			prevChoice = 0;
		}
		else if(choice==2){
			prevChoice = 3;
		}
		else if(choice == 3){
			prevChoice = 2;
		}
		
		
		printf("Moving: %d\n",choice);
		moveMat(curMatrix,choice);
		
		printf("Errors: %d\n",countErrors(curMatrix));
		printMatrix(curMatrix);
		
		
	}
	
	return 0;
}
