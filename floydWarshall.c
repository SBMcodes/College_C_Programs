#include<stdio.h>
#define TOTAL_VERTICES 4
#define INFINITY 999

// What is Floyd Warshall algorithm and How to use it?
// This algoritm helps us to find all pair of shortest path between two nodes in a graph
// and it will also works for negative weight edges
// We can find same result if we use djikstra/bellmanFord for n times for n vertices
// But Floyd warshall algoritm is much more efficent than former
// as it uses dynamic programming concept
// At first we will set the cost matrix same as graph adjacency matrix which initially represents
// the distance between each connected node, Nodes which are not connected are represented as INFINITY
// as we dont know the distance between this nodes and we need to find out
// Then we will iterate v times and for each iteration we will compare
// between the direct distance between nodes and the Indirect distance
// from initial to final node via vth node For Example:
// in first iteration we will check lets say from 2nd vertice to 3rd vertice
// then we will compare the direct distance between them and the distance we
// need to cover if go via 1st vertice (as its the first iteration)
// and we will update the matrix it if distance is lower than the direct distance
// We will do this for each node pair and then we will move onto
// checking for each vertice i.e. next for each pair we will check
// what will happend if we go via second vertice and we will continue this loop till
// we reach vth vertice
// Note that if we are in vth iteration of loop then vth row
// vth column values remains constant as the direct and indirect distance will
// remain same



// Directed Graph
// AB(4) BA(6) AC(10) BC(5) CD(20) BD(12)
int graph[TOTAL_VERTICES][TOTAL_VERTICES] = {
{0,4,10,INFINITY},
{6,0,5,12},
{INFINITY,INFINITY,0,20},
{INFINITY,INFINITY,INFINITY,0}
};


void printMatrix(int costMat[TOTAL_VERTICES][TOTAL_VERTICES]){
	int i,j;
	for(i=0;i<TOTAL_VERTICES;i++){
		for(j=0;j<TOTAL_VERTICES;j++){
			printf("%d\t",costMat[i][j]);
		}
		printf("\n");
	}
}


void floydWarshall(){
	int costMat[TOTAL_VERTICES][TOTAL_VERTICES];
	int i,j,k;
	
	
	//Initializing cost matrix array
	for(i=0;i<TOTAL_VERTICES;i++){
		for(j=0;j<TOTAL_VERTICES;j++){
			costMat[i][j] = graph[i][j];
		}
	}
	
	printMatrix(costMat);
	printf("\n\n");
	
	//Updating Cost Matrix
	for(k=0;k<TOTAL_VERTICES;k++){
		for(i=0;i<TOTAL_VERTICES;i++){
			for(j=0;j<TOTAL_VERTICES;j++){
				if(costMat[i][k] + costMat[k][j] < costMat[i][j]){
					costMat[i][j] = costMat[i][k] + costMat[k][j];
				}
				
			}
		}
	}
	
	printMatrix(costMat);
	
}



int main(){
	floydWarshall();
	return 0;
}
