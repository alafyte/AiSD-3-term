#pragma once
#include "stdafx.h"

namespace GraphAdjacencyMatrix
{
	class Graph
	{
	private:
		int graphMatrix[10][10] = {
		{0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
		};

	public:
		void print();

		void BFS(int s);

		void DFS(int s);
	};
}
