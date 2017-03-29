#pragma once
class Person
{
public:
	Person();							//default constructor
	Person(char*, int);					//constructor
	Person(const Person&);				//copy constructor
	Person(Person&&);					//move constructor
	Person& operator=(const Person&);	//copy assignment
	Person& operator=(Person&&);		//move assignment
	void Read();
	void Show();
	~Person();
private:
	char* name;
	int year;
};

