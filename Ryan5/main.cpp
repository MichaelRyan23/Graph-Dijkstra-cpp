/********************************************************************
*** NAME :          Michael Ryan
*** CLASS :         CSC 300
*** ASSIGNMENT :    5
*** DUE DATE :      11/29/2023
*** INSTRUCTOR :    GAMRADT 
*********************************************************************
*** DESCRIPTION : This assignment creates and implements a graph ADT.
*** The graph is represented by an adjacency matrix with weighted edges
*** between the nodes. Along with this, Dijkstra's algorithm is used on
*** said graph to calculate the shortest path possible from a user's starting
*** node. 
********************************************************************/

#include "Graph.h"
#include <iostream>
using namespace std;

int main() {
    // Create a Graph object with the default file name "data.dat".
    Graph myGraph;
    
    myGraph.dijkstra();

    return 0;
}
