#include <stdio.h>
#include <stdbool.h>
#define BOARD_SIZE 8

// ©SBM
// What is 8 Queen Problem and How to solve It?
// In this problem we have to place 8 queen on a 8x8 chessboard so that none of them attack one another
// To solve this problem we will be using backtracking approach



int board[BOARD_SIZE][BOARD_SIZE];


// Prints current state of board
void printBoard(){
	int i,j;
	for(i = 0;i<BOARD_SIZE;i++){
		for(j = 0;j<BOARD_SIZE;j++){
			if(board[i][j]==0)
				printf(" . ");
			else
				printf(" Q ");
		}
		printf("\n\n");
	}
}

//Checks if queen is safe to place in that square
bool isSafeToPlace(int row,int col){
	int i,j;
	
//	Checking left of current col of current row by decreasing row count and keeping column count same
	for(i=0;i<col;i++){
		if(board[row][i] == 1){
			return false;
		}
	}
	
	//	Check upper diagonal of left side by decreasing the row count and decreasing column count
	for(i=row,j=col;i>=0 && j>=0;i--,j--){
		if(board[i][j] == 1){
			return false;
		}
	}
	
	//	Check lower diagonal of left side by increasing the row count and decreasing column count
	for(i=row,j=col;i<BOARD_SIZE && j>=0;i++,j--){
		if(board[i][j] == 1){
			return false;
		}
	}
	
	return true;
}

//Try to place queen for each column
bool solveNqueen(int col){
	int i;
	
//	Stopping condition for recursion if we have reached column count greater than total column
	if(col >= BOARD_SIZE){
		return true;
	}
	
	
	//	Checking each row if queen can be place if any row is found then 
	// 	goes to check next column recursively and finally return true if subsequent
	//	columns return true otherwise backtrack and check for other rows
	
	for(i=0;i<BOARD_SIZE;i++){
		
		if(isSafeToPlace(i,col)){
			
			board[i][col] = 1;
			
			if(solveNqueen(col+1)){return true;}
			
			board[i][col] = 0;
			
			}
		}
	
	return false;
}



int main(){
	
	int i,j;
	for(i = 0;i<BOARD_SIZE;i++){
		for(j = 0;j<BOARD_SIZE;j++){
			board[i][j] = 0;
		}
	}
	
	if(solveNqueen(0) == true){
		printBoard();
	}
	else{
		printf("No Solution Exist");
	}
	
	
	
	return 0;
}
