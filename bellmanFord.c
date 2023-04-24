#include<stdio.h>
#include <stdlib.h>
#define INFINITY 999999

// What is Bellman Ford algorithm and How does it work?
// Bellman Ford algorithm is similar to dijkstra algorithm but it helps us in finding shortest path
// in a graph where edges have negative weights dijkstra algorithm may or may not work when
// edges have negative weights It is slower than dijkstra though because in Bellman ford
// we have iterate through loop (v-1) times to relax the edges whereas in dijkstra it was only 1 time
// This algorithm will not work if the graph has negative weight cycle which means if the sum of all the weight
// in a cycle turns out to be negative then this algorithm will not work
// Algorithm:
// First we have to choose the starting vertice from where we will find the mininmum distance to all the other
// vertice and then we have to set starting vertuce distance as 0 as start to start will always be 0 :)
// Vertices other than starting vertice we will set to infinity
// Next we will iterate (v-1) times to relax the weight of the edges as in vth time there will be no change
// in the weight that's the reason we will stop at (v-1)th time
// Inside the loop the logic is very similar dijkstra
// if distance of u + cost of edge u,v < distance of v then we will update
// distance of v with distance of u + cost of edge u,v



typedef struct Edge{
	int u,v,w;
}Edge;

typedef struct Graph{
	int TOTAL_VERTICES,TOTAL_EDGES;
	Edge* edges;
}Graph;

Graph* graph;



void printArr(int* arr,int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\n",arr[i]);
	}
	printf("\n");
}


void bellmanFord(int start){
	int i,j;
	int u,v,w;
	
	// This array denotes the mindistance from starting vertice to other vertices
	int distance[graph->TOTAL_VERTICES];
	// This array denotes predecessor of each vertice Its helpful in finding the minimum path by backtracking
	// value from each node
	int pred[graph->TOTAL_VERTICES];
	
	// Initializing Distance and Predecessor array with infinity and 0 respectively
	for(i=0;i<graph->TOTAL_VERTICES;i++){
		distance[i] = INFINITY;
		pred[i] = 0;
	}
	distance[start] = 0;
	
	// Looping |V| - 1 times to relax the edges 
	for(i=0;i<graph->TOTAL_VERTICES-1;i++){
		for(j=0;j<graph->TOTAL_EDGES;j++){
			u = graph->edges[i].u;
			v = graph->edges[i].v;
			w = graph->edges[i].w;
			
			
			if(distance[u]!= INFINITY && distance[v] > distance[u] + w){
				//updates the min vertice of vertice v
				distance[v] = distance[u] + w;
				// Denotes predecessor of v vertice is the u vertice
				pred[v] = u;
			}
		}
	}
	
	
	// This loop basically checks if the edges can be relaxed vth time
	// if it can then it means there is a negative weight cycle in the loop
	// as there should be no edges left to be relaxed after relaxing it v-1 th times
	for(i=0;i<graph->TOTAL_EDGES;i++){
		u = graph->edges[i].u;
		v = graph->edges[i].v;
		w = graph->edges[i].w;
		if(distance[u]!= INFINITY && distance[v] > distance[u] + w){
			printf("Negative Weight Cycle is found!");
			return;
		}
	}
	
	
	printf("Distance Array: \n");
	printArr(distance,graph->TOTAL_VERTICES);
	printf("Predecessor Array: \n");
	printArr(pred,graph->TOTAL_VERTICES);
}





int total_vertices,total_edges;

int main(){
	
	graph = (Graph *)malloc(sizeof(struct Graph));
	graph->TOTAL_VERTICES = 6;
	graph->TOTAL_EDGES = 6;
	graph->edges = (Edge *)malloc(graph->TOTAL_EDGES * sizeof(Edge));
	
	
	
	int i;
	
	// Remember its a directed graph i.e. direction here is from u to v
	for(i=0;i<graph->TOTAL_EDGES;i++){
		printf("Enter Starting Vertex for edge %d: ",i+1);
		scanf("%d",&graph->edges[i].u);
		printf("Enter Ending Vertex for edge %d: ",i+1);
		scanf("%d",&graph->edges[i].v);
		printf("Enter Weight for edge %d: ",i+1);
		scanf("%d",&graph->edges[i].w); 
		}
  
  bellmanFord(0);


	
	return 0;
}
