#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<conio.h>

#include"myFunc.h"

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    cout.setf(ios::boolalpha);
    SetColor(White, Black);
    system("cls");
    srand(time(0));

    const int row = 3;
    const int col = 4;

    int a[row][col];

    int x;

    cout << "Введіть число: ";
    cin >> x;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            a[i][j] = x;
            x++;
        }
    }

    cout << " " << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}