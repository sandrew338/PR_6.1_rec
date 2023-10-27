#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
void OutputArray(int* arr, const int size, int i);
void FillArrayRandomVal(int* arr, const int size, int start, int end, int i);
void RewritingArray(int* arr, const int size, const int k1, const int k2, int& sum, int& quantity, int i);
int main()
{
	srand((unsigned)time(0));
	const int size_r = 25, start_random = 4, end_random = 73, k1 = 6, k2 = 5;
	int sum = 0, quantity = 0;
	int r[size_r];
	FillArrayRandomVal(r, size_r, start_random, end_random, 0);
	OutputArray(r, size_r, 0);
	RewritingArray(r, size_r, k1, k2, sum, quantity, 0);
	OutputArray(r, size_r, 0);
	cout << "sum = " << sum << "\nquantity = " << quantity << endl;
}
void FillArrayRandomVal(int* arr, const int size, int start, int end, int i)
{
	if (i < size)
	{
		arr[i] = start + rand() % (end - start);
		FillArrayRandomVal(arr, size, start, end, i + 1);
	}
}
void OutputArray(int* arr, const int size, int i)
{
	if (i < size)
	{
		cout << setw(4) << arr[i];
		OutputArray(arr, size, i + 1);
	}
	else
		cout << endl;
}
void RewritingArray(int* arr, const int size, const int k1, const int k2, int& sum, int& quantity, int i)
{
	if (i < size)
	{
		if (arr[i] % k1 == 0 || i % k2 != 0)
		{
			sum += arr[i];
			++quantity;
			arr[i] = 0;
		}
		RewritingArray(arr, size, k1, k2, sum, quantity, i + 1);
	}
}