#include "Person.h"
#include "Car.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	Person p1;
	p1.Read();
	p1.Show();
	Person p2(p1);
	p2.Show();
	Person p3;
	p3 = p1;
	p3.Show();
	p2 = move(p3); 
	p2.Show();
	cout << "p3: ";
	p3.Show();  //p3 вече го няма

	Car c1("Opel Astra", "BT 1234 TB", 1998, "Ivan Ivanov", 1990);
	Car c2("Opel Vectra", "CB 1111 CB", 1993, p2);
	c1.Show();
	c2.Show();
	Car c3(c1);
	c3.Show();
	c2 = c1;
	c2.Show();
	c2 = move(c1);
	c2.Show();
	c1.Show();

	Car c4;
	c4.Read();
	c4.Show();

	vector<Car> carVector{ Car("Opel Astra", "BT 1234 TB", 1998, "Ivan Ivanov", 1990),
		                   Car("Opel Vectra", "CB 4321 BC", 2010, "Petar Petrov", 1986),
	                       Car("Ford Fiesta", "BT 1111 BT", 1995, "Stefan Stefanov", 1956) };
	for (auto c : carVector)
		c.Show();

}