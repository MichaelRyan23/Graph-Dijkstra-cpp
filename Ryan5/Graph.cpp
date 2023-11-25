/********************************************************************
*** NAME :          Michael Ryan
*** CLASS :         CSC 300
*** ASSIGNMENT :    5
*** DUE DATE :      11/29/2023
*** INSTRUCTOR :    GAMRADT 
*********************************************************************
*** DESCRIPTION : <detailed english description of the abstract data type> ***
*** <including supporting operations> ***
********************************************************************/

#include "Graph.h"
#include <fstream>
#include <limits>
#include <string>
using namespace std;

// constructor
Graph::Graph(const string fileName) {
    setGraph(fileName);
}

// destructor
Graph::~Graph() {}

// Dijkstra's algorithm
void Graph::dijkstra() {
    setVisited();
    unsigned short startNode = setStart();

}

void Graph::setGraph(const string fileName) {
    ifstream file(fileName);    // since using this, don't have to close file
    if(file.is_open()) {
        file >> nodeCount;
        for(unsigned short i = 0; i < nodeCount; ++i) {
            for(unsigned short j = 0; j < nodeCount; ++j) {
                file >> cost[i][j];
            }
        }
    } else {
        cout << "Error with opening file: " << fileName << endl;
    }
}

void Graph::setVisited() {
    for(unsigned short i = 0; i < nodeCount; ++i) {
        visited[i] = false;
    }
}

unsigned short Graph::setStart() const {
    unsigned short startNode;

    while(startNode >= nodeCount) {
        cout << "Enter the starting node: ";
        cin >> startNode;
    }
    
    return startNode;
}

void Graph::view() const {
    for(unsigned short i = 0; i < nodeCount; ++i) {
        if(distance[i] == USHRT_MAX) {
            cout << "Distance[" << i << "] = " << "no path" << endl;
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



