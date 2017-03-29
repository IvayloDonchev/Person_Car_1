#include "Car.h"
#include <iostream>

Car::Car() : model(nullptr), regnum(nullptr), year(0), owner()
{}

Car::Car(char *m, char *rn, int y, Person o) : 
	model(new char[strlen(m)+1]),
    regnum(new char[strlen(rn)+1]), 
	year(y), 
	owner(o)	//тук ще се изпълни копиращия конструктор на Person
{
	strcpy_s(model, strlen(m) + 1, m);
	strcpy_s(regnum, strlen(rn) + 1, rn);
}

Car::Car(char *m, char *rn, int cy, char *pn, int py) :
	model(new char[strlen(m) + 1]),
	regnum(new char[strlen(rn) + 1]), 
	year(cy),
	owner(pn,py)
{
	strcpy_s(model, strlen(m) + 1, m);
	strcpy_s(regnum, strlen(rn) + 1, rn);
}

Car::~Car()
{
	if (model) delete[] model;
	if (regnum) delete[] regnum;
}

Car::Car(const Car &other) : 
	model(new char[strlen(other.model)+1]),
	regnum(new char[strlen(other.regnum)+1]),
	year(other.year),
	owner(other.owner)	//тук ще се извика копиращия конструктор на Person
{
	strcpy_s(model, strlen(other.model) + 1, other.model);
	strcpy_s(regnum, strlen(other.regnum) + 1, other.regnum);
}

Car::Car(Car && other) : 
	model(std::move(other.model)),
	regnum(std::move(other.regnum)),
	year(std::move(other.year)),
	owner(std::move(other.owner))	//тук ще се извика move конструкторa на Person
{
	other.model = nullptr;
	other.regnum = nullptr;
	other.year = 0;
	other.owner = Person();
}

Car & Car::operator=(const Car &other)
{
	if (this == &other) return *this;
	size_t size = strlen(other.model)+1;
	if (model) delete[] model;
	model = new char[size];
	strcpy_s(model, size, other.model);
	size = strlen(other.regnum)+1;
	if (regnum) delete[] regnum;
	regnum = new char[size];
	strcpy_s(regnum, size, other.regnum);
	year = other.year;
	owner = other.owner;	//тук ще се изпълни копиращо присвояване на Person
	return *this;
}

Car & Car::operator=(Car &&other)
{
	if (this == &other) return *this;
	if (model) delete[] model;
	model = std::move(other.model);
	if (regnum) delete[] regnum;
	regnum = std::move(other.regnum);
	year = std::move(other.year);
	owner = std::move(other.owner); //тук ще се изпълни преместващото присвояване на Person
	other.model = nullptr;
	other.regnum = nullptr;
	other.year = 0;
	other.owner = Person();
	return *this;
}

void Car::Read()
{
	char s[45];
	std::cout << "Enter car model: ";
	std::cin.getline(s,45);
	if (model) delete[] model;
	size_t size = strlen(s) + 1;
	model = new char[size];
	strcpy_s(model, size, s);
	std::cout << "Enter registration number: ";
	std::cin.getline(s, 45);
	size = strlen(s) + 1;
	if (regnum) delete[] regnum;
	regnum = new char[size];
	strcpy_s(regnum, size, s);
	std::cout << "Enter year of production: ";
	std::cin >> year;
	std::cin.ignore();
	std::cout << "Enter owner: ";
	owner.Read();
}

void Car::Show()
{
	if (model)
	{
		std::cout << "................ Car Information ...............\n";
		std::cout << "Model: " << model << std::endl;
		std::cout << "Registration: " << regnum << std::endl;
		std::cout << "Year of production: " << year << std::endl;
		std::cout << "Owner: "; owner.Show();
	}
	else
		std::cout << "Empty object\n";
}
