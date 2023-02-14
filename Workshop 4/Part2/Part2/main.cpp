/***********************************************************************
// OOP244 Workshop 4 p2: main cpp file
//
// File:  main.cpp
// Due date: Friday, 02/15/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 02/13/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
using namespace std;
#include "NameTag.h"
using namespace sdds;

int main() {
   NameTag nt[6] = {  
       {"A very very very long name to be cut short!!!"}, // one argument constructor
      {"Fred Soley", 12345} ,       // two argument constructor with good data
      {nullptr, 23456},    // two argument constructor with bad name
      {"Bad number", 1234},  // two argument constructor with bad number
      {"Bad number", 123456}  // two argument constructor with bad number
                             // default constructor (sixth element)
   };
   int i;
   for (i = 0; i < 6; i++) {
      nt[i].print();
      cout << endl;
   }
   nt[1].read().print();
   nt[3].read().print();
   nt[5].read().print();
   return 0;
}
