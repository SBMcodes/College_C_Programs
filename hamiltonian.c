#include<stdio.h>
#include<stdlib.h>
#define TOTAL_VERTICES 5

// What is a hamiltonian cycle?
// Hamiltonian cycle is a cycle in a graph where from starting vertices we traverse all vertices without repeating
// any vertice and it should terminate at starting vertice We can find hamiltonian cycle in a graph using
// backtracking This approach is very simialar to DFS but with a mix of backtracking



// Prints the hamiltonian path
void printPath(int path[TOTAL_VERTICES]){
	int i;
	printf("Hamiltonian Cycle \n");
	for(i=0;i<TOTAL_VERTICES;i++){
		if(i!=TOTAL_VERTICES-1)
			printf("%d -> ",path[i]);
		else
			printf("%d",path[i]);
	}
	printf("\n");
}


// Checks if a node can be connected to another node by
// making sure its not already available in the path array
// and its an adjacent vertex of previously added vertex 
// as it needs to be the adjacent vertex of previous vertex
// v: vertex we want to connect
// pos: current position in path
int canConnect(int graph[TOTAL_VERTICES][TOTAL_VERTICES],int path[TOTAL_VERTICES],int pos,int v){
	int i;
	
	
	// if the vertex is already in the path then we return 0
	for(i=0;i<TOTAL_VERTICES;i++){
		if(path[i]==v){
			return 0;
		}
	}
	
	// Checks for if its an adjacent vertex of the previous vertex
	if(graph[path[pos-1]][v]==0){
		return 0;
	}
	
	
	return 1;
}


// Recursive function which uses backtracking to find hamiltonian cycle
int findHamCycle(int graph[TOTAL_VERTICES][TOTAL_VERTICES],int path[TOTAL_VERTICES],int pos){
	
	// Base Case
	// If all nodes are included in our current path then we check for
	// if current node leads to starting vertice if yes then we have found
	// the hamiltonian cycle and return 1 otherwise return 0
	if(pos==TOTAL_VERTICES){
		if(graph[path[pos-1]][path[0]]==1){
			return 1;
		}
		return 0;
	}
	
	
	// If not the base case then we continue the branch
	int v;
	// Starting with vertex 1 as we have choosen vertex 0 as the root vertex
	for(v=1;v<TOTAL_VERTICES;v++){
		if(canConnect(graph,path,pos,v)){
			
			// Connect it with the path
			path[pos] = v;
			
			// Recursive call to connect another vertice
			if(findHamCycle(graph,path,pos+1) == 1){
				return 1;
			}
			
			// Backtracks to previous result and check for other vertices
			path[pos] = -1;
		}
	}
	
	
	return 0;
}



int hamCycle(int graph[TOTAL_VERTICES][TOTAL_VERTICES]){
	int path[TOTAL_VERTICES],i;
	
	// setting default value of all the node in a path to -1
	// as we have not visited any of them yet
	for(i=0;i<TOTAL_VERTICES;i++){
		path[i] = -1;
	}
	
	// Setting the starting vertice of the path as 0 though we can choose any vertice
	// because in a undirected graph where hamiltonian cycle is present starting from any
	// should lead us to the starting vertice
	path[0] = 0;
	
	if(findHamCycle(graph,path,1) == 0){
		printf("\nCould Not Find Hamiltonian Cycle!\n");
		return 0;
	}
	
	printPath(path);
	
	return 1;
}


int main(){
	
	// Undirected Graph
	// AB AC BD CE DE
	 int graph[TOTAL_VERTICES][TOTAL_VERTICES] = { 
	 {0,1,1,0,0}, 
	 {1,0,0,1,0},
     {1,0,0,0,1}, 
	 {1,0,0,0,1}, 
	 {0,0,1,1,0}};
            
    hamCycle(graph);
	
	
	// Undirected Graph
	// AB AC BD CD DE
	 int graph2[TOTAL_VERTICES][TOTAL_VERTICES] = { 
	 {0,1,1,0,0}, 
	 {1,0,0,1,0},
     {1,0,0,1,0}, 
	 {1,0,1,0,1}, 
	 {0,0,0,1,0}};
    hamCycle(graph2);
    
	return 0;
}
