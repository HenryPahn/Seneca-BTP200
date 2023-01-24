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
// Date: 01/19/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "GPAlist.h"
using namespace std;

namespace sdds
{
	bool exist() // Option - exist
	{
		char a[4];
		cout << "Exit the program? (Y)es/(N)o: ";
		cin >> a;
		a[0] = toupper(a[0]);
		if (a[0] != 'Y') return 0;
		return 1;
	}

	void error() // Display error when user input wrong option
	{
		cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
		cout << "Op: [>,<,~,!]" << endl;
		cout << "value: GPA value" << endl << endl;
	}

	void userChoices(const char* filename) // Let users make decision
	{	
		GPA* students = new GPA[100]; // Initialize dynamic array with struct GPA type to store the list of students
		int size{};
		retrieveData(filename, students, size); // Retrieve information from file, and assign to dynamic array

		cout << "Enter GPA query..." << endl; 
		char option = '~';
		double targetGPA{};
		while (option != '!') 
		{
			cout << "? ";
			cin >> option;
			if (option != '!') cin >> targetGPA;

			switch (option)
			{
				case '~':
					// display students with gpa equal to user's target
					approximateGPA(students, size, targetGPA);
					break;
				case '>':
					// display students with gpa greater than user's target 
					greaterGPA(students, size, targetGPA);
					break;
				case '<':
					// display students with gpa lower than user's target
					lowerGPA(students, size, targetGPA);
					break;
				case '!':
					// question to confirm that user will quit the program
					if(!exist()) option = '~';
					break;
				default: 
					// display error that user inputed the wrong option
					error();
					break;
			}
		}
		delete[] students;
	}
}

