#include<stdio.h>
#include<stdlib.h>
#define SIZE 4




// Adjacency matrix
// We can also take it as user input
// AB,AC,BD,CD
int matrix[SIZE][SIZE] = {
	{0,1,1,0},
	{1,0,0,1},
	{1,0,0,1},
	{0,1,1,0},
};




void dfs(int startNode){
	int i,j,top,val;
	int stack[SIZE],visited[SIZE];
	
	for(i=0;i<SIZE;i++){
		visited[i] = 0;
	}
	visited[startNode] = 1;
	
	stack[0] = startNode;
	
	
	//we are using top variable to keep track of stack state
	top=0;
	
	while(top>=0){
		val = stack[top]; // Currently selected node
		top--; // Decreasing top Its similar to popping a value from stack
		
		// Checking all the neighbours of currently selected node
		for(j=0;j<SIZE;j++){
			// if its a neighbour and not visited before
			if(matrix[val][j]==1 && visited[j]==0){
				visited[j] = 1;
				
				// increasing top value
				top++;
				// Adding at the top of the stack
				stack[top] = j;
			}
		}
		
		printf("Visited Node: %d\n",val);
	}
}






int main(){
	dfs(2);
	return 0;
}
