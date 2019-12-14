#include <iostream>
using namespace std;

#include "Polynomial.h"

int main()

{


	Polynomial p1;



	p1.changeCoefficient(1, 1);


	p1.changeCoefficient(4, 4);

	p1.changeCoefficient(2.2, 2);

	p1.changeCoefficient(-3.8, 3);

	cout << "p1 = " << p1 << endl;



	p1.changeCoefficient(0, 2);

	cout << "p1 = " << p1 << endl;



	Polynomial p2 = p1;

	p2.changeCoefficient(9.5, 2);

	cout << "p1 = " << p1 << endl;

	cout << "p2 = " << p2 << endl;

	cout << p2.degree() << endl;
	cout << p1.coefficient(3)<<endl;
	cout << p2.coefficient(2) << endl;

	//Polynomial p3; 
	//Polynomial p4;

	//p3.changeCoefficient(2, 2);
	//p4.changeCoefficient(2, 2);

	if (p1 == p2)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	Polynomial p3;
	p3.changeCoefficient(1, 1);
	p3.changeCoefficient(4, 4);
	p3.changeCoefficient(-3.8, 3);

	if (p3 == p1)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	if (p3 != p1)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	Polynomial p4;

	p4.changeCoefficient(6, 5);
	p4.changeCoefficient(6, 0);
	//p4.changeCoefficient(8, 7);
	//p4.changeCoefficient(3, 3);
	//p4.changeCoefficient(4, 4);


	cout << "p4 = " << p4 << endl;

	Polynomial p5;
	p5.changeCoefficient(2, 2);

	p4 = p5;
	//p5 = p4;

	cout << "p5 = " << p4 << endl;
	
}