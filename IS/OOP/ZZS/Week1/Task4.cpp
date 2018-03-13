#include"stdafx.h"
#include<iostream>
using namespace std;
struct Point
{
	double x;
	double y;
};
void copyPoint(Point* from, Point* to, int l, int r)
{
	int i;
	for (i = 0; i < r - l + 1; i++)
	{
		to[i] = from[l + i];
	}
}

// Returns whether the left element should go first
// Compares first by X, then by Y
int cmpXY(Point left, Point right)
{
	if (left.x < right.x) return 1;
	if (left.x > right.x) return 0;
	if (left.y < right.y) return 1;
	if (left.y > right.y) return 0;

	return 0; // Doesn't really matter. They are equal
}
void merge(Point arr[], int l, int m, int r)
{
	int i, j, k, szl = m - l + 1, szr = r - m;

	Point *left = new Point[szl];
	Point *right = new Point[szr];

	copyPoint(arr, left, l, m);
	copyPoint(arr, right, m + 1, r);
	

	for (i = 0, j = 0, k = l; i < szl && j < szr; k++)
	{
		if (cmpXY(left[i], right[j])) 
		{
			// left element should go first

			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
	}
	
	// copy the rest
	for (; i < szl; i++, k++)
	{
		arr[k] = left[i];
	}
	for (; j < szr; j++, k++)
	{
		arr[k] = right[j];
	}
	

	delete[] left;
	delete[] right;

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
