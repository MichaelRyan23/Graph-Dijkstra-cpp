/********************************************************************
*** NAME :          Michael Ryan
*** CLASS :         CSC 300
*** ASSIGNMENT :    5
*** DUE DATE :      11/29/2023
*** INSTRUCTOR :    GAMRADT 
*********************************************************************
*** DESCRIPTION : This implementation file implements the graph class,
*** and includes operations for initalizing a graph from a data file,
*** running Dijkstra's algorithm on said adjacency matrix with edges and
*** their weights, and displays the shortest path result.
********************************************************************/

#include "Graph.h"
#include <fstream>
#include <climits>
#include <string>
using namespace std;

/********************************************************************
*** FUNCTION Constructor
*********************************************************************
*** DESCRIPTION : Constructs a graph by initializing it with data from
*** a user file, using "data.dat" as default. Graph is an adjacency matrix
*** INPUT ARGS : fileName
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
Graph::Graph(const string fileName) {
    setGraph(fileName);
}

/********************************************************************
*** FUNCTION Destructor
*********************************************************************
*** DESCRIPTION : Doesn't really get implemented in this case, but here 
*** just in case for future use perhaps? 
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN :
********************************************************************/
Graph::~Graph() {}

/********************************************************************
*** FUNCTION Dijkstra
*********************************************************************
*** DESCRIPTION : Implements Dijkstra's algorithm to find the shortest
*** from a user-specified starting onde. The function uses private operations
*** to prompt user to enter an appropriate starting node, and then uses
*** logic to calculate the shortest path to each node, displaying the results
*** at the end and asking if the user want to run it again on the same graph.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN :
********************************************************************/
void Graph::dijkstra() {
    
    bool runAgain = false;
    do {
        setVisited();
        Element startNode = setStart();
        for(int i = 0; i < nodeCount; ++i) {
            distance[i] = cost[startNode][i];
            visited[i] = false;
        }
        visited[startNode] = true;
        distance[startNode] = 0;

        // actual algorithm implementation
        for(int i = 0; i < nodeCount - 1; ++i) {
            Element min = USHRT_MAX;
            Element minIndex = startNode;
            for(int j = 0; j < nodeCount; ++j) {
                if(!visited[j] && distance[j] < min) {
                    min = distance[j];
                    minIndex = j;
                }
            }
            visited[minIndex] = true;

            for(int k = 0; k < nodeCount; ++k) {
                if(!visited[k] && cost[minIndex][k] != USHRT_MAX && distance[minIndex] + cost[minIndex][k] < distance[k]) {
                    distance[k] = distance[minIndex] + cost[minIndex][k];
                }
            }
        }

        view();
        if(restart() == true) {
            runAgain = true;
        } else runAgain = false;
    } while(runAgain == true);
}

void Graph::setGraph(const string fileName) {
    ifstream file(fileName);    // since using this, don't have to close file
    if(file.is_open()) {
        file >> nodeCount;      // how big the matrix is
        for(int i = 0; i < nodeCount; ++i) {
            for(int j = 0; j < nodeCount; ++j) {
                file >> cost[i][j];
            }
        }
    } else {
        cout << "Error with opening file" << endl;
    }
}

void Graph::setVisited() {
    for(Element i = 0; i < nodeCount; ++i) {
        visited[i] = false;
    }
}

unsigned short Graph::setStart() const {
    Element startNode;

    do {
        cout << "Enter the starting node: ";
        cin >> startNode;
        if(startNode >= nodeCount || startNode < 0) {
            cout << "Invalid start node!" << endl;
        }
    } while(startNode >= nodeCount || startNode < 0);
    
    return startNode;
}

void Graph::view() const {
    for(Element i = 0; i < nodeCount; ++i) {
        if(distance[i] == USHRT_MAX) {
            cout << "Distance[" << i << "] = no path!" << endl;
        } else {
            cout << "Distance[" << i << "] = " << distance[i] << endl;
        }
    }
}

bool Graph::restart() const {
    char uChoice;
    cout << "Run Dijkstra's algorithm again? (Y/N): ";
    cin >> uChoice;
    return uChoice == 'y' || uChoice == 'Y';
}

