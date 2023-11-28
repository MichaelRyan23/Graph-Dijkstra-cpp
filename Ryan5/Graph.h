/********************************************************************
*** NAME :          Michael Ryan
*** CLASS :         CSC 300
*** ASSIGNMENT :    5
*** DUE DATE :      11/29/2023
*** INSTRUCTOR :    GAMRADT 
*********************************************************************
*** DESCRIPTION : This class helps represent a graph (adjacency matrix)
*** along with the edges and their weights, and has operations supporting 
*** Dijkstra's algorithm to find the shortest possible path in a user-asked 
*** specification.
********************************************************************/
#pragma once
#include <iostream>
using namespace std;

class Graph {

    public:

/********************************************************************
*** FUNCTION constructor
*********************************************************************
*** DESCRIPTION : Creates a graph using data from a file, default file name
*** being "data.dat"
*** INPUT ARGS : fileName
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : object of graph class
********************************************************************/
        explicit Graph(const string = "data.dat");

/********************************************************************
*** FUNCTION Destructor
*********************************************************************
*** DESCRIPTION : In this implementation, it doesn't really do anything
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        ~Graph();

/********************************************************************
*** FUNCTION Dijkstra
*********************************************************************
*** DESCRIPTION : Implements Dijkstra's algorithm on a specific graph/
*** adjacency matrix. Goes from a user-defined start node to the other nodes
*** in the graph. 
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        void dijkstra();

    private:
        typedef unsigned short Element;
        enum {GRAPH_LIMIT = 15};
        Graph(const Graph &) = delete;
        void setGraph(const string);
        void setVisited();
        unsigned short setStart() const;
        void view() const;
        bool restart() const;
        Element cost[GRAPH_LIMIT][GRAPH_LIMIT];
        Element distance[GRAPH_LIMIT];
        bool visited[GRAPH_LIMIT];
        unsigned short nodeCount;
};