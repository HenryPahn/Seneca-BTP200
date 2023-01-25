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
// Date: 01/25/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "GPAlist.h"
using namespace sdds;
int main() {
	if(gpaQuery("std.csv")) {
		std::cout << "This should have failed!" << std::endl;
	} else {
		std::cout << "failed!, this is the correct exectution" << std::endl;
	}
	if(!gpaQuery("students.csv")) {
		std::cout << "This should have worked, fix the problem!" << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return 0;
}