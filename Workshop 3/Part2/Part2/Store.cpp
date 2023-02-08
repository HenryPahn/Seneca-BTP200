/***********************************************************************
// OOP244 Workshop 3 p2: Store cpp file
//
// File:  Store.cpp
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
#include "Store.h"
#include "Toys.h"
using namespace std; 

namespace sdds
{
	// SECTION: add all information of a store
	// add store's name and number of toys in that store
	void Store::setStore(const char* sName, int no)
	{
		setEmpty();
		if (sName && no)
		{
			strcpy(this->m_sName, sName);
			this->m_noOfToys = no;
		}
	}

	// add a toy into the store 
	void Store::setToys(const char* tname, int sku, double price, int age)
	{
		if (m_noOfToys - m_addToys)
			this->m_toy[m_addToys++].addToys(tname, sku, price, age);
	}

	// SECTION: display a store
	// display a form of the store
	void Store::display() const
	{
		if (strlen(m_sName) && m_noOfToys)
		{
			cout << setfill('*') << setw(61) << '\n' << m_sName << endl;
			cout << setfill('*') << setw(61) << '\n' << "list of the toys" << endl;
			cout << setfill(' ') << setw(30) << "SKU";
			cout << setfill(' ') << setw(10) << "Age";
			cout << setfill(' ') << setw(11) << "Price";
			cout << setfill(' ') << setw(10) << "Sale" << endl;
			for (int i = 0; i < m_addToys; i++)
			{
				cout << "Toy[" << i + 1 << "] :";
				m_toy[i].display();
			}
		}
		else
			cout << "Invalid Store" << endl;
	}

	// find the item has the given sku 
	void Store::find(int sku)
	{
		for (int i = 0; i < m_noOfToys; i++)
		{
			if (m_toy[i].checkSKU(sku))
			{
				m_toy[i].isSale(true);
				m_toy[i].calSale();
			}
		}
	}

	// SECTION: clear the current store
	void Store::setEmpty()
	{
		strcpy(this->m_sName, "");
		for (int i = 0; i < m_noOfToys; i++)
		{
			this->m_toy[i].setEmpty();
		}
		this->m_noOfToys = 0; 
		this->m_addToys = 0; 
	}
}