#include "stdafx.h"
#include "GraphAdjacencyMatrix.h"

namespace GraphAdjacencyMatrix
{
	void Graph::print()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				cout << graphMatrix[i][j] << "\t";
			cout << endl;
		}
	}

	void Graph::BFS(int s)
	{
		vector<bool> visited(10, false);

		queue<int> q;

		visited[s - 1] = true;
		q.push(s);

		int vis;
		while (!q.empty()) {
			vis = q.front();

			cout << vis << " ";
			q.pop();

			for (int i = 0; i < 10; i++) {
				if (graphMatrix[vis - 1][i] == 1 && (!visited[i]))
				{
					q.push(i + 1);
					visited[i] = true;
				}
			}
		}
	}

	void Graph::DFS(int s)
	{
		vector<bool> visited(10, false);

		stack<int> stck;

		visited[s - 1] = true;
		stck.push(s);

		int vis;
		while (!stck.empty()) {
			vis = stck.top();

			cout << vis << " ";
			stck.pop();

			for (int i = 9; i >= 0; i--) {
				if (graphMatrix[vis - 1][i] == 1 && (!visited[i]))
				{
					stck.push(i + 1);
					visited[i] = true;
				}
			}
		}
	}
}