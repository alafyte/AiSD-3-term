#include <iostream>
using namespace std;

//i - номер стержня, с которого перекладываем
//k - номер стержня, на который перекладываем
//n - количество дисков
//temp - вспомогательный (промежуточный стержень)

int counter = 0;

void HanoiTowers(int i, int k, int n)
{
    counter++;
    if (n == 1)
        cout << "Переместить диск 1 с " << i << " на " << k << " стержень." << endl;
    else 
    {
        /* 1 + 2 + 3 = 6
        i + k + temp = 6
        * => temp = 6 - i - k */

        int temp = 6 - i - k;
        HanoiTowers(i, temp, n - 1);
        cout << "Переместить диск " << n << " с " << i << " на " << k << " стержень." << endl;
        HanoiTowers(temp, k, n - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, k;

    while (true)
    {
        cout << "Введите число дисков: ";
        cin >> n;
        if (cin.get() != (int)'\n')
        {
            cout << "\n>>>>>>>>>>> Данные введены неверно, попробуйте ещё раз <<<<<<<<<<<" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        } 
        else if (n <= 0 || n > 1000)
        {
            cout << "\n>>>>>>>>>>> Данные введены неверно, попробуйте ещё раз <<<<<<<<<<<" << endl;
            continue;
        }
        cout << "\nВведите номер стрежня, на которые нужно переместить диски (2 или 3): ";
        cin >> k;
        if (cin.get() != (int)'\n')
        {
            cout << "\n>>>>>>>>>>> Данные введены неверно, попробуйте ещё раз <<<<<<<<<<<" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else if (k > 3 || k <= 1)
        {
            cout << "\n>>>>>>>>>>> Данные введены неверно, попробуйте ещё раз <<<<<<<<<<<" << endl;
            continue;
        }
        else
        {
            HanoiTowers(1, k, n);
            //cout << "Кол-во итераций: " << counter << endl;
            break;
        }
    }

    system("pause");
    return 0;
}