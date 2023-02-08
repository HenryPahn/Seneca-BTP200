#pragma once
#define MAX_TNAME 31
#include <cstring>
/***********************************************************************
// OOP244 Workshop 3 p2: Toys header file
//
// File:  Toys.h
// Due date: Friday, 02/08/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 02/06/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iomanip>
#include <iostream>
#include <string>

namespace sdds
{
	class Toys
	{
		char m_tname[MAX_TNAME];
		int m_sku = 0; 
		double m_price = 0;
		int m_age = 0;
		bool m_onSale = false;

	public: 
		void addToys(const char* tname, int sku, double price, int age);
		int countSKU(int sku) const; 
		bool checkSKU(int SKU) const;
		void isSale(bool sale);
		void calSale();
		void display()const;
		void setEmpty();
	};
	
}

