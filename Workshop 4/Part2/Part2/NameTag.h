/***********************************************************************
// OOP244 Workshop 4 p2: Name Tag header file
//
// File:  NameTag.h
// Due date: Friday, 02/15/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 02/13/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#pragma once
#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_
#include <iostream>
#include <iomanip>
#include <cstring>

namespace sdds
{
	const int MAX_NAME = 40;
	class NameTag
	{
		char* m_name {}; // only name with 40 characters allowed
		int m_num {}; // 5 digit number

	public: 
		void setName(const char* t_name);
		void setEmpty();
		int countDigit(int n) const;
		std::ostream& print() const;
		NameTag& read();
		NameTag();
		NameTag(const char* t_name);
		NameTag(const char* t_name, int t_num);
		~NameTag();
	};
}

#endif 