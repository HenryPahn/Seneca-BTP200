/***********************************************************************
// OOP244 Workshop 2 p2: main cpp file
//
// File: main.cpp
// Due date: Friday, 02/01/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 01/28/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

// Please don't change this file
// This file is to test your source code

#include <iostream>
#include "Customer.h"
using namespace std;
using namespace sdds;

int main() {
    bool Check = false;

    Customers c_rec;
    EmptyRecord(c_rec);

    CustomersRecord t_rec;
    EmptyRecord(t_rec);

    cout << "---------  Customers records entry ------------------" << endl;
    while (!Check) {
        cout << endl<<"Enter customer information (to exit, press Enter): " << endl;
        if (read(c_rec)) {
            addCustomer(t_rec, c_rec);
        }
        else {
            Check = true;
        }
    }

    cout << "---------------------------------------------------------" << endl;
    cout << "                Users' tweets report                     " << endl;
    cout << " user name, likes, re-tweets, replies, share videos (y/n)" << endl;
    cout << "---------------------------------------------------------" << endl;

    display(t_rec);
    cout << "---------------------------------------------------------" << endl;
    cout << "            Report was successfully created                " << endl;

    delete[] t_rec.ptr_rec;
    cout << "Dynamically allocated memory was successfully deallocated" << endl;
    cout << "---------------------------------------------------------" << endl;

    }




