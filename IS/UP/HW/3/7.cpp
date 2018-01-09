#include "stdafx.h"
#include <iostream>
using namespace std;
int pow(int x, int y)
{
	int k;
	if (y < 0)
	{
		cout << "1/";
		return pow(x, -y);
	}
	if (y == 0) return 1;
	if (y % 2 != 0) return x * pow(x, y - 1);
	k = pow(x, y / 2);
	return k * k;
}
int main()
{
	int x, y;
	cin >> x >> y;
	cout << pow(x, y) << endl;
	return 0;
}
