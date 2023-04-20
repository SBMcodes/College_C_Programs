#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	struct node* next;
};

struct Graph{
	int numVertices;
	int* visited;
	
	struct node** adjLists;
};

struct node* createNode(int v){
	struct node* newNode = malloc(sizeof(struct node));
	newNode -> vertex = v;
	newNode -> next = NULL;
	return newNode;
}

struct Graph* createGraph(int numVertices){
	struct Graph* graph = malloc(sizeof(struct Graph));
	
	graph->numVertices = numVertices;
	graph -> adjLists = malloc(sizeof(struct node) * numVertices);
	graph -> visited = malloc(sizeof(int) * numVertices);
	
	int i;
	for(i=0;i<numVertices;i++){
		graph -> adjLists[i] = NULL;
		graph -> visited[i] = 0;
	}
	
	return graph;
}

void addEdge(struct Graph* graph,int src,int dest){
	struct node* newNode = createNode(dest);
	
	
}

int main(){
	
	return 0;
}
