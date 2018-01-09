#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char c;
	for (c = 'A'; c <= 'Z'; c++)
	{
		cout << "Bukvata: " << c << " ima ASCII kod: " << (int)c;
		if ((c - 'A') % 2 == 0)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}
