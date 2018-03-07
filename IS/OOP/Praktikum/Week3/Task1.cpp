// Week 3; Task 1
#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
double average(int *arr, int n)
{
	double avg = 0;
	for (int i = 0; i < n; i++)
	{
		avg += arr[i];
	}
	avg /= n;
	return avg;
}
int minel(int *arr, int n)
{
	int ans;
	for (int i = 0; i < n; i++)
	{
		ans = min(ans, arr[i]);
	}
	return ans;
}
int maxel(int *arr, int n)
{
	int ans;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, arr[i]);
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << average(arr, n) << endl;
	cout << minel(arr, n) << endl;
	cout << maxel(arr, n) << endl;
	return 0;
}
/*

Да се напише програма, която пита потребителя за n на брой числа. 
Трябва да заделите динамично толкова на брой елементи(не повече!) колкото потребителя ще въведе. 
Напишете функции, които намират средното, най-малкия и най-големия елемент в този масив. 
Изпишете тези стойности на конзолата.

*/
