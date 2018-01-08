#include "stdafx.h"
#include <iostream>
using namespace std;
int bin(int n)
{
	if (n<0)
	{
		cout << '-';
		return bin(-n);
	}
	if (n)
		return n % 2 + bin(n / 2) * 10;
	else
		return 0;
}
int main()
{
	int n;
	cin >> n;
	cout << bin(n) << endl;
	return 0;
}
