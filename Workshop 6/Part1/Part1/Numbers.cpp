/***********************************************************************
// OOP244 Workshop 6 p1: numbers cpp file
//
// File:  numbers.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include "Numbers.h"

using namespace std;

namespace sdds {

    // SECTION: constructors
    // constructor with one argument
    Numbers::Numbers(const char* fileName)
    {
        strcpy(this->m_fileName, fileName);
        load();
    }

    // default constructor
    Numbers::Numbers()
    {
        setEmpty();
    }

    // destructor
    Numbers::~Numbers()
    {
        save();
        delete[] this->m_collection;
    }

    // copy constructor
    Numbers::Numbers(const Numbers& object)
    {
        setEmpty();
        *this = object;

    }

    // copy assignment operator
    Numbers& Numbers::operator=(const Numbers& right)
    {
        bool check = this->m_collection != right.m_collection ||
            this->m_fileName != right.m_fileName ||
            this->m_collectionSize != right.m_collectionSize ||
            this->m_origionalFlag != right.m_origionalFlag ||
            this->m_addedFlag != right.m_addedFlag;

        if (check)
        {
            save();
            setEmpty();
            if (right.m_collectionSize)
            {
                strcpy(this->m_fileName, right.m_fileName);
                m_origionalFlag = false;
                this->m_collection = new double[right.m_collectionSize];
                for (int i = 0; i < right.m_collectionSize; i++)
                    this->m_collection[i] = right.m_collection[i];
                this->m_collectionSize = right.m_collectionSize;
            }
        }
        return *this;
    }


    // SECTION: private method
    // sort an array of doubles
    void Numbers::sort(double* nums, unsigned int size)
    {
        unsigned int i, j;
        double temp;
        for (i = size - 1; size && i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }

    // count number of lines in a file
    unsigned int Numbers::countLines(const char* filename)
    { 
        unsigned int lines = 0u;
        ifstream nums(filename);
        while (nums)
        {
            lines += (nums.get() == '\n');
        }
        return lines;
    }

    // empty an object
    void Numbers::setEmpty()
    {
        delete[] this->m_collection;
        m_collection = nullptr;
        strcpy(m_fileName, "\0");
        m_collectionSize = 0;
        m_origionalFlag = false;
        m_addedFlag = false;
    }
    
    // read the data from a file
    bool Numbers::load()
    {
        delete[] this->m_collection;
        int noOfLines = countLines(m_fileName);
        if (noOfLines)
        {
            this->m_collection = new double[noOfLines];
            ifstream ifs(m_fileName, ifstream::in);
            double number;
            ifs >> number;

            int noOfReads{};

            while (ifs.good())
            {
                noOfReads++;
                m_collection[m_collectionSize++] = number;
                ifs >> number;
            }

            if (noOfLines != noOfReads)
            {
                setEmpty();
            }
            else
            {
                m_collectionSize = noOfReads;
                m_origionalFlag = true;
            }

            ifs.close();

            if (noOfReads) return true;
        }
        return false;
    }

    // save the current object
    void Numbers::save()
    {
        if (m_origionalFlag && m_addedFlag)
        {
            ofstream ofs(m_fileName, ofstream::out);
            cout.setf(ios::fixed);
            int oldPrecision = cout.precision(2);
            for (int i = 0; i < m_collectionSize; i++)
                ofs << m_collection[i] << endl;
            cout.unsetf(ios::fixed);
            cout.precision(oldPrecision);
            ofs.close();
        }
    }

    // return the largest double
    double Numbers::max() const
    {
        double max = m_collection[0];
        for (auto i = 0; i < m_collectionSize; i++)
            max = m_collection[i] > max ? m_collection[i] : max;
        return max;
    }

    // return the smallest double
    double Numbers::min() const
    {
        double min = m_collection[0];
        for (auto i = 0; i < m_collectionSize; i++)
            min = m_collection[i] < min ? m_collection[i] : min;
        return min;
    }

    // return the adverage of the double numbers
    double Numbers::average() const
    {
        double avg{};
        for (auto i = 0; i < m_collectionSize; i++)
            avg += m_collection[i];
        return avg / m_collectionSize;
    }

    // SECTION: public method
    // check the status of the object
    Numbers::operator bool() const
    {
        bool check = m_collection && m_collectionSize;
        if (check)
            return true;
        return false;
    }

    // sort an array of doubles
    void Numbers::sort()
    {
        for (int i = 0; i < m_collectionSize - 1; i++)
        {
            for (int j = i; j < m_collectionSize; j++)
            {
                if (m_collection[i] > m_collection[j])
                {
                    double temp = m_collection[i];
                    m_collection[i] = m_collection[j];
                    m_collection[j] = temp;
                }
            }
        }
    }
    
    // operator += overloading, add a sungle double value to the list
    Numbers& Numbers::operator+=(double value)
    {
        if (*this)
        {
            int n_collectionSize = m_collectionSize + 1;
            double* temp = new double[n_collectionSize];
            for (int i = 0; i < m_collectionSize; i++)
                temp[i] = this->m_collection[i];
            temp[m_collectionSize] = value;

            delete[] this->m_collection;
            this->m_collection = new double[n_collectionSize];
            for (int i = 0; i < n_collectionSize; i++)
                this->m_collection[i] = temp[i];
            this->m_collectionSize = n_collectionSize;
            delete[] temp;
        }
        
        return *this;
    }

    // display function
    std::ostream& Numbers::display(std::ostream& ostr) const
    {
        if (!*this)
        {
            ostr << "Empty list";
        }
        else
        {
            ostr.setf(ios::fixed);
            int oldPrecision = ostr.precision(2);
            if (!m_origionalFlag)
                ostr << "Copy of "; 
            ostr << m_fileName << endl;
            ostr << m_collection[0];
            for(int i = 1; i < m_collectionSize; i++) 
                ostr << ", " << m_collection[i];
            ostr << endl;
            for (int i = 1; i < 76; i++)
                ostr << "-";
            ostr << endl;
            ostr << "Total of " << m_collectionSize << " number(s), Largest: " << max() << ", Smallest: " << min() << ", Average: " << average();
            ostr << endl;
            for (int i = 1; i < 76; i++)
                ostr << "=";
            ostr.unsetf(ios::fixed);
            ostr.precision(oldPrecision);
        }
        return ostr;
    }

    // read function
    std::istream& Numbers::read(std::istream& istr)
    {
        double value{};
        istr >> value; 
        *this += value;
        return istr;
    }

    // SECTION: helper function
    // overload insertion operator
    std::ostream& operator<<(std::ostream& ostr, const Numbers& right)
    {
        return right.display(ostr);
    }

    // overload extraction operator
    std::istream& operator>>(std::istream& istr, Numbers& right)
    {
        return right.read(istr);
    }
}