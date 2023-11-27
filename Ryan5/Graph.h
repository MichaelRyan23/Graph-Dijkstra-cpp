/********************************************************************
*** NAME :          Michael Ryan
*** CLASS :         CSC 300
*** ASSIGNMENT :    5
*** DUE DATE :      11/29/2023
*** INSTRUCTOR :    GAMRADT 
*********************************************************************
*** DESCRIPTION : <general english description of the abstract data type> ***
*** <including supporting operations> ***
********************************************************************/
#pragma once
#include <iostream>
using namespace std;

class Graph {

    public:

/********************************************************************
*** FUNCTION <name of function> ***
*********************************************************************
*** DESCRIPTION : <general english description of the function> ***
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        explicit Graph(const string = "data.dat");

/********************************************************************
*** FUNCTION <name of function> ***
*********************************************************************
*** DESCRIPTION : <general english description of the function> ***
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
        ~Graph();

/********************************************************************
*** FUNCTION <name of function> ***
*********************************************************************
*** DESCRIPTION : <general english description of the function> ***
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