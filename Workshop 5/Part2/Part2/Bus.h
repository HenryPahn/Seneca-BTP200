/***********************************************************************
// OOP244 Workshop 5 p2: main header file
//
// File:  Bus.h
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

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_BUS_H
#define SDDS_BUS_H

#include <iostream>

namespace sdds
{
	const double TICKET_PRICE = 125.34; 

	class Bus
	{
		int m_noOfSeats{};
		int m_noOfPassengers{};
		void drawBus(int seats, int noOfPassengers, std::ostream& ostr) const;

	public:
		void outOfService();
		Bus(int noOfSeats = 20, int noOfPassengers = 0);

		std::ostream& display(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);

		explicit operator bool() const;
		explicit operator int() const;
		explicit operator double() const;

		bool operator--();
		bool operator++();
		bool operator--(int);
		bool operator++(int);

		Bus& operator=(int value);
		Bus& operator+=(int value);
		Bus& operator+=(Bus& right);
		bool operator==(const Bus& right) const;
	};

	int operator+(int left, const Bus& right);
	std::ostream& operator<<(std::ostream& ostr, const Bus& right);
	std::istream& operator>>(std::istream& istr, Bus& right);
}

#endif 

