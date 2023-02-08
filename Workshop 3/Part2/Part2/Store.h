/***********************************************************************
// OOP244 Workshop 3 p2: Store header file
//
// File:  Store.h
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

#pragma once
#define MAX_NUM_TOYS 10
#define MAX_SNAME 31
#include "Toys.h"
#include <cstring>

namespace sdds
{
	class Store 
	{
		char m_sName[MAX_SNAME];
		int m_noOfToys = 0;
		int m_addToys = 0;
		Toys m_toy[MAX_NUM_TOYS];

	public:
		void setStore(const char* sName, int no);
		void setToys(const char* tname, int sku, double price, int age);
		void display()const;
		void find(int sku);
		void setEmpty();
	};
}