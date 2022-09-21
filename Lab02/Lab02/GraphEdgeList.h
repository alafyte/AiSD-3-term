#include "stdafx.h"

namespace GraphEdgeList
{

    struct Edge {
        int src, dest;
        Edge(int src, int dest)
        {
            this->src = src;
            this->dest = dest;
        }
    };

    class Graph
    {
    private:
        vector<list<int>> adjList;

    public:
        Graph(vector<Edge> const& edges, int n);

        void print();

        void BFS(int v);
    };
}