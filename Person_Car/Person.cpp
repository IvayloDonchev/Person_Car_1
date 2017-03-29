#include "Person.h"
#include <cstring>
#include <iostream>

Person::Person() : name(nullptr), year(0) {}

Person::Person(char *n, int y) : name(new char[strlen(n)+1]), year(y)
{
	strcpy_s(name, strlen(n) + 1, n);
}

Person::Person(const Person &other) : name(new char[strlen(other.name)+1]), 
                                      year(other.year)
{
	strcpy_s(name, strlen(other.name) + 1, other.name);
}

Person::Person(Person && other) : name(std::move(other.name)),
                                  year(std::move(other.year))
{
	other.name = nullptr;
	other.year = 0;
}

Person & Person::operator=(const Person &other)
{
	if (this == &other) return *this;
	if (name) delete[] name;
	size_t size = strlen(other.name) + 1;
	name = new char[size];
	strcpy_s(name, size, other.name);
	year = other.year;
	return *this;
}

Person & Person::operator=(Person && other)
{
	if (this == &other) return *this;
	if (name) delete[] name;
	name = std::move(other.name);
	year = std::move(other.year);
	other.name = nullptr;
	other.year = 0;
	return *this;
}

void Person::Read()
{
	if (name)
		delete[] name;
	char s[25];
	std::cout << "Enter the name of person: ";
	std::cin.getline(s,25);
	size_t size = strlen(s) + 1;
	name = new char[size];
	strcpy_s(name, size, s);
	std::cout << "Enter the year of birth: ";
	std::cin >> year;
	std::cin.ignore();
}

void Person::Show()
{
	if (name)
		std::cout << name << ", " << year << std::endl;
	else
		std::cout << "Empty object\n";
}

Person::~Person()
{
	if (name)
		delete[] name;
}
