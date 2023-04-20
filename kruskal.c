#include<stdio.h>

#define TOTAL_VERTICES 4


// What is Kruskal's Algorithm and How to find it?


// Spanning Tree Properties
// Number of edges in MST = Number of Vertices - 1
// Number of vertices in MST = Number of Vertices
// Removing one edge from spanning tree will make it disconnected
// Adding one edge to the spanning tree will create a cycle
// n^n-2 number of spanning tree is possible for a complete undirected graph
// Removing max e-v+1 we can construct a spanning tree

// Remove all the loops
// Remove Parallel edges Keep the edge which has minimum weight

// Arrange all the edges accorading to their edge weight in increasing order
// Choose edge which has minimum edge weight from the list
// Continue forming the graph knowing it should not form a cycle









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





typedef struct Edge{
	int u,v;
	int weight;
}Edge;


typedef struct EdgeList{
	Edge list[TOTAL_VERTICES*TOTAL_VERTICES];
	int total;
}EdgeList;

EdgeList edgeList,mstEdgeList;



void printMstEdgeList(){
	int i;
	for(i=mstEdgeList.total-1;i>=0;i--){
		printf("u: %d v:%d weight: %d\n",mstEdgeList.list[i].v,mstEdgeList.list[i].u,mstEdgeList.list[i].weight);
	}
}






void sortEdges(){
	int i,j,minIndex;
	Edge temp;
	
	for(i=0;i<edgeList.total;i++){
		minIndex=i;
		for(j=i+1;j<edgeList.total;j++){
			if(edgeList.list[j].weight<edgeList.list[minIndex].weight){
				minIndex = j;
			}
		}
		temp = edgeList.list[minIndex];
		edgeList.list[minIndex] = edgeList.list[i];
		edgeList.list[i] = temp;
	}
}





int findParent(int* parent,int i){
	if(i==parent[i]){
		return i;
	}
	else{
		return findParent(parent,parent[i]);
	}
}


void updateParent(int parent[],int uRoot,int vRoot){
	int i;
	
	for(i=0;i<TOTAL_VERTICES;i++){
		if(parent[i]==vRoot){
			parent[i] = uRoot;
		}
	}
}

void kruskal(){
	int parent[TOTAL_VERTICES],i,j,uRoot,vRoot;
	edgeList.total = 0;
	
	
	// Creating and adding all the edges generated from the graph to the edge list 
	for(i=1;i<TOTAL_VERTICES;i++){
		for(j=0;j<i;j++){
			if(graph[i][j] != 0){
				edgeList.list[edgeList.total].u = i;
				edgeList.list[edgeList.total].v = j;
				edgeList.list[edgeList.total].weight = graph[i][j];
				edgeList.total++;
			}
		}
	}
	
	// Setting MST EdgeList to 0 initially
	mstEdgeList.total = 0;
	
	// Setting the parent of all vertices to itshelf initially
	for(i=0;i<TOTAL_VERTICES;i++){
		parent[i] = i;
	}
	
	// Sorting all the edges accorading to its weight in ascending order
	sortEdges();
	
	
	
	//Adding edge to MST EdgeList if root of both the vertices of edge are not equal (to avoid cycles)
	for(i=0;i<edgeList.total;i++){
		uRoot = findParent(parent,edgeList.list[i].u);
		vRoot = findParent(parent,edgeList.list[i].v);
		
		if(uRoot!=vRoot){
			mstEdgeList.list[mstEdgeList.total] = edgeList.list[i];
			mstEdgeList.total+=1;
			updateParent(parent,uRoot,vRoot);
		}
	}
}



int main(){
	kruskal();
	printMstEdgeList();
	return 0;
}
