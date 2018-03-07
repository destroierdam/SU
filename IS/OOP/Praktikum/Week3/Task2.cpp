// OOP Praktikum, Week 3, Task 2
#include"stdafx.h"
#include<iostream>
#include<fstream>
#include<cstring>
#define DEBUG 0
using namespace std;
int globsz;
int* reallocArr(int *&arr, int &sz)

{
	#if DEBUG
		cout << "REALLOCATING arrsz: "<< sz << endl;
	#endif // DEBUG

	

	int *newArr = new int[sz * 2];
	for (int i = 0; i < sz; i++)
	{
		#if DEBUG
			cout << i << ": ";
			cout << newArr[i] << " ";
		#endif // DEBUG
		
		newArr[i] = arr[i];

		#if DEBUG
		cout << newArr[i] << endl;
		#endif // DEBUG
		
		#if DEBUG
		cout << "Addresses of elements of newArr and arr: " << &newArr[i] << " " << &arr[i] << endl;
		#endif
	}

	sz *= 2;

	#if DEBUG
	cout << "before delete" << endl;
	#endif // DEBUG
	
	delete[] arr;
	
	#if DEBUG
	cout << "after delete" << endl;
	#endif // DEBUG


	#if DEBUG
	cout << "Addresses pointed by newArr and arr before assignment: " << newArr << " " << arr << endl;
	#endif

	arr = newArr;

	#if DEBUG
	cout << "Addresses pointed by newArr and arr after assignment: " << newArr << " " << arr << endl;
	#endif
	

	#if DEBUG
	cout << "REALLOC DONE" << endl;
	#endif // DEBUG

	
	return newArr;
}
int* readDynamicFromFile(const char *fileName)
{
	int i, sz = 4;
	int *arr = new int[sz];
	ifstream fin;
	fin.open(fileName, ios::in);
	for (i = 0; !fin.eof(); i++)
	{
		if (i == sz)
		{
			//arr = reallocArr(arr, sz);
			reallocArr(arr, sz);

			#if DEBUG
			cout << "Address of first element of arr: " << &arr[0] << endl;
			#endif

		}

		fin >> arr[i];
	}
	globsz = --i;
	fin.close();
	return arr;
}
void print(int *arr)
{
	for (int i = 0; i < globsz; i++)
	{
		cout << arr[i] << endl;
	}
}
int main()
{
	int *arr = readDynamicFromFile("input.txt");

	#if DEBUG 
	cout << endl << "-----------------------" << endl;
	print(arr);
	#endif // DEBUG

	delete[] arr;
	return 0;
}
/*

Да се напише функция, която прочита произволен брой числа от файл и ги записва в динамичен масив.
Масива да се връща като резултат от функцията.

*/
