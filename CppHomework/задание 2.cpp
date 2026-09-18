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

#include<iostream>

    using namespace std;

    void Fill(int* a, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }
    }

    void Print(int* a, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    int main()
    {
        int M, N;

        cout << "M = ";
        cin >> M;

        cout << "N = ";
        cin >> N;

        int* A = new int[M];
        int* B = new int[N];
        int* C = new int[M];

        cout << "A:" << endl;
        Fill(A, M);

        cout << "B:" << endl;
        Fill(B, N);

        int k = 0;

        for (int i = 0; i < M; i++)
        {
            bool inB = false;

            for (int j = 0; j < N; j++)
            {
                if (A[i] == B[j])
                {
                    inB = true;
                }
            }

            bool repeat = false;

            for (int j = 0; j < k; j++)
            {
                if (A[i] == C[j])
                {
                    repeat = true;
                }
            }

            if (!inB && !repeat)
            {
                C[k] = A[i];
                k++;
            }
        }

        cout << "Result:" << endl;
        Print(C, k);

        delete[] A;
        delete[] B;
        delete[] C;

        return 0;
    }