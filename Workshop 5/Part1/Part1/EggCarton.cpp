/***********************************************************************
// OOP244 Workshop 5 p1: egg carton cpp file
//
// File:  EggCarton.cpp
// Due date: Friday, 02/17/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 02/15/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "EggCarton.h"
using namespace std; 

namespace sdds
{
	// SECTION: the constructor
	EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) 
	{
		bool check = !(size % 6) && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size;
		if (check)
		{
			this->m_size = size; 
			this->m_noOfEggs = noOfEggs; 
			this->m_jumboSize = jumboSize;
		}
		else
		{
			setBroken();
		}
	}

	// SECTION: additional function
	// this function set the status of an egg carton to broken
	void EggCarton::setBroken()
	{
		this->m_size = -1;
		this->m_noOfEggs = -1;
	}

	// SECTION: UI function 
	// display an egg carton
	void EggCarton::displayCarton(std::ostream& ostr) const 
	{
		if (bool(*this))
		{
			int cartonWidth = m_size == 6 ? 3 : 6;
			for (int i = 0; i < m_size; i++)
			{
				ostr << ((i % cartonWidth) ? '|' : '[') << ((i < m_noOfEggs) ? (m_jumboSize ? 'O' : 'o') : ' ');
				((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
			}2
		}
		else
		{
			cout << "Broken Egg Carton!" << endl;
		}
	}
	
	// take the information of an egg carton from the input
	void EggCarton::read(std::istream& istr) 
	{
		char jumboSize;
		istr >> jumboSize;
		istr.ignore(1);
		int size;
		istr >> size;
		cin.ignore(1);
		int noOfEggs;
		istr >> noOfEggs;
		
		bool check = !(size % 6) && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs < size;
		if (check)
		{
			this->m_size = size; 
			this->m_noOfEggs = noOfEggs; 
			m_jumboSize = jumboSize == 'j' ? true : false;
		}
		else
		{
			setBroken();
		}
	}

	// SECTION:: type conversion operator overloads
	// boolean conversion
	EggCarton::operator bool() const 
	{
		if (m_size > 0)
			return true;
		return false;
	}
	
	// integer conversion
	EggCarton::operator int() const
	{
		if (bool(*this))
			return m_noOfEggs; 
		return -1; 
	}

	// double conversion
	EggCarton::operator double() const
	{
		if (bool(*this))
		{
			if (m_jumboSize)
				return (m_noOfEggs * JumboEggWieght) / 1000.00;
			else
				return (m_noOfEggs * RegularEggWieght) / 1000.00;
		}
		return -1.0;
	}

	// SECTION: unary operator overload
	// prefix operator --
	EggCarton& EggCarton::operator--()
	{
		bool check(*this);
		if (check && m_noOfEggs)
		{
			m_noOfEggs--;
		}
		return *this;
	}

	// prefix operator ++
	EggCarton& EggCarton::operator++()
	{
		bool check(*this);
		if (check)
		{
			m_noOfEggs++; 
			if (m_noOfEggs > m_size)
				setBroken();
		}
		return *this;
	}

	// postfix operator --
	EggCarton EggCarton::operator--(int)
	{
		EggCarton temp = *this; 
		--(*this); 
		return temp;
	}

	// postfix operator ++
	EggCarton EggCarton::operator++(int)
	{
		EggCarton temp = *this; 
		++(*this); 
		return temp;
	}

	// SECTION: Binary Member Operators
	// member operator =, set an integer value to the number of egg
	EggCarton& EggCarton::operator=(int value)
	{
		this->m_noOfEggs = value;
		if (m_noOfEggs > m_size)
			setBroken();
		return *this;
	}

	// member operator +=, add an integer value to number of egg 
	EggCarton& EggCarton::operator+=(int value)
	{
		bool check(*this);
		if (check)
		{
			m_noOfEggs += value; 
			if (m_noOfEggs > m_size)
				setBroken();
		}
		return *this;
	}

	// member operator +=, move number of eggs from a carton to another one
	EggCarton& EggCarton::operator+=(EggCarton& right)
	{
		bool check(*this);
		if (check)
		{
			const int emptySpots = m_size - m_noOfEggs;
			if (emptySpots)
			{
				if (emptySpots >= right.m_noOfEggs)
				{
					this->m_noOfEggs += right.m_noOfEggs;
					right.m_noOfEggs = 0;
				}
				else
				{
					this->m_noOfEggs = m_size;
					right.m_noOfEggs = right.m_noOfEggs - emptySpots;
				}
			}
		}
		return *this;
	}

	// member operator ==, validate the weights of 2 egg cartons
	bool EggCarton::operator==(const EggCarton& right) const
	{
		double c_weight(*this);
		double r_weight(right);
		double diff = c_weight - r_weight;
		bool check = diff > -0.001 && diff < 0.001;
		return check ? true : false;
	}

	// Helper Binary Operator Overload
	// helper operator +
	int operator+(int left, const EggCarton& right)
	{
		bool check(right);
		if (check)
			return left + int(right);
		return int(right);
	}

	// helper operator <<
	std::ostream& operator<<(std::ostream& ostr, const EggCarton& right) 
	{
		right.displayCarton(ostr);
		return ostr;
	}

	// helper operator >>
	std::istream& operator>>(std::istream& istr, EggCarton& right) 
	{
		right.read(istr);
		return istr;
	}
}
