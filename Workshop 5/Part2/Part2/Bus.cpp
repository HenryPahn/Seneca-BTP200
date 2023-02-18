/***********************************************************************
// OOP244 Workshop 5 p2: bus cpp file
//
// File:  Bus.cpp
// Due date: Friday, 02/22/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 02/18/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Bus.h"
using namespace std; 

namespace sdds
{
	// SECTION: additional functions 
	// set the bus status to be out of service
	void Bus::outOfService()
	{
		this->m_noOfSeats = -1;
		this->m_noOfPassengers = -1;
	}
	
	// SECTION: constructor
	Bus::Bus(int noOfSeats, int noOfPassengers)
	{
		bool BusStatus = !(noOfSeats % 2) && noOfSeats >= 10 && noOfSeats <= 40 && noOfPassengers >= 0 && noOfPassengers <= noOfSeats;
		if (BusStatus)
		{
			this->m_noOfSeats = noOfSeats;
			this->m_noOfPassengers = noOfPassengers;
		}
		else
		{
			outOfService();
		}
	}

	// SECTION: display and read
	// draw the bus
	void Bus::drawBus(int seats, int noOfPassengers, std::ostream& ostr) const
	{
		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;
	}

	// display the bus
	std::ostream& Bus::display(std::ostream& ostr) const
	{
		if (*this)
		{
			drawBus(m_noOfSeats, m_noOfPassengers, ostr);
			ostr.setf(ios::fixed);
			int oldPrecision = ostr.precision(2);
			ostr << "Total Fare Price: " << (double) m_noOfPassengers * TICKET_PRICE << endl;
			ostr.unsetf(ios::fixed);
			ostr.precision(oldPrecision);
		}
		else
		{
			ostr << "Out of service!" << endl;
		}
		return ostr;
	}

	// read the infomation of the bus from the input
	std::istream& Bus::read(std::istream& istr)
	{
		int noOfSeats{};
		istr >> noOfSeats;
		istr.ignore();
		int noOfPassengers{};
		istr >> noOfPassengers;


		bool BusStatus = !(noOfSeats % 2) && noOfSeats >= 10 && noOfSeats <= 40 && noOfPassengers >= 0 && noOfPassengers <= noOfSeats;
		if (BusStatus)
		{
			this->m_noOfSeats = noOfSeats;
			this->m_noOfPassengers = noOfPassengers;
		}
		else
		{
			outOfService();
		}
		return istr;
	}

	// SECTION: type conversion operator overloads
	// boolean conversion
	Bus::operator bool() const
	{
		if (m_noOfSeats != -1)
			return true; 
		return false;
	}

	// integer conversion
	Bus::operator int() const
	{
		return *this ? m_noOfPassengers : -1;
	}

	// double conversion
	Bus::operator double() const
	{
		return *this ? m_noOfPassengers * TICKET_PRICE : -1.0;
	}


	// SECTION: unary operator overload 
	// prefix operator --, decrease the number of passengers
	bool Bus::operator--()
	{
		if (!*this || !m_noOfPassengers)
			return false;
		m_noOfPassengers--; 
		return true;
	}

	// prefix operator --, increase the number of passengers
	bool Bus::operator++()
	{
		if (!*this || m_noOfSeats == m_noOfPassengers)
			return false;
		m_noOfPassengers++;
		return true;
	}

	// postfix operator --, decrease the number of passengers
	bool Bus::operator--(int)
	{
		return --(*this);
	}

	// postfix operator --, increase the number of passengers
	bool Bus::operator++(int)
	{
		return ++(*this);
	}


	// SECTION: Binary Member Operators
	// operator =, assgin a bus object to an integer value
	Bus& Bus::operator=(int value)
	{
		m_noOfPassengers = value; 
		if (m_noOfPassengers > m_noOfSeats)
			outOfService();
		return *this;
	}

	// operator +=, add a integer value to an bus object
	Bus& Bus::operator+=(int value)
	{
		if(*this)
			m_noOfPassengers += value;
		if (m_noOfPassengers > m_noOfSeats)
			outOfService();
		return *this;
	}

	// operator +=, add a bus object to another bus object
	Bus& Bus::operator+=(Bus& right)
	{
		if (*this && right)
		{
			const int availableSeats = m_noOfSeats - m_noOfPassengers;
			if (availableSeats)
			{
				if (availableSeats < right.m_noOfPassengers)
				{
					m_noOfPassengers = m_noOfSeats; 
					right.m_noOfPassengers -= availableSeats;
				}
				else
				{
					m_noOfPassengers += right.m_noOfPassengers;
					right.m_noOfPassengers = 0;
				}
			}
		}
		return *this;
	}

	// operator ==, comparing two buses
	bool Bus::operator==(const Bus& right) const
	{
		if (*this && right && m_noOfPassengers == right.m_noOfPassengers)
			return true; 
		return false;
	}

	// SECTION: helper functions 
	// operator, sum of an integer number (at left) and a bus (at right)
	int operator+(int left, const Bus& right)
	{
		if (right)
			return left + int(right);
		return left;
	}

	// operator << overloading
	std::ostream& operator<<(std::ostream& ostr, const Bus& right)
	{
		return right.display(ostr);
	}

	// operator << overloading
	std::istream& operator>>(std::istream& istr, Bus& right)
	{
		return right.read(istr);
	}
}