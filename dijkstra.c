#include<stdio.h>
#define INFINITY 9999999
#define TOTAL_VERTICES 5


// What is dijkstra algorithm and how does it work?
// Dijkstra algorithm helps us to find the shortest path between two vertices
// We can get the minimum cost between two nodes in a graph
// and also the path we should take to have that minimum cost



//AB(4) AC(6) BC(1) BE(5) CD(8) DE(2)
// A -> D (Source Dest)
int graph[TOTAL_VERTICES][TOTAL_VERTICES];

// Cost Matrix which shows us distance from starting vertice(user choice) to other vertices
int costGraph[TOTAL_VERTICES][TOTAL_VERTICES];



// Initialize graph with 0's
void initGraph(){
	int i,j;
	for(i=0;i<TOTAL_VERTICES;i++){
		for(j=0;j<TOTAL_VERTICES;j++){
			graph[i][j] = 0;
		}
	}
}


// Adds edge to graph
void addEdge(int u,int v,int weight){
	graph[u][v] = weight;
	graph[v][u] = weight;
}


// Helper Function to print current graph
void printGraph(){
	int i,j;
	for(i=0;i<TOTAL_VERTICES;i++){
		for(j=0;j<TOTAL_VERTICES;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n");
}


// Helper Function to print cost graph
void printCostGraph(){
	int i,j;
	for(i=0;i<TOTAL_VERTICES;i++){
		for(j=0;j<TOTAL_VERTICES;j++){
			if(costGraph[i][j] == INFINITY){
				printf("x ");
			}
			else{
				printf("%d ",costGraph[i][j]);
			}
			
		}
		printf("\n");
	}
	printf("\n\n");
	
}




// Function to find cost matrix from starting vertice to other vertices
void findMinCost(int start){
	int i,j;
	
	// distance -- Min Distance of each vertice from starting vertice
	// visited -- Mark the vertice as visited if all of its adjancent vertices are explored
	// pred -- Predecessor of each node in the minimum path of a graph it acts similar to a linked list
	int distance[TOTAL_VERTICES],visited[TOTAL_VERTICES],pred[TOTAL_VERTICES];
	
	// curMinNode -- Stores the current Node which has minimum distance while iterating through loop
	// curMinDist -- Helpful when iterating through vertices and we are trying to find the min node
	// among all non visited vertices
	int curMinNode,curMinDist,count=0;
	
	
	// Setting the initial cost of each vertices before calculating actual cost
	for(i=0;i<TOTAL_VERTICES;i++){
		for(j=0;j<TOTAL_VERTICES;j++){
			if(graph[i][j]==0){
				costGraph[i][j] = INFINITY;
			}
			else{
				costGraph[i][j] = graph[i][j];
			}
		}
	}
	
	
	for(i=0;i<TOTAL_VERTICES;i++){
		
		// Setting distance of each vertice from starting vertice
		// at first only immediate vertices adjacent to starting vertices are set to a cost
		// other vertices get the value of INFINITY
		
		if(i==start){
			distance[start] = 0;
			visited[start] = 1;
		}
		else{
			distance[i] = costGraph[start][i];
			visited[i] = 0;
		}
		
		pred[i] = start;
	}
	
	
	
	
	
	
	while(count<TOTAL_VERTICES){
		curMinDist = INFINITY;
		
		
		// Finding next min cost vertice among all non visited vertices
		for(i=0;i<TOTAL_VERTICES;i++){
			if(!visited[i] && distance[i]<curMinDist){
				curMinNode = i;
				curMinDist = distance[i];
			}
		}
		
		visited[curMinNode] = 1;
		
		
		
		
		// Updating all the vertices adjacent to the current min node
		// if the adjacent vertice is not visited
		// and if its current cost/distance is greater than if we go through cur min node
		// then we update the distance of that vertice
		
		// If we see a vertice for the first time
		// then it is bound to update its distance as initial distance of all vertices 
		// except adjacent vertices of starting vertice is infinite
		
		// It is helpful in next iteration when we are trying to find the minNode among all the
		// adjacent vertices of already visited vertices
		for(i=0;i<TOTAL_VERTICES;i++){
			if(!visited[i]){
				if(curMinDist + costGraph[curMinNode][i] < distance[i]){
					
//					printf("%d\n",count);
//					printf("%d\n",curMinDist);
//					printf("%d\n",costGraph[curMinNode][i]);
//					printf("%d\n",distance[i]);
//					printf("\n");
					
					distance[i] = curMinDist + costGraph[curMinNode][i];
					pred[i] = curMinNode;
				}
			}
		}
		
		count++;
	}
	
	printf("\n\nStarting Vertice: %d\n",start);
	for(i=0;i<TOTAL_VERTICES;i++){
		
		if(i!=start){
			printf("--Node %d--\n\n",i);
			printf("Min Distance: %d\n",distance[i]);
			printf("Path: ");
			
			j=i;
			while(j!=start){
				printf(" %d <- ",j);
				j=pred[j];
			}
			printf("%d",start);
			
		}
		
		printf("\n\n\n");
	}	
}


int main(){
	//AB(4) AC(6) BC(1) BE(5) CD(8) DE(2)
	// A -> D (Source Dest)
	initGraph();
	addEdge(0,1,4);
	addEdge(0,2,6);
	addEdge(1,2,1);
	addEdge(1,4,5);
	addEdge(2,3,8);
	addEdge(3,4,2);
	printGraph();
	
	findMinCost(0);
	
	printCostGraph();
	
	return 0;
}
