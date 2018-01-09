#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
int strSize(char *str)// ;)
{
	int i = 0;
	for (; str[++i];);  
	return i;
}
int main()
{
	char first[1024], second[1024], res[1024];
	cin >> first;
	cin >> second;
	for (int i = 0; i < 5; i++)
	{
		char temp = first[i];
		first[i] = second[i];
		second[i] = temp;
	}
	int firstSz = strSize(first);
	int secondSz = strSize(second);
	if (firstSz > secondSz)
	{
		cout << firstSz << " " << first;
	}
	else
	{
		cout << secondSz << " " << second;
	}
	cout << endl;
	return 0;
}
