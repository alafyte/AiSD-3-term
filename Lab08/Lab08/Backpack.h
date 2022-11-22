#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct Product
{
    string name;
    int cost;
    int weight;
};

int backpack(vector<Product> product, int numOfElements, int backpackCapacity);