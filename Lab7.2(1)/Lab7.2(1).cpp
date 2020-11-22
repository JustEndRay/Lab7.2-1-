#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void Search(int** a, const int n);
int main()
{
	srand((unsigned)time(NULL));
	int Low  =  -14;
	int High = 27;
	int n;
	cout << "n = ";cin >> n;
	int**a = new int*[n];
	for(int i=0; i<n; i++) a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	Search(a, n);
	Print(a, n);
	for(int i=0; i<n; i++)delete[] a[i];
	delete[] a;
	return 0;
}void Create(int** a, const int n, const int Low, const int High)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)a[i][j] = Low + rand() % (High-Low+1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)cout << setw(4) << a[i][j];
	cout << endl;
	}
	cout << endl;
}
void Search(int** a, const int n)
{
	int max = -15;
	int j = 0;
	for (int i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++)
		{
			if ((i + 1) % 2 == 0)
			{
				if (a[i][j] > max) { max = a[i][j]; }
			}
			else{max = -20;}
		}
		if (max != -20)
		{
			swap(a[i][i], max);
			max = 0;
		}
	}
}