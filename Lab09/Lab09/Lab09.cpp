#include "GeneticAlgotithm.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int populatonSize, numberOfEvolutions;

    while (true)
    {
        cout << "Введите размер популяции: ";
        cin >> populatonSize;

        if (cin.get() != (int)'\n')
        {
            cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else if (populatonSize <= 0)
        {
            cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
            cin.clear();
            continue;
        }
        else
            break;
    }

    while (true)
    {
        cout << "Введите кол-во эволюций: ";
        cin >> numberOfEvolutions;

        if (cin.get() != (int)'\n')
        {
            cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else if (numberOfEvolutions <= 0)
        {
            cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
            cin.clear();
            continue;
        }
        else
            break;
    }

    GeneticAlgorithm ga(populatonSize, numberOfEvolutions);
    ga.Solve();
}