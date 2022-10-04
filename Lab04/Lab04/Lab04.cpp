#include "stdafx.h"
#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    Graph graph;
    graph.FloydWarshall();
    graph.PrintSolution();
    system("pause");
}

