/***********************************************************************
// OOP244 Workshop 2 p1: main cpp file
//
// File:  main.cpp
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

#include<iostream>
#include "Package.h"

using namespace std;
using namespace sdds;
const bool APP_OS_WINDOWS = true;

int main() {
    
    loadTraces();
    cout << "Records were retrieved successfully" << endl;

    grouptTraces();
    cout << "Data records were grouped by the user id successfully" << endl;

    cout<< "User id, timeinhours, Fctime, Fwifitime, Package Name" << endl
        << "....................................................." << endl;

    display();
    cout << "\nData was successfully printed" << endl;
    
    deallocateMemory();
    cout << "Dynamically allocated memory was successfully deallocated"<<endl;
    return 0;
}

