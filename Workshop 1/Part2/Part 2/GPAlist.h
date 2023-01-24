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
// Date: 01/19/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#pragma once
#ifndef SDDS_GPALIST_H
#define SDDS_GPALIST_H
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cctype>
#include<string>
#include<vector>
#include<iomanip>
#include<string.h>
#include "GPA.h"
#include "UI.h"
#include "File.h"

namespace sdds
{
	bool gpaQuery(const char* filename);
}

#endif // !SDDS_GPA_H