/***********************************************************************
// OOP244 Workshop 1 p2: file header file
//
// File:  File.h
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

#pragma once
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include "GPAlist.h"

namespace sdds
{
	void retrieveData(const char* filename, GPA* students, int &i);
	void swapStudents(GPA& st1, GPA& st2);
	bool compareStudents(const GPA st1, const GPA st2);
	void sortStudents(GPA* students, const int n);
	void approximateGPA(GPA* students, const int size, const double targetGPA);
	void greaterGPA(GPA* students, const int size, const double targetGPA);
	void lowerGPA(GPA* students, const int size, const double targetGPA);
}

#endif // !SDDS_GPA_H