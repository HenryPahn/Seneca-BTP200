/***********************************************************************
// OOP244 Workshop 1 p2: GPA list header file
//
// File:  GPAlist.h
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

#pragma once
#ifndef SDDS_GPALIST_H 
#define SDDS_GPALIST_H
#include "GPA.h"

namespace sdds
{
	bool gpaQuery(const char* filename);
	void swapStudents(GPA& st1, GPA& st2);
	bool compareStudents(const GPA st1, const GPA st2);
	void sortStudents(GPA* list, const int n);
	void displayApproximateGPA(const double target);
	void displayGreaterGPA(const double target);
	void displayLowerGPA(const double target);
}

#endif