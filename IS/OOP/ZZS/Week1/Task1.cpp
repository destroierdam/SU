#include"stdafx.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct Product
{
	char description[32];
	//описание на изделие
	int partNum;
	//номер на изделие
	double cost;
	//цена на изделие
};
void initProductArray(Product *items)
{
	strcpy_s(items[0].description, sizeof("screw driver"), "screw driver");
	items[0].partNum = 456;
	items[0].cost = 5.50;
	strcpy_s(items[1].description, sizeof("hammer"), "hammer");
	items[1].partNum = 324;
	items[1].cost = 8.20;
	strcpy_s(items[2].description, sizeof("socket"), "socket");
	items[2].partNum = 777;
	items[2].cost = 6.80;
	strcpy_s(items[3].description, sizeof("plier"), "plier");
	items[3].partNum = 123;
	items[3].cost = 10.80;
	strcpy_s(items[4].description, sizeof("hand-saw"), "hand-saw");
	items[4].partNum = 555;
	items[4].cost = 12.80;
}
void showProduct(Product work)
{
	cout << "Description: " << work.description << endl;
	cout << "Part number: " << work.partNum << endl;
	cout << "Cost: " << work.cost << endl;
}
void arrayToFile(const char *fileName, Product *p, int sz, bool withDescriptions = false)
{
	ofstream out;
	out.open(fileName, ios::out);
	if (out.is_open())
	{
		for (int i = 0; i < sz; i++)
		{
			if (withDescriptions) out << "Description: ";
			out << p[i].description << endl;

			if (withDescriptions) out << "Part number: ";
			out << p[i].partNum << endl;

			if (withDescriptions) out << "Cost: ";
			out << p[i].cost << endl;
		}
	}
	out.close();
}
void fileToArray(const char *fileName, Product *p, int sz)
{
	char buff[32] = "";
	ifstream in;
	in.open(fileName, ios::in);
	if (in.is_open())
	{
		for (int i = 0; i < sz; i++)
		{
			in.getline(buff, 32);
			strcpy_s(p[i].description, sizeof(buff), buff);

			in >> p[i].partNum;
			in >> p[i].cost;

			strcpy_s(buff, sizeof(""), "");

			char removeNewLine;
			in.get(removeNewLine);
		}
		in.close();
	}
}

// Returns -1 if left is greater, 0 when equal, 1 if right is greater. By description, partnum and cost
int ProductCmp(Product p1, Product p2)
{
	int strcmpres = strcmp(p1.description, p2.description);
	if (strcmpres) return strcmpres;
	if (p1.partNum < p2.partNum) return -1;
	if (p1.partNum > p2.partNum) return 1;
	if (p1.cost < p2.cost) return -1;
	if (p1.cost > p2.cost) return 1;
	return 0;
}

// Returns -1 if left is greater, 0 when equal, 1 if right is greater. By description, partnum and cost
int ProductArrCmp(Product *p1, Product *p2, int szp1, int szp2)
{
	for (int i = 0; i < szp1&&i < szp2; i++)
	{
		int res = ProductCmp(p1[i], p2[i]);
		if (res)
		{
			return res;
		}
	}
	if (szp1 < szp2) return -1;
	if (szp1 > szp2) return 1;
	return 0;
}
int main()
{
	Product p1, p2;

	// (а) Да се създадат две изделия и се инициализират чрез следните данни:
	// p1 Init
	strcpy_s(p1.description, sizeof("screw driver"), "screw driver");
	p1.partNum = 456;
	p1.cost = 5.50;

	// p2 Init
	strcpy_s(p2.description, sizeof("hammer"), "hammer");
	p2.partNum = 234;
	p2.cost = 8.20;

	// (б) Да се изведат на екрана компонентите на двете изделия
	showProduct(p1);
	showProduct(p2);

	// (в) Да се дефинира масив от 5 структури Product. Елементите на масива да не се инициализират;
	Product items[5];

	//(г) Да се реализира цикъл, който инициализира масива чрез нулевите за съответния тип на полетата стойности;
	for (int i = 0; i < 5; i++)
	{
		strcpy_s(items[i].description, sizeof(""), "");
		items[i].cost = 0;
		items[i].partNum = 0;
	}

	// (д) Да се променят елементите на масива така, че да съдържат следните стойности :
	/*
	description		partNum		cost
	--------------------------------
	screw driver	456			5.50
	hammer			324			8.20
	socket			777			6.80
	plier			123			10.80
	hand - saw		555			12.80
	*/
	initProductArray(items);

	// (е) Да се изведат елементите на масива на конзолата с подходящо форматиране;
	for (int i = 0; i < 5; i++)
	{
		showProduct(items[i]);
		std::cout << endl;
	}

	// (ж) Да се изведат елементите на масива в текстов файл;
	arrayToFile("out file.txt", items, 5);

	// (з) Да се дефинира втори масив и неговите елементи да се инициализират 
	//     чрез прочитане на записаните от предната точка данни в съответния файл;

	

	Product arr2[5];

	fileToArray("out file.txt", arr2, 5);

	// (и) Да се изведат на конзолата елементите на втория масив и да се сравнят с елементите на първия.

	cout << "--------------------------" << endl; // For clarity

	for (int i = 0; i < 5; i++)
	{
		showProduct(arr2[i]); 
		cout << endl;
	}


	int res = ProductArrCmp(items, arr2, 5, 5);
	cout << res << endl;
	return 0;
}
