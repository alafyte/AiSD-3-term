#pragma once
#include "stdafx.h"

struct Edge
{
	int start;
	int end;
	int weight;
};


class Graph
{
private:
	int graphMatrix[8][8] = {
		{INT_MAX, 2, INT_MAX, 8, 2, INT_MAX, INT_MAX, INT_MAX},
		{2, INT_MAX, 3, 10, 5, INT_MAX, INT_MAX, INT_MAX},
		{INT_MAX, 3, INT_MAX, INT_MAX, 12, INT_MAX,INT_MAX, 7},
		{8, 10, INT_MAX, INT_MAX, 14, 3, 1, INT_MAX},
		{2, 5, 12, 14, INT_MAX, 11, 4, 8},
		{INT_MAX, INT_MAX, INT_MAX, 3, 11, INT_MAX, 6, INT_MAX},
		{INT_MAX, INT_MAX, INT_MAX, 1, 4, 6, INT_MAX, 9},
		{INT_MAX, INT_MAX, 7, INT_MAX, 8, INT_MAX, 9, INT_MAX}
	};

public:
	std::vector <Edge> edgeList = {
	{1, 2, 2}, {1, 4, 8}, {7, 5, 4}, {1, 5, 2}, {2, 3, 3}, {2, 5, 5}, {2, 4, 10}, {3, 5, 12}, 
	{3, 8, 7}, {4, 5, 14}, {4, 6, 3}, {4, 7, 1}, {5, 8, 8}, {6, 7, 6}, {7, 8, 9}, {5, 6, 11}
	};
	void Prims();
	void Kruslals();
};

