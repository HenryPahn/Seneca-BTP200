/***********************************************************************
// OOP244 Workshop 1 p2: GPA list cpp file
//
// File:  GPAlist.cpp
// Due date: Friday, 01/25/2023
// Author Fardad Soleimanloo
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 01/19/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "GPAlist.h"
using namespace std; 
using namespace sdds;

namespace sdds
{
	bool gpaQuery(const char* filename)
	{
		ifstream f(filename); // open file
		if (f.is_open()) // check the file is open or not
		{
			userChoices(filename); // UI.cpp - Lets users make decisions.
			return 1;
		}
		return 0;
	}
}