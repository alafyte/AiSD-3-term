#pragma once
#include <locale>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define NUMBER_OF_ANTS 20

struct AntWay 
{
	int itabu;
	int length;
	int* tabu;
};

int randNum(int start, int end);

class AntColony
{
public:
	AntWay AntColonyOptimization(int** distance0, int vertex, int start, int finish);
	AntColony(int alpha, int betta, int q)
	{
		ALPHA = alpha;
		BETA = betta;
		TIME_OF_LIFE = q;
	}
private:
	int ALPHA = 0;
	int BETA = 0;
	int TIME_OF_LIFE = 0;
	const int Q = 100;
	const int RHO = 0.5;
	double probability(int to, AntWay ant, double** pheromone, double** distance, int vertex);
};

