/***********************************************************************
// OOP244 Workshop 1 p2: GPA header file
//
// File:  GPA.h
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
#ifndef SDDS_GPA_H
#define SDDS_GPA_H
#include "GPAlist.h"

struct GPA
{
    char name[116];
    double gpa;
    int stno;
};

#endif // !SDDS_GPA_H