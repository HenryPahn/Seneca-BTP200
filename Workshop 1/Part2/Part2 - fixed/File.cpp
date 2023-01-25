/***********************************************************************
// OOP244 Workshop 1 p2: File cpp file
//
// File:  File.cpp
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

#include "File.h"
using namespace std;

FILE* fptr;

namespace sdds
{
    // SECTION: open and close file
    // opens the data file and returns true is successful
    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // closes the data file
    void closeFile()
    {
        if (fptr) fclose(fptr);
    }

    // SECTION: extract students' data from file
    // read students' name from global fptr GPA pointer and returns true if successful
    bool readName(char name[])
    {
        return fscanf(fptr, "%[^,],", name) == 1;
    }


    // read students' number from global fptr GPA pointer and returns true if successful
    bool readSTNO(int* stno)
    {
        return fscanf(fptr, "%d,", stno) == 1;
    }

    // read students' gpa from global fptr GPA pointer and returns true if successful
    bool readGPA(double* gpa)
    {
        return fscanf(fptr, "%lf\n", gpa) == 1;
    }
}