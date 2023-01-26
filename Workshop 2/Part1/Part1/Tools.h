/***********************************************************************
// OOP244 Workshop 2 p1: Tools header file
//
// File:  Tools.h
// Due date: Friday, 01/27/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 01/26/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	// ADD: Declare read prototypes (4 prototypes)
	int read(char data[]);
	int read(int& data);
	int read(double& data);
	int read(char& data);

	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 
