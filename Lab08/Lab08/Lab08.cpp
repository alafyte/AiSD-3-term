#include <iostream>
#include <Windows.h>
#include "Backpack.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // вместимость рюкзака
    int W;

    while (true)
    {
        cout << "Введите N (вместимость рюкзака): ";
        cin >> W;
        if (cin.get() != (int)'\n')
        {
            cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else if (W <= 0)
        {
            cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
            cin.clear();
            continue;
        }
        else
            break;
    }

    vector<Product> products;

    while (true)
    {
        int option;
        string name;
        int cost = 0, weight = 0;
        cout << "Введите опцию: " << endl;
        cout << "1 - ввести товар" << endl;
        cout << "другое число - выход" << endl;
        cin >> option;
        if (cin.get() != (int)'\n')
        {
            cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else if (option <= 0)
        {
            cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
            cin.clear();
            continue;
        }
        else if (option == 1)
        {
            cout << "Название: ";
            cin >> name;
            while (true)
            {
                cout << "\nСтоимость: ";
                cin >> cost;

                if (cin.get() != (int)'\n')
                {
                    cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    continue;
                }
                else if (cost <= 0)
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
                cout << "\nВес: ";
                cin >> weight;

                if (cin.get() != (int)'\n')
                {
                    cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    continue;
                }
                else if (weight <= 0)
                {
                    cout << "\n---------- Данные введены неверно, попробуйте ещё раз --------------" << endl;
                    cin.clear();
                    continue;
                }
                else
                    break;

            }
            products.push_back({name, cost, weight});
        }
        else if (products.size() == 0)
        {
            cout << "\n---------- Введите хотя бы один предмет --------------" << endl;
            cin.clear();
            continue;
        }
        else
            break;
    }

   /* vector<Product> products = {
        {"Алмаз", 30, 6}, {"Часы", 14, 3}, {"Телевизор", 16, 4}, {"Картина", 9, 2}
    };*/
   
    int n = products.size();
    cout << "Стоимость предметов в рюкзаке: " << backpack(products, n - 1, W);

    return 0;
}