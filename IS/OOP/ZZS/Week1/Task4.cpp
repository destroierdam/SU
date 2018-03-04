#include"stdafx.h"
#include<iostream>
using namespace std;
struct Point
{
	double x;
	double y;
};
void merge(Point arr[], int l, int m, int r)
{
	int i = 0, j = 0, k = l;
	int szl = m - l + 1;
	int szr = r - m;

	Point left[5], right[5];

	for (i = 0; i < szl; i++)
	{
		left[i] = arr[l + i];
	}

	for (j = 0; j < szr; j++)
	{
		right[j] = arr[m + 1 + j];
	}

	for (i = 0, j = 0, k = l; i < szl && j < szr; k++)
	{
		if (left[i].x < right[j].x)
		{
			arr[k] = left[i];
			i++;
		}
		else if (left[i].x == right[j].x)
		{
			if (left[i].y <= right[j].y)
			{
				arr[k] = left[i];
				i++;
			}
			else
			{
				arr[k] = right[j];
				j++;
			}
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
	}

	for (; i < szl; i++, k++)
	{
		arr[k] = left[i];
	}
	for (; j < szr; j++, k++)
	{
		arr[k] = right[j];
	}
}
void mergeSort(Point arr[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
void print(Point *arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i].x << " " << arr[i].y << endl;
	}
}
int main()
{
	Point arr[7] = { {1,1},{1,2},{2,2},{2,1},{3,4},{2,5} ,{1,1} };

	mergeSort(arr, 0, 6);

	print(arr, 7);
	return 0;
}
/*

Да се дефинира функция, която сортира лексикографски във въз-
ходящ ред редица от точки в равнината. За целта да се дефинира
структура Point, описваща точка от равнината с декартови коор-
динати.

*/
