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
	int i, sz = 1, br = 0;
	char c;
	char* str = new char[sz];
	ifstream input;
	input.open(nameOfFile, ios::in);
	for (i = 0; !input.eof(); i++)
	{
		if (i == sz - 1)
		{
			cout << str + i << " ";
			reallocStr(str, sz);
			cout << &(str[i]) << endl;
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
	int age;
	char* name;
public:
	Person()
	{
		age = 0;
	}
	Person(const char *_name, int _age = -1)
	{
		int i;
		char *newName = new char[strlen(_name) + 1];

		for (i = 0; _name[i]; i++)
		{
			newName[i] = _name[i];
		}
		newName[i] = NULL;

		name = newName;

		if (_age != -1)
		{
			age = _age;
		}
	}
	void operator = (Person& toBeCopied)
	{
		int i;
		age = toBeCopied.age;
		for(i=0;toBeCopied.name[])
	}
	void print()
	{
		cout << name << " " << age << endl;
	}
	~Person()
	{
		delete[] name;
	}
};

int main()
{
	char nameOfFile[128] = "in.txt";
	//cin >> nameOfFile;
	//int content = readFile(nameOfFile);

	Person first("asd",12);
	Person second = "fgh";

	first.print();
	second.print();

	second = first;

	first.print();
	second.print();
	return 0;
}
/*

Да се направи клас Person, който в себе си има полета за име и години. Нека този клас има реализирани:

конструктор по подразбиране
конструктор с параметри
деструктор
get-ъри и set-ъри
функция, която принтира информацията на човека

*/
