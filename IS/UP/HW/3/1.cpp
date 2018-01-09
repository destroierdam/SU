#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char c;
	cin >> c;
	cout << (char)(c - 'a' + 'A') << endl;;
	return 0;
}
