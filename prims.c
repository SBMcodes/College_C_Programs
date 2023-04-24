#include<stdio.h>
#include<stdbool.h>

#define TOTAL_VERTICES 4
#define INFINITY 9999999

// Spanning Tree Properties
// Number of edges in MST = Number of Vertices - 1
// Number of vertices in MST = Number of Vertices
// Removing one edge from spanning tree will make it disconnected
// Adding one edge to the spanning tree will create a cycle
// n^n-2 number of spanning tree is possible for a complete undirected graph
// Removing max e-v+1 we can construct a spanning tree


// Remove all the loops
// Remove Parallel edges Keep the edge which has minimum weight

//Prim's Algorithm
// Choose any arbitary node
// Check all outgoing edges from root node
// Choose the outgoing edge (node) which has minimum weight
// Compare all the unvisted edges of current nodes i.e. root node & choosen node
// Choose the node with the minimum weight for edge
// Continue this process till we form the graph





// Cost Adjacency Matrix
// We can also take it as user input but here we have taken directly
// Edges-> AB(01):5 AC(02):3 BD(13):1 CD(23):2 BC(12):6

int graph[TOTAL_VERTICES][TOTAL_VERTICES] = {
{0,5,3,0},
{5,0,6,1},
{3,6,0,2},
{0,1,2,0}
};
int total = TOTAL_VERTICES;









int main(){
	int i,j;
	int selected[TOTAL_VERTICES];
	for(i=0;i<TOTAL_VERTICES;i++){
		selected[i] = false;
	}
	
	int cur_edge = 0;
	
	selected[cur_edge] = true;
	
	int row,col;
	
	
	while(cur_edge<TOTAL_VERTICES - 1){
		int minWeight = INFINITY;
		row=0;
		col=0;
		
		for(i=0;i<TOTAL_VERTICES;i++){
			if(selected[i]){
				for(j=0;j<TOTAL_VERTICES;j++){
					if(!selected[j] && graph[i][j]>0){
						if(graph[i][j]<minWeight){
							minWeight = graph[i][j];
							row = i;
							col = j;
						}
					}
				}
			}
			
		}
		
		selected[col] = true;
		cur_edge++;
		
		printf("%d - %d : %d \n",row,col,minWeight);
	}
	
	
	
	return 0;
}
