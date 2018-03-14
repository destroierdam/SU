#include"stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;
void reallocStr(char* &str, int& sz)
{
	char* newStr = new char[sz * 2];
	int i;
	for (i = 0; i < sz; i++)
	{
		newStr[i] = str[i];
	}
	sz *= 2;
	newStr[i] = NULL;
	delete[] str;
	str = newStr;
}
int readFile(char* nameOfFile)
{
	int i, sz = 1,br=0;
	char c;
	char* str = new char[sz];
	ifstream input;
	input.open(nameOfFile, ios::in);
	for (i = 0; !input.eof(); i++)
	{
		if (i == sz - 1)
		{
			//cout << str + i << " ";
			reallocStr(str, sz);
			//cout << &(str[i]) << endl;
		}
		input.get(str[i]);
		switch (str[i])
		{
		case '.':
		case '!':
		case '?':
			br++;
		}
	}
	str[i] = NULL;
	return br;
}
class Person
{
	char* name;
public:
	Person(const char *name)
	{
		// strcpy_s(this->name, sizeof(name),name);

		char *newName = new char[strlen(name) + 1];

		strcpy_s(this->name, sizeof(name), name);

		/*
		for(int i=0;name[i];i++)
		{
			newName[i]=name[i];
		}
		newName[i] = NULL;
		*/
	}
};

int main()
{
	char nameOfFile[128] = "in.txt";
	cin >> nameOfFile;
	int content = readFile(nameOfFile);

	cout << content << endl;
	/*
	cout << "#";
	for (int i = 0; content[i]; i++)
	{
		cout << content[i];
	}
	cout << "#" << endl;
	*/
	return 0;
}
/*

Да се напише функция, която прочита текст от файл и
го записва в символен низ динамичен размер.
Функцията трябва да връща броят на изреченията в текста.

*/
