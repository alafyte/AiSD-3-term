#pragma once
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

//Число городов
#define NUM_OF_CITIES 8

//Особь
struct individual
{
    string gnome;
    int fitness;
};
//Потомки
struct children
{
    string child1;
    string child2;
};
bool lessthan(individual, individual);

class GeneticAlgorithm
{
public:
    int POP_SIZE = 0;
    int EVOL_NUM = 0;
    int m = INT_MAX;
    int map[NUM_OF_CITIES][NUM_OF_CITIES] = { 
                    { 0,  50, 60, m,  20, 30, 10, 70 },
                    { 50, 0,  10, 90, 70, 20, 35, 10 },
                    { 60, 10, 0,  20, 70, 40, 30, 70 },
                    { m,  90, 20, 0,  20, 70, 80, 25 },
                    { 20, 70, 70, 20, 0,  60, 70, m  },
                    { 30, 20, 40, 70, 60, 0,  20, 70 },
                    { 10, 35, 30, 80, 70, 20, 0,  40 },
                    { 70, 10, 70, 25, m,  70, 40, 0  }
    };
    void Solve();

    GeneticAlgorithm(int size, int evolNum)
    {
        POP_SIZE = size;
        EVOL_NUM = evolNum;
    }

private:
    vector<individual> paths;
    int randNum(int, int);
    bool repeat(string, char);
    string mutatedGene(string);
    children crossover(string, string);
    string createGnome();
    int calculatePath(string);
    individual findMinPath(vector<individual>);
};