#pragma once
#include "stdafx.h"

class Graph
{
private:
	int graphMatrix[9][9] = {
	{0, 7, 10, 0, 0, 0, 0, 0, 0},
	{7, 0, 0, 0, 0, 9, 27, 0, 0},
	{10, 0, 0, 0, 31, 8, 0, 0, 0},
	{0, 0, 0, 0, 32, 0, 0, 17, 21},
	{0, 0, 31, 32, 0, 0, 0, 0, 0},
	{0, 9, 8, 0, 0, 0, 0, 11, 0},
	{0, 27, 0, 0, 0, 0, 0, 0, 15},
	{0, 0, 0, 17, 0, 11, 0, 0, 15},
	{0, 0, 0, 21, 0, 0, 15, 15, 0}
	};

	char vertices[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
public:
	void print();

	//ѕоиск вершины с минимальным рассто€нием
	int static minDistance(int dist[], bool visited[]);

	void dijkstra(char src);

	void printSolution(int dist[]);

};

