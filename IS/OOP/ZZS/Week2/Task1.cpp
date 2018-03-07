#include"stdafx.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class BankAccount
{
	char customerName[50];
	char iban[20];
	double balance;
public:
	BankAccount()
	{
		strcpy_s(customerName, sizeof("N/A"), "N/A");
		strcpy_s(iban, sizeof("N/A"), "N/A");
		balance = 0; 
	};
	void initBankAccount(BankAccount acc)
	{
		strcpy_s(customerName, sizeof(acc.customerName), acc.customerName);
		strcpy_s(iban, sizeof(acc.iban), acc.iban);
		balance = acc.balance;
	}
	BankAccount(char *_customerName, char *_iban, double _balance = 0)
	{
		strcpy_s(customerName, sizeof(_customerName), _customerName);
		strcpy_s(iban, sizeof(_iban), _iban);
		balance = _balance;

	}
	void showBankAccount()
	{
		cout << customerName << " " << iban << " " << balance << endl;
	}
	void deposit(double amount)
	{
		balance += amount;
	}
	void withdraw(double amount)
	{
		balance -= amount;
	}
	bool operator < (BankAccount rhs)
	{
		if (balance < rhs.balance) return true;
		return false;
	}
	bool operator <= (BankAccount rhs)
	{
		if (balance <= rhs.balance) return true;
		return false;
	}
	bool operator == (BankAccount rhs)
	{
		if (balance == rhs.balance) return true;
		return false;
	}
	bool operator > (BankAccount rhs)
	{
		if (balance > rhs.balance) return true;
		return false;
	}
	bool operator >= (BankAccount rhs)
	{
		if (balance >= rhs.balance) return true;
		return false;
	}

};
int main()
{
	BankAccount acc1, acc2;
	acc1.showBankAccount();
	acc1.deposit(420.69);
	acc2.withdraw(34.16);
	return 0;
}
/*

Да се дефинира клас BankAccount, определящ банкова сметка на клиент, състояща се от:
име на клиент (символен низ до 50 символа),
номер на банкова сметка (символен низ до 20 символа) и
налична сума на клиент (реално число).

Класът да притежава методи, чрез които може да:

• инициализира банкова сметка;
• извежда на екрана информация за банкова сметка;
• внася пари в банкова сметка;
• тегли пари от банкова сметка.

Да се дефинира оператор за сравнение на две сметки по сумите в тях.
Да се дефинира главна функция, която създава две банкови сметки,
извежда информацията в сметките, внася сума в една от сметките и
тегли сума от другата сметка.


*/
