#include "stdafx.h"
#include "Graph.h"


int main()
{
    setlocale(LC_ALL, "Rus");
    Graph graph;
    cout << "Список ребер остовного дерева и их вес (алгоритм Прима)" << endl;
    graph.Prims();
    cout << "\nСписок ребер остовного дерева и их вес (алгоритм Краскала)" << endl;
    graph.Kruslals();
}

