/***********************************************************************
// OOP244 Workshop 3 p1: Main cpp file
//
// File:  main.cpp
// Due date: Friday, 02/03/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 02/03/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Department.h"
using namespace std;
using namespace sdds;

int main() {
	Project testProject = { "Base",551.55 };

	Project myprojects[5] = { {"Synergy", 5041.55},
							  {"Mecha", 2925.99},
							  {"Chroma", 3995.45},
							  {"Force", 6988.45},
							  {"Oculus", 7441.22}
	};

	Department SDDS{};

	//Test1
	cout << "**********Create Department TEST START**********" << endl;
	SDDS.createDepartment("School of Software development", testProject, 1);
	display(SDDS);
	cout << "**********Create Department TEST END**********" << endl;

	//Test2
	cout << endl << "**********Update Name TEST Start**********" << endl;
	SDDS.updateName("School of Software development and design");
	display(SDDS);
	cout << "**********Update Name TEST END**********" << endl;

	//Test3
	cout << endl << "**********Update Budget TEST Start**********" << endl;
	SDDS.updateBudget(5555.99);
	display(SDDS);
	cout << "**********Update Budget TEST END**********" << endl;

	//Test4
	cout << endl << "**********Expenses and Remaining Budget TEST Start**********" << endl;
	cout << "Our current total Expenses are: " << SDDS.totalexpenses() << endl;
	cout << "Our remaining budget is: " << SDDS.remainingBudget() << endl;
	cout << "**********Expenses and Remaining Budget TEST END**********" << endl;

	//Test5
	cout << endl << "**********Add Project TEST START**********" << endl;
	for (int i = 0; i < 5 && SDDS.addProject(myprojects[i]); i++);
	display(SDDS);
	cout << "**********Add Project TEST END**********" << endl;
	
	SDDS.clearDepartment();
	return 0;
}
