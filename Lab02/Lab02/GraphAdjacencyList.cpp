#include "stdafx.h"
#include "GraphAdjacencyList.h"

namespace GraphAdjacencyList
{
	Graph::Graph(int V)
	{
		this->numOfVertices = V;
		adj.resize(V);
	}

	void Graph::addEdge(int v, int w)
	{
		adj[v - 1].push_back(w);
	}

	void Graph::print()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << i + 1 << " -> ";
			for (auto iter = adj[i].begin(); iter != adj[i].end(); ++iter)
			{
				cout << *iter << " ";
			}
			cout << endl;
		}
	}

	void Graph::BFS(int s)
	{
		vector<bool> visited;
		visited.resize(numOfVertices, false);

		queue<int> q;

		visited[s - 1] = true;
		q.push(s);

		while (!q.empty())
		{
			s = q.front();
			cout << s << " ";
			q.pop();

			for (auto adjecent : adj[s - 1])
			{
				if (!visited[adjecent - 1])
				{
					visited[adjecent - 1] = true;
					q.push(adjecent);
				}
			}
		}
	}
}