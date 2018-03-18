#include"stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

// char car(const char* x), която връща първия символ (елемент) на низа x;
char car(const char* x)
{
	return *x;
}

// char* cdr(char* x), която връща останалата част от низа x след отделянето на първия елемент на низа x;
char* cdr(char* x)
{
	return (x + 1);
}

// char* cons(char x, const char* y), която връща указател към символен низ, разположен в динамичната памет,
// и съдържащ конкатенацията на символa x със символния низ y;
char* cons(char x, const char* y)
{
	int i, sz = strlen(y) + 2;
	char *str = new char[sz];
	for (i = 0; y[i]; i++)
	{
		str[i] = y[i];
	}
	str[i] = x;
	str[i + 1] = NULL;
	return str;
}

// bool eq(const char* x, const char* y), която връща true тогава и само тогава, когато низовете съвпадат.
bool eq(const char* x, const char* y)
{
	for (int i = 0; x[i] || y[i]; i++)
	{
		if (x[i] != y[i])
			return false;
	}
	return true;
}

// char* reverse(char* x), която връща указател към символен низ,
// разположен в динамичната памет и съдържащ символите на x, записани в обратен ред;
char* reverse(char* x)
{
	int i, sz = strlen(x) + 1;
	char *str = new char[sz];
	for (i = 0; i < sz - 1; i++)
	{
		str[i] = x[sz - i - 2];
	}
	str[i] = NULL;
	return str;
}

// char* copy(char* x), която връща указател към символен низ, 
// разположен в динамичната памет и съдържащ копие на символния низ x;
char* copy(char* x)
{
	int i, sz = strlen(x) + 1;
	char *str = new char[sz];
	for (i = 0; x[i]; i++)
	{
		str[i] = x[i];
	}
	str[i] = NULL;
	return str;
}

// char* car_n(char* x, int n), която връща указател към символен низ,
// разположен в динамичната памет и съдържащ първите n символа на символния низ x;
char* car_n(char* x, int n)
{
	char temp = x[n];

	x[n] = NULL;
	char *str = copy(x);
	x[n] = temp;

	return str;
}

// char* cdr_n(char* x, int n), която връща останалата част от низа x след отделянето на първите n символа.
// Предварително е известно, че x притежава поне n символа;
char* cdr_n(char* x, int n)
{
	return (x + n);
}

// int number_of_char( char* x, char ch), която намира колко пъти символът ch се среща в символния низ x;
int number_of_char(char* x, char ch)
{
	int i,sz = strlen(x)+1,br=0;

	for (i = 0; i < sz; i++)
	{
		if (x[i] == ch) br++;
	}
	return br;
}

// char* delete_substr(char* x, char* y), която връща указател към символен низ,
// разположен в динамичната памет и съдържащ символите на низа x,
// от който са изтрити всички срещания на символния низ y.
char* delete_substr(char* x, char* y)
{
	return NULL;
}
int main()
{
	char str[] = "abcdabcy";
	char txt[] = "abcxabcdabcdabcy";

	int ans = number_of_char(txt, 'z');
	cout << ans << endl;
	//delete[] str;
	return 0;
}
/*
Като се използват тези функции да се дефинират следните функции:


• char* delete_substr(char* x, char* y), която връща указател към символен низ,
разположен в динамичната памет и съдържащ символите на низа x,
от който са изтрити всички срещания на символния низ y.

*/
