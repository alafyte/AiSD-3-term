#include "AntColony.h"

double AntColony::probability(int to, AntWay ant, double** pheromone, double** distance, int vertex)
{
	for (int i = 0; i < ant.itabu; ++i) 
		if (to == ant.tabu[i]) 
			return 0;

	double sum = 0.0;
	int from = ant.tabu[ant.itabu - 1];

	for (int j = 0; j < vertex; ++j) 
	{
		int flag = 1;

		for (int i = 0; i < ant.itabu; ++i) 
			if (j == ant.tabu[i]) 
				flag = 0;

		if (flag) 
			sum += pow(pheromone[from][j], ALPHA) * pow(distance[from][j], BETA);
	}

	return pow(pheromone[from][to], ALPHA) * pow(distance[from][to], BETA) / sum;
}


AntWay AntColony::AntColonyOptimization(int** distance0, int vertex, int start, int finish)
{
	AntWay way;
	way.itabu = 0;
	way.length = -1;
	way.tabu = new int[vertex];

	double** distance = new double* [vertex];
	double **pheromone = new double* [vertex];

	for (int i = 0; i < vertex; ++i) 
	{
		distance[i] = new double[vertex];
		pheromone[i] = new double[vertex];
		for (int j = 0; j < vertex; ++j) 
		{
			pheromone[i][j] = 1.0 / vertex;
			if (i != j) 
				distance[i][j] = 1.0 / distance0[i][j];
		}
	}

	AntWay ants[NUMBER_OF_ANTS];
	for (int k = 0; k < NUMBER_OF_ANTS; ++k) 
	{
		ants[k].itabu = 0;
		ants[k].length = 0.0;
		ants[k].tabu = new int[vertex];
		ants[k].tabu[ants[k].itabu++] = start;
	}

	for (int t = 0; t < TIME_OF_LIFE; ++t) 
	{
		for (int k = 0; k < NUMBER_OF_ANTS; ++k) 
		{
			// поиск маршрута для k-го муравья
			do 
			{
				int j_max = -1;
				double p_max = 0.0;
				for (int j = 0; j < vertex; ++j) 
				{
					if (ants[k].tabu[ants[k].itabu - 1] != j) 
					{
						double p = probability(j, ants[k], pheromone, distance, vertex);
						if (p && p >= p_max) 
						{
							p_max = p;
							j_max = j;
						}
					}
				}
				ants[k].length += distance0[ants[k].tabu[ants[k].itabu - 1]][j_max];
				ants[k].tabu[ants[k].itabu++] = j_max;
			} while (ants[k].tabu[ants[k].itabu - 1] != finish);

			// оставляем феромон на пути муравья
			for (int i = 0; i < ants[k].itabu - 1; ++i) 
			{
				int from = ants[k].tabu[i % ants[k].itabu];
				int to = ants[k].tabu[(i + 1) % ants[k].itabu];
				pheromone[from][to] += Q / ants[k].length;
				pheromone[to][from] = pheromone[from][to];
			}

			if (ants[k].length < way.length || way.length < 0) 
			{
				way.itabu = ants[k].itabu;
				way.length = ants[k].length;
				for (int i = 0; i < way.itabu; ++i) 
					way.tabu[i] = ants[k].tabu[i];
			}

			ants[k].itabu = 1;
			ants[k].length = 0.0;
		}

		for (int i = 0; i < vertex; ++i)
			for (int j = 0; j < vertex; ++j)
				if (i != j) 
					pheromone[i][j] *= 1.0 - RHO;
	}

	return way;
}

int randNum(int start, int end)
{
	int r = end - start;
	int rnum = start + rand() % r;
	return rnum;
}

