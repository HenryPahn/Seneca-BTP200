/***********************************************************************
// OOP244 Workshop 6 p1: numbers header file
//
// File:  numbers.h
// Due date: 00/00/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 00/00/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
       double* m_collection{}; 
       char m_fileName[255];
       int m_collectionSize{};
       bool m_origionalFlag{};
       bool m_addedFlag{};

       unsigned int countLines(const char* filename);
       void sort(double* collectionPtr, unsigned int size);

       void setEmpty();
       bool load();
       void save();
       double max() const;
       double min() const;
       double average() const;
   public:
       Numbers(const char* fileName);
       Numbers();
       ~Numbers();
       Numbers(const Numbers& object);
       Numbers& operator=(const Numbers& object);
       Numbers& operator+=(double value);
       explicit operator bool() const;
       void sort();
       std::ostream& display(std::ostream& ostr = std::cout) const;
       std::istream& read(std::istream& istr = std::cin);
   };

   std::ostream& operator<<(std::ostream& ostr, const Numbers& right);
   std::istream& operator>>(std::istream& value, Numbers& right);
}
#endif // !SDDS_NUMBERS_H_

