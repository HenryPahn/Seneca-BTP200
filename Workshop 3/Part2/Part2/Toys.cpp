/***********************************************************************
// OOP244 Workshop 3 p2: Toys cpp file
//
// File:  Toys.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "Toys.h"
using namespace std; 

namespace sdds
{
	// SECTION: add all information of a toy 
	// add toy's name, sku, price and age
	void Toys::addToys(const char* tname, int sku, double price, int age)
	{
		if (tname && countSKU(sku) == 8)
		{
			strcpy(this->m_tname, tname);	
			this->m_sku = sku; 
			this->m_price = price; 
			this->m_age = age;
		}
		else
		{
			setEmpty();
		}
	}

	// count number of digit of toy's sku
	int Toys::countSKU(int sku) const
	{
		int cnt = 0;
		if (sku < 0) cnt = 1;
		while (sku)
		{
			sku /= 10;
			cnt++;
		}
		return cnt;
	}

	// check if the toy's sku matchs the given sku or not
	bool Toys::checkSKU(int sku) const
	{
		return m_sku == sku;
	}

	// set the status of the toy is on sale
	void Toys::isSale(bool sale)
	{
		this->m_onSale = sale;
	}

	// caculate the price of the toy after discount
	void Toys::calSale()
	{
		if (m_onSale)
			this->m_price = (m_price * 80) / 100;
	}

	// SECTION: display all information of a toy
	void Toys::display() const
	{
		if(m_tname && to_string(m_sku).length() == 8) // a Toy object is valid
		{
			cout.width(15); cout << setfill(' ') << left << m_tname;
			cout << setw(10) << internal << m_sku; 
			cout << setw(6) << internal << m_age;
			cout << setw(12) << fixed << setprecision(2) << internal << m_price;
			if (m_onSale)
				cout << setw(11) << right << "On Sale " << endl;
			else
				cout << setfill(' ') << setw(8) << right << "" << endl;
		} else
			cout << "Invalid Toy" << endl;
	}

	// SECTION: eliminate a toy from the store
	void Toys::setEmpty()
	{
		strcpy(this->m_tname, "");
		this->m_sku = 0;
		this->m_price = 0;
		this->m_age = 0;
		this->m_onSale = false;
	}
}