#include"stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;
void reduce(char* str, char* ans, int* used, int &pos)
{
	int i;
	for (i = 0; str[i]; i++)
	{
		if (used[(int)str[i]] == 0)
		{
			ans[pos] = str[i];
			used[(int)str[i]] = 1;
			pos++;
		}
	}
}
char* unify(char* str1, char* str2)
{
	int i, pos = 0;
	int used[512] = { 0 };
	int sz = strlen(str1) + strlen(str2) + 2;
	char *ans = new char[sz];

	reduce(str1, ans, used, pos);
	reduce(str2, ans, used, pos);

	ans[pos] = NULL;
	return ans;
}
int main()
{
	char str[20] = "Hello";
	char str2[20] = "World";

	char* ans = unify(str, str2);

	cout << ans << endl;
	delete[] ans;
	return 0;
}

/*

Обединение на два символни низа s1 и s2 наричаме
всеки символен низ, който съдържа без повторение всички символи на s1 и s2.
Да се дефинира функция, която намира и връща обединението на два символни низа.

*/
