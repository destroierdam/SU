#include"stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int i;
	char str[1024];
	cin >> str;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == 'T')
		{
			cout << "pozicia " << i + 1 << endl;
		}
	}
	return 0;
}
