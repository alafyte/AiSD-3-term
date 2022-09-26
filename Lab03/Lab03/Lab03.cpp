#include <iostream>
#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    Graph graph;

    graph.dijkstra('E');

    system("pause");

    return 0;
}
