#include "stdafx.h"
#include <iostream>
using namespace std;
int countNum(char *str)
{
	int i, br = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			br++;
	}
	return br;
}
int countLower(char *str)
{
	int i, br = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 'a'&&str[i] <= 'z')
			br++;
	}
	return br;
}
int countUpper(char *str)
{
	int i, br = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
			br++;
	}
	return br;
}
int main()
{
	int n, p, i;
	char str[16];
	cin >> str;
	cout << "Numbers: " << countNum(str) << endl;
	cout << "Lower case characters: " << countLower(str) << endl;
	cout << "Upper case characters: " << countUpper(str) << endl;
	return 0;
}
