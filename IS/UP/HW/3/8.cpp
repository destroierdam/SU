#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
int strSize(char *str)
{
	if (str[0] == '\0')
		return 0;
	return 1 + strSize(str+1);
}
int main()
{
	char str[1024];
	cin >> str;
	cout << strSize(str) << endl;
	return 0;
}
