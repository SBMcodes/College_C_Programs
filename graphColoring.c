#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#define TOTAL_VERTICES 5

// ©SBM
// We can also take it as user input
// A Pentagon with third and fifth vertices connected with each other
int graph[TOTAL_VERTICES][TOTAL_VERTICES] = {
{1,1,0,0,1},
{1,1,1,0,0},
{0,1,1,1,1},
{0,0,1,0,1},
{1,0,1,1,1}};

int verticsColor[TOTAL_VERTICES];

// Total Amount of color available to us
int totalColor = 3; // 1,2,3



// Change the color of the console text
void Color(int col) {  
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleTextAttribute(hConsole, col);
}



// Checks if its possible to color current vertice with the given color
bool isSafeToColor(int curVertice,int color){
	int i;
	
//	Looping through all the connected vertices of current vertice
	for(i=0;i<TOTAL_VERTICES;i++){
//		If Connected and has same color return false
		if(graph[curVertice][i] == 1){
			if(verticsColor[i] == color){
				return false;
			}
		}	
	}
	
	return true;
}


// Color all vertices graph
bool colorGraph(int curVertice){
	
	int i;
	
//	Stopping Condition for recursive loop
	if(curVertice >= TOTAL_VERTICES){
		return true;
	}
	
	//	Looping through totalColors and checking if we can color the vertex with specific color
	//	If yes then we move onto next vertices recursively otherwise check next color
	//	If subsequent vertices can be colored then it return true
	
	for(i=0;i<totalColor;i++){
		if(isSafeToColor(curVertice,i+1)){
			verticsColor[curVertice] = i+1;
			if(colorGraph(curVertice+1)){
				return true;
				}
			verticsColor[curVertice] = 0;
			}
		}
	
	return false;
}

// Setting all the vertices color to 0 (No Color)
void initVerticesColor(){
	int i;
	for(i=0;i<TOTAL_VERTICES;i++){
		verticsColor[i] = 0;
	}
}


//Printing the current graph
void printGraph(){
	int i,j;
	for(i=0;i<TOTAL_VERTICES;i++){
		for(j=0;j<TOTAL_VERTICES;j++){
			printf(" %d ",graph[i][j]);
		}
		printf("\n");
	}
}

//Printing color of vertices serially
void printColorVertices(){
	int i;
	for(i=0;i<TOTAL_VERTICES;i++){
		Color((i%totalColor) + 2);
		printf(" %d ",verticsColor[i]);
	}
}

int main(){
	initVerticesColor();
	
	if(colorGraph(0)){
		printGraph();
		printf("\n\n");
		printColorVertices();
	}
	else{
		printf("Cant color complete graph with available colors");
	}
	
	
	
	return 0;
}
