#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int br[256] = {0};
	char str[1024];
	cin.getline(str, 1024);
	for (int i = 0; str[i]; i++)
	{
		br[(int)str[i]]++;
	}
	for (int i = 0; i < 256; i++)
	{
		if (br[i])
		{
			cout << '\'' << (char)i << "\': "<< br[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
