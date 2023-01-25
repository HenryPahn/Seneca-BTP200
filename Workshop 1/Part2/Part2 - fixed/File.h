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
// Date: 01/25/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#pragma once
#ifndef SDDS_FILE_H 
#define SDDS_FILE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>

namespace sdds
{
    bool openFile(const char filename[]);
    void closeFile();
    bool readName(char name[]);
    bool readSTNO(int* stno);
    bool readGPA(double* gpa);
}

#endif