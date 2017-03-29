#pragma once
#include "Person.h"
class Car
{
public:
	Car();								//defult constructor
	Car(char*, char*, int, Person);		//constructor
	Car(char*, char*, int, char*, int);	//constructor
	~Car();								//destructor
	Car(const Car&);					//copy constructor
	Car(Car&&);							//move constructor
	Car& operator=(const Car&);			//copy assignment
	Car& operator=(Car&&);				//move assignment
	void Read();
	void Show();
private:
	char* model;
	char* regnum;
	int year;
	Person owner;
};

