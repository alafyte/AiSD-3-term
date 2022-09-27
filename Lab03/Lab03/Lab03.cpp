#include <iostream>
#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    Graph graph;

    graph.dijkstra('A');

    system("pause");

    return 0;
}
