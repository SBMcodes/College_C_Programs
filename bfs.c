#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

// What is BFS and How to implement it?
// BFS or Breadth First Search is an algorithm which helps us
// to traverse or search in a graph data structure
// It starts at the root level and explores all nodes at current depth
// before moving on to next depth
// There are two ways to implement it
// Using adjacency matrix and adjacency list 
// We are going to use adjacency matrix in this program

// Adjacency matrix
// We can also take it as user input
// AB,AC,BD,CD
int matrix[SIZE][SIZE] = {
	{0,1,1,0},
	{1,0,0,1},
	{1,0,0,1},
	{0,1,1,0},
};




void bfs(int startNode){
	int i,j,front,rear,val;
	int queue[SIZE],visited[SIZE];
	
	for(i=0;i<SIZE;i++){
		visited[i] = 0;
	}
	visited[startNode] = 1;
	
	queue[0] = startNode;
	
	
	//we are using front and rear variable to keep track of queue state
	front = 0;
	rear = 0;
	
	while(front<=rear){
		val = queue[front]; // Currently selected node
		// Checking all the neighbours of currently selected node
		for(j=0;j<SIZE;j++){
			// if its a neighbour and not visited before
			if(matrix[val][j]==1 && visited[j]==0){
				visited[j] = 1;
				
				// increasing rear value
				rear++;
				// Adding at the rear end of the queue
				queue[rear] = j;
			}
		}
		
		printf("Visited Node: %d\n",val);
		// Increasing front value of queue Its similar as popping a value
		front++;
	}
}






int main(){
	bfs(2);
	return 0;
}
