#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>

using namespace std;

//double rand_x() {
//	double plus = 0.0000002;
//	double minus = -plus;
//	int des = (rand() % 2);
//	if (des == 0) {
//		return plus;
//	}
//	else {
//		return minus;
//	}
//}
//
//void main() {
//	int S = 134862;
//	double *matr_X = new double[S];
//	ifstream X;
//	fstream X_2;
//	X.open("true_X_01.dat");
//	X_2.open("X_1_ANSWER.dat");
//	for (int i = 0; i < S; ++i) {
//		cout << i + 1 << " / " << S << endl;
//		X >> matr_X[i];
//		X_2 << matr_X[i] + rand_x() << endl;
//	}
//	X.close();
//	X_2.close();
//	system("pause");
//}

int main(int argc, char** argv)
{
	int i, j, k;
	int Ai[5][5] = { { 0,1,0,1,0 },{ 1,0,0,0,0 },{ 1,1,1,0,1 },{ 1,1,0,1,1 },{ 1,1,0,0,0 } };
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
			printf("%i", Ai[i][j]);
		printf("\n");
	}
	cout << endl;
	//==========СОСТАВЛЕНИЕ РАБОЧЕЙ МАТРИЦЫ А========

	//размерность матрицы
	int n = 5;
	//рабочая матрица
	int A[5][10];
	//копируем исходную в рабочую
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			A[i][j] = Ai[i][j];
	//прибавляем единичную матрицу
	for (i = 0; i < n; i++)
		for (j = n; j < 2 * n; j++)
		{
			if (i + n == j)
				A[i][j] = 1;
			else
				A[i][j] = 0;
		}

	//==========МЕТОД ГАУССА ДЛЯ МАТРИЦЫ В=========	

	for (i = 0; i < n; i++)
	{
		if (A[i][i] == 0)
			for (j = i + 1; j < n; j++)
			{
				if (A[j][i] == 1)
				{
					for (k = 0; k < 2 * n; k++)
					{
						int c = A[j][k];
						A[j][k] = A[i][k];
						A[i][k] = c;
					}
					break;
				}
			}
		for (k = i + 1; k < n; k++)
		{
			if (A[k][i] == 1)
			{
				for (j = 0; j < 2 * n; j++)
				{
					A[k][j] ^= A[i][j];
				}
			}
		}
	}
	for (i = n - 1; i >= 0; i--)
	{
		for (k = i - 1; k >= 0; k--)
		{
			if (A[k][i] == 1)
			{
				for (j = 0; j < 2 * n; j++)
					A[k][j] ^= A[i][j];
			}
		}
	}

	//обратная матрица
	int B[5][5];

	//копируем в обратную матрицу В
	for (i = 0; i < n; i++)
		for (j = 0, k = n; j < n; j++, k++)
			B[i][j] = A[i][k];
	//Выводим на экран обратную матрицу
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%i", B[i][j]);
		printf("\n");
	}
	system("pause");
}