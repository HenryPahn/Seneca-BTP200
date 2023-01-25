/***********************************************************************
// OOP244 Workshop 1 p2: UI cpp file
//
// File:  UI.cpp
// Due date: Friday, 01/25/2023
// Author Fardad Soleimanloo
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 01/25/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "UI.h"
#include "GPAlist.h"
using namespace std; 

namespace sdds
{
	// SECTION: user interface
	// display menu
	void menu()
	{
		bool done = false; 
		char opt; 
		double val;
		cout << "Enter GPA query..." << endl;
		while (!done)
		{
			cout << "? ";
			cin >> opt;
			if (opt != '!') cin >> val;

			switch (opt)
			{
			case '>':
				displayGreaterGPA(val);
				break;
			case '<':
				displayLowerGPA(val);
				break;
			case '~':
				displayApproximateGPA(val);
				break;
			case '!': 
				cout << "Exit the program? (Y)es/(N)o: ";
				done = yes();
				break;
			default:
				error();
				break;
			}
		}
	}

	// display error message when user inputed the wrong option
	void error()
	{
		cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
		cout << "Op: [>,<,~,!]" << endl;
		cout << "value: GPA value" << endl << endl;
	}

	// return true if user enter y or Y
	bool yes()
	{
		char ans; cin >> ans;
		return ans == 'y' || ans == 'Y';
	}
}