/***********************************************************************
// OOP244 Workshop 5 p1: egg carton header file
//
// File:  EggCarton.h
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

#ifndef SDDS_EGGCARTON_H_
#define SDDS_EGGCARTON_H_
#include <iostream>
#include <cstring>

namespace sdds
{
	const int RegularEggWieght = 50;
	const int JumboEggWieght = 75;
	class EggCarton
	{
		int m_size{};
		int m_noOfEggs{};
		char m_jumboSize{};
		
	public:
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
		void setBroken();

		void displayCarton(std::ostream& ostr) const;
		void read(std::istream& istr);

		explicit operator bool() const;
		explicit operator int() const;
		explicit operator double() const;

		EggCarton& operator--();
		EggCarton& operator++();
		EggCarton operator--(int);
		EggCarton operator++(int);

		EggCarton& operator=(int value);
		EggCarton& operator+=(int value);
		EggCarton& operator+=(EggCarton& right);

		bool operator==(const EggCarton& right) const;
	};
	int operator+(int left, const EggCarton& right);
	std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
	std::istream& operator>>(std::istream& istr, EggCarton& right);
}

#endif // 
