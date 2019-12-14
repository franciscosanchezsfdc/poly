// polynomial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Polynomial.h"
using namespace std;


Polynomial::Polynomial()
{
	head = new Term;
	head->coeff = 0;
	head->power = 0;
	size = 0;
	head->next = NULL;
	head->prev = NULL;
}

Polynomial::Polynomial(const Polynomial& p) :Polynomial()
{
	Term* curr = p.head->next;
	Term* t;
	Term* tempPrev = head;
	if (p.head->next == NULL && p.head->prev == NULL)
	{
		return;
	}
	else
	{
		while (curr != p.head)
		{
			t = new Term();
			t->coeff = curr->coeff;
			t->power = curr->power;
			t->next = head;
			t->prev = tempPrev;
			tempPrev->next = t;
			head->prev = t;

			tempPrev = t;
			curr = curr->next;
		}
	}

}

Polynomial::~Polynomial()
{

};

int Polynomial::degree() const
{

	Term* temp = head->next;
	return temp->power;
}

double Polynomial::coefficient(const int power) const
{

	Term* currTerm = head->next;

	while (currTerm != head)
	{
		if (currTerm->power == power)
		{
			return currTerm->coeff;
			break;
		}
		currTerm = currTerm->next;
	}
	return 0;
}

bool Polynomial::changeCoefficient(const double newCoefficient, const int power)
{
	if (power < 0)
	{
		return false;
	}
	Term* curr = head->next;

	if (curr == NULL)
	{
		return insert(head, newCoefficient, power);
	}
	while (curr != head)
	{
		if (curr->power == power)
		{
			curr->coeff = newCoefficient;
			if (newCoefficient == 0) {
				return remove(curr);
			}
			return true;
		}
		else if (power > curr->power)
		{
			return insert(curr, newCoefficient, power);
		}
		else {
			curr = curr->next;
			if (curr == head)
			{
				return insert(head, newCoefficient, power);
			}
		}
	}
	return false;
}

Polynomial Polynomial::operator+(const Polynomial& p) const
{
	Polynomial temp = *this;
	temp += p;
	return temp;
}

bool Polynomial::operator==(const Polynomial& p) const
{
	Term* curr = head->next;
	Term* pCurr = p.head->next;

	while (curr != head)
	{
		if (curr->coeff != pCurr->coeff || curr->power != pCurr->power)
		{
			return false;
		}
		curr = curr->next;
		pCurr = pCurr->next;

	}
	return true;
}

bool Polynomial::operator!=(const Polynomial& p) const
{
	Term* curr = head->next;
	Term* pCurr = p.head->next;

	while (curr != head)
	{
		if (curr->coeff == pCurr->coeff && curr->power == pCurr->power)
		{
			return false;
		}
		curr = curr->next;
		pCurr = pCurr->next;

	}
	return true;
}

Polynomial& Polynomial::operator=(const Polynomial& p)
{

	Term* curr = head->next;
	Term* otherCurr = p.head->next;
	Term* tempPrev = head;
	if (*this == p)
	{
		return *this;
	}
	while (curr != head)
	//while (curr != head)
	{
		Term* next = curr->next;
		remove(curr);
		curr = next;
	}
	while (otherCurr != p.head)
	{
		Term* temp = new Term;
		temp->coeff = otherCurr->coeff;
		temp->power = otherCurr->power;
		temp->next = head;

		temp->prev = tempPrev;
		tempPrev->next = temp;
		head->prev = temp;

		tempPrev = temp;
		otherCurr = otherCurr->next;
	}
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& p)
{
	Term* curr = head->next;
	Term* pCurr = p.head->next;

	if (head->next == NULL && head->prev == NULL)
	{
		*this = p;
		return *this;
	}
	while (pCurr != p.head)
	{
		if (curr->power == pCurr->power)
		{
			this->changeCoefficient(curr->coeff + pCurr->coeff, curr->power);
			pCurr = pCurr->next;
		}
		else if (curr->power > pCurr->power)
		{
			curr = curr->next;
			if (curr == head) {
				insert(head, pCurr->coeff, pCurr->power);
				pCurr = pCurr->next;
				curr = head->next;
			}
		}
		else if (curr->power < pCurr->power) {
			insert(curr, pCurr->coeff, pCurr->power);
			pCurr = pCurr->next;

		}

	}
	return *this;
}

ostream& operator<<(ostream& output, const Polynomial& p)
{
	Polynomial::Term* curr = p.head->next;
	bool prev = false;
	while (curr && curr != p.head)
	{
		if (prev && curr->coeff > 0)
		{
			output << "+";
		}
		if (curr->coeff != 1)
		{
			output << curr->coeff;
		}
    if (curr->power > 0) {
  		if (curr->power == 1)
  		{
  			output << "x";
  		}
  		else
  		{
  			output << "x^" << curr->power;
  		}
    }
		prev = true;
		curr = curr->next;
	}
	return output;
}

bool Polynomial::insert(Term* pos, const double newCoefficient, const int power)
{
	if (newCoefficient == 0)
	{
		return false;
	}
	Term* temp = new Term;
	if (temp == NULL)
	{
		return false;
	}
	temp->coeff = newCoefficient;
	temp->power = power;
	Term* previous = pos->prev;
	if (previous == NULL)
	{
		previous = head;
	}
	previous->next = temp;
	temp->next = pos;
	pos->prev = temp;
	temp->prev = previous;


	return true;
}

bool Polynomial::remove(Term* pos)
{
	if (pos == head) {
		return false;
	}
	Term* previous = pos->prev;
	Term* next = pos->next;
	delete pos;
	previous->next = next;
	next->prev = previous;
	if (previous == head && next == head)

	{
		head->next = head->prev = NULL;
	}

	return true;
}
