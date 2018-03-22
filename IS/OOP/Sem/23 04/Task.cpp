#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
void mystrcpy(char* dest, const char *from)
{
	size_t i;
	for (i = 0; from[i]; i++)
	{
		dest[i] = from[i];
	}
	dest[i] == NULL;
}
class Book
{
	char heading[128];
	char author[128];
	char* description;
	void copy(const Book& from)
	{
		description = new char[strlen(from.description) + 1]; 

		mystrcpy(description, from.description);

		mystrcpy(heading, from.heading);

		mystrcpy(author, from.author);
	}

public:
	Book()
	{
		heading[0] = author[0] = NULL;
		description = nullptr;
	}
	Book(const Book& other)
	{	
		copy(other);
	}
	Book& operator = (const Book& other)
	{
		delete[] description;
		
		copy(other);
	}
	~Book()
	{
		delete[] description;
	}

	const char* getHeading() const
	{
		return heading;
	}
	const char* getAuthor() const
	{
		return author;
	}
	const char* getDescription() const
	{
		return description;
	}

	void setHeading(const char* newHeading)
	{
		mystrcpy(heading, newHeading);
	}
	void setAuthor(const char* newAuthor)
	{
		mystrcpy(author, newAuthor);
	}
	void setDescription(const char* newDescription)
	{
		if (description != nullptr)
		{
			delete[] description;
			description = new char[strlen(newDescription) + 1];

			mystrcpy(description, newDescription);
		}
	}
};
class Library
{
	char name[128];
	Book* bookArr;
	size_t bookArrsz;
	void copy(const Library& other)
	{
		mystrcpy(name, other.name);

		bookArr = new Book[other.bookArrsz];
		bookArrsz = other.bookArrsz;

		size_t i;
		for (i = 0; i < bookArrsz; i++)
		{
			bookArr[i] = other.bookArr[i];
		}
	}
public:
	Library()
	{
		name[0] = NULL;
		bookArr = nullptr;
		bookArrsz = 0;
	}
	Library(const Library& other)
	{
		copy(other);
	}
	Book& operator [] (size_t idx)
	{
		return bookArr[idx];
	}
	Library& operator [] (char*)
	{
		;
	}
	~Library()
	{
		delete[] bookArr;
	}
	void addBook()
	{
		;
	}
};
int main()
{
	
	return 0;
}
