/***********************************************************************
// OOP244 Workshop 1 p2: main cpp file
//
// File:  main.cpp
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


#include <iostream>
#include "GPAlist.h"
using namespace sdds;
using namespace std; 

int main()
{
	if (gpaQuery("std.csv"))
	{
		cout << "This should have failed!" << endl;
	}
	else
	{
		cout << "failed!, this is the correct exectution" << endl;
	}
	if (!gpaQuery("students.csv"))
	{
		cout << "This should have worked, fix the problem!" << endl;
	}

	cout << "Goodbye!" << endl;
	return 0;
}
