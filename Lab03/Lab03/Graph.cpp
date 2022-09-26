#include "stdafx.h"
#include "Graph.h"


void Graph::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << graphMatrix[i][j] << "\t";
		cout << endl;
	}
}

int Graph::minDistance(int dist[], bool visited[])
{
	int minIndex, min = INT_MAX;

	for (int i = 0; i < 9; i++)
	{
		if (visited[i] == false && dist[i] <= min)
		{
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}


void Graph::printSolution(int dist[])
{
	for (int i = 0; i < 9; i++)
		cout << this->vertices[i] << " --- " << dist[i] << endl;
}

void Graph::dijkstra(char s)
{
	auto itr = find(vertices, vertices + 8, s);
	int src = distance(vertices, itr);
	int dist[9];
	bool visited[9];

	for (int i = 0; i < 9; i++)
	{
		dist[i] = INT_MAX;
		visited[i] = false;
	}

	dist[src] = 0;

	for (int j = 0; j < 8; j++)
	{
		int u = Graph::minDistance(dist, visited);

		visited[u] = true;

		for (int k = 0; k < 9; k++)
			if (!visited[k] && this->graphMatrix[u][k] && dist[u] != INT_MAX
				&& dist[u] + this->graphMatrix[u][k] < dist[k])
				dist[k] = dist[u] + this->graphMatrix[u][k];
	}

	this->printSolution(dist);
}








