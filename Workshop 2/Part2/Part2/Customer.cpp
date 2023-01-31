/***********************************************************************
// OOP244 Workshop 2 p2: customer cpp file
//
// File: Customer.cpp
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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete
    void EmptyRecord(Customers &rec)
    {
        rec = { 0 };
    }

    void EmptyRecord(CustomersRecord& rec)
    {
        rec = { 0 };
    }

    bool read(Customers& rec)
    {
        // char temp[21];
        cout << " Enter User name: ";
        read(rec.user_name, 21);
        if (strlen(rec.user_name))
        {
            //strCpy(rec.user_name, temp);
            cout << " Enter likes_count: ";
            cin >> rec.likes_count;
            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;
            cout << " Enter replies_count: ";
            cin >> rec.replies_count;
            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
            while ((getchar()) != '\n');
        } else return false;
        return true;
    }

    void read(char* str, int len) {  // Fully provided
        cin.getline(str, len);
        if (str[0] == '\n')
        {
            cin.ignore();
        }
    }

    
    // complete
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec)
    {
        CustomersRecord temp; 
        temp.noOfRecords = t_rec.noOfRecords + 1;
        temp.ptr_rec = new Customers[temp.noOfRecords];
        int i{};
        for (; i < t_rec.noOfRecords; i++)
            temp.ptr_rec[i] = t_rec.ptr_rec[i];
        temp.ptr_rec[i] = c_rec;
        delete[] t_rec.ptr_rec; 
        t_rec = temp;
    }

    void display(const Customers& c_rec)
    {
        cout << c_rec.user_name << ", ";
        cout << c_rec.likes_count << ", ";
        cout << c_rec.retweets_count << ", ";
        cout << c_rec.replies_count << ", ";
        cout << c_rec.share_videos << "\n\n";
    }

    void display(const CustomersRecord& t_rec)
    {
        for (int i = 0; i < t_rec.noOfRecords; i++)
        {
            cout << i + 1 << ". ";
            display(t_rec.ptr_rec[i]);
        }
    }
  }

