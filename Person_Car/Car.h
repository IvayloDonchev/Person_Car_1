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
	void Read();						//въвеждане от клавиатурата
	void Show();						//извеждане на екрана
private:
	char* model;			//модел
	char* regnum;			//регистрационен номер
	int year;				//година на производство
	Person owner;			//собственик (обект на Person)
};

