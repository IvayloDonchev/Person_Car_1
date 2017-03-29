#include "Person.h"
#include "Car.h"
#include <iostream>
using namespace std;

int main()
{
	Person p;
	p.Read();
	p.Show();
	Person p2(p);
	p2.Show();
	Person p3;
	p3 = p;
	p3.Show();
	p2 = move(p3);
	p2.Show();
	cout << "p3: ";
	p3.Show();

	Car c1("Opel Astra", "BT 1234 TB", 1998, "Ivan Ivanov", 1990);
	Car c2("Opel Astra", "BT 1234 TB", 1998, p2);
	c1.Show();
	c2.Show();
	Car c3(c1);
	c3.Show();
	c2 = c1;
	c2.Show();
	c2 = move(c1);
	c2.Show();
	c1.Show();


}