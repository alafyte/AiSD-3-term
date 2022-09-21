#pragma once
#include "stdafx.h"

namespace GraphAdjacencyList
{
    class Graph
    {
    private:
        int numOfVertices;
        vector<list<int>> adj;

    public:
        Graph(int V);

        void addEdge(int v, int w);

        void print();

        void BFS(int s);

    };
}

