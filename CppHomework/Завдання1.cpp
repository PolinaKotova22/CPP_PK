#include<iostream>
#include<Windows.h>
#include<iomanip>

#include"Func.h"

using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	SetColor(White, Black);
	system("cls");
	srand(time(0));


int M, N;

cout << "M: ";
cin >> M;

int* A = new int[M];
setArray(A, M);

SetColor(Blue, Black);
cout << "A: ";
printArray(A, M);

SetColor(White, Black);

cout << "N: ";
cin >> N;

int* B = new int[N];
setArray(B, N);

SetColor(Red, Black);
cout << "B: ";
printArray(B, N);

int* C = nullptr;
int sizeC = 0;

for (size_t i = 0; i < M; i++)
{
    if (findArray(B, N, A[i]) == -1 &&
        findArray(C, sizeC, A[i]) == -1)
    {
        addValueArray(C, sizeC, A[i]);
    }
}

SetColor(Green, Black);
cout << "C: ";
printArray(C, sizeC);

delete[] A;
delete[] B;
delete[] C;

return 0;
}