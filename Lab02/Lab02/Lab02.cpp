#include <iostream>
#include "GraphEdgeList.h"
#include "GraphAdjacencyMatrix.h"
#include "GraphAdjacencyList.h"

namespace GEL = GraphEdgeList;
namespace GAM = GraphAdjacencyMatrix;
namespace GAL = GraphAdjacencyList;

int main()
{
	setlocale(LC_ALL, "rus");
	GAM::Graph graphSecond;
	//Для матрицы
	cout << "1) Поиск в ширину (порядок обхода вершин):" << endl;
	graphSecond.BFS(1);
	cout << "\n2) Поиск в глубину (порядок обхода вершин):" << endl;
	graphSecond.DFS(1);

	cout << "\n\n\nГраф (список ребёр): " << endl;
	vector<GEL::Edge> edges = {
		{1, 2}, {1, 5}, {5, 6}, {2, 7}, {2, 8}, {7, 8}, {3, 8}, {4, 6}, {4, 9}, {9, 10}
	};
	GEL::Graph graphFirst(edges, 10);
	graphFirst.print();

	cout << "\nГраф (матрица смежности):" << endl;
	graphSecond.print();

	cout << "\n\nГраф (список смежности): " << endl;
	GAL::Graph graphThird(10);

	graphThird.addEdge(1, 2);
	graphThird.addEdge(1, 5);
	graphThird.addEdge(2, 1);
	graphThird.addEdge(2, 7);
	graphThird.addEdge(2, 8);
	graphThird.addEdge(3, 8);
	graphThird.addEdge(4, 6);
	graphThird.addEdge(4, 9);
	graphThird.addEdge(5, 1);
	graphThird.addEdge(5, 6);
	graphThird.addEdge(6, 4);
	graphThird.addEdge(6, 5);
	graphThird.addEdge(6, 9);
	graphThird.addEdge(7, 2);
	graphThird.addEdge(7, 8);
	graphThird.addEdge(8, 2);
	graphThird.addEdge(8, 3);
	graphThird.addEdge(8, 7);
	graphThird.addEdge(9, 4);
	graphThird.addEdge(9, 6);
	graphThird.addEdge(9, 10);
	graphThird.addEdge(10, 9);
	graphThird.print();

	cout << endl;

	system("pause");
	return 0;
}
