#include <climits>
#include "Backpack.h"

int max(int a, int b)
{
    return ((a > b) ? a : b);
};

int backpack(vector<Product> product, int numOfElements, int backpackCapacity)
{
    int** backpack = new int* [numOfElements + 1];

    for (unsigned int i = 0; i <= numOfElements; i++)
    {
        backpack[i] = new int[backpackCapacity + 1];
        for (unsigned int j = 0; j <= backpackCapacity; j++)
        {
            if (i == 0 || j == 0)
                backpack[i][j] = 0;
            else if (product[i - 1].weight <= j)
                backpack[i][j] = max((product[i - 1].cost + backpack[i - 1][j - product[i - 1].weight]), backpack[i - 1][j]);
            else
                backpack[i][j] = backpack[i - 1][j];
        }
    }


    int i = numOfElements;
    int j = backpackCapacity;

    cout << "\n--- Предмет - Цена ---\n";

    while (i > 0 && j >= 0)
    {
        if (backpack[i][j] != backpack[i - 1][j])
        {
            cout << product[i - 1].name << " - " << product[i - 1].cost << endl;
            j -= product[i - 1].weight;
        }
        i--;
    }

    return backpack[numOfElements][backpackCapacity];
}