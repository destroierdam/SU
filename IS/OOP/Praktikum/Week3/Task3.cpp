#include"stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;
void mystrcpy(char* dest, const char* src)
{
	int i;
	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = NULL;
}
int main()
{
	/* Driver
	char destination[32];
	const char source[32]="This is a string.";
	mystrcpy(destination, source);

	cout << destination << endl;

	*/
	return 0;
}
/*

Напишете имплементация на strcpy(char* dest, const char* src) функцията.

*/
