#include"stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;
struct Person
{
	char firstName[64];
	char lastName[64];
};
struct Client
{
	Person names;
	char iban[256];
	double balance;
};
void readClientFile(const char *fileName, Client *arr, int arrsz)
{
	ifstream fin;
	fin.open(fileName, ios::in);
	if (fin.is_open())
	{
		for (int i = 0; i < arrsz; i++)
		{
			fin >> arr[i].names.firstName >> arr[i].names.lastName >> arr[i].iban;
		}
		fin.close();
	}
}
void showClient(Client obj)
{
	cout << obj.names.firstName << " " << obj.names.lastName << " " << obj.iban << endl;
}
void showClientArr(Client *arr, int sz)
{
	for (int i = 0; i < 5; i++)
	{
		showClient(arr[i]);
		cout << endl;
	}
}
double DebtsTotal(Client *arr, int arrsz)
{
	double debts = 0;
	for (int i = 0; i < arrsz; i++)
	{
		if (arr[i].balance < 0)
			debts += arr[i].balance;
	}
	return debts;
}
int main()
{
	// (а) Въвежда от файл имената и банковите сметки на едномерен масив от клиенти. 
	//     Размерът на масива е фиксиран на 5, като във файла има данни за 5 клиента;

	Client clients[5];
	readClientFile("clients.txt", clients, 5);

	// (б) извежда на екрана имената и банковите сметки на клиентите от масива;
	showClientArr(clients, 5);


	// (в) намира сумата от задълженията на клиентите от масива.
	double debts = DebtsTotal(clients, 5);

	return 0;
}
/*

Да се дефинират структурите: Person, определяща лице по собстве-
но име и фамилия и Client, определяща клиент като лице (Person),
притежаващо банкова сметка с дадена сума.
Да се дефинират функции, които въвеждат и извеждат данни за
лице и клиент. Да се напише програма, която:

*/
