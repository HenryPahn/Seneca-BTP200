/*
*****************************************************************************
                          Workshop - #2 (P2)
Full Name  : Zoey Lin
Student ID#: 139452221
Email      : zlin104@myseneca.ca
Date       : 2023/01/31
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }
    void EmptyRecord(Customers& rec)
    {
        strCpy(rec.user_name, "\0");
        rec.retweets_count = 0;
        rec.likes_count = 0;
        rec.replies_count = 0;
        rec.share_videos = '\0';
    }
    void EmptyRecord(CustomersRecord &rec)
    {
        //rec.ptr_rec = nullptr;
        rec = { 0 };

       // rec.noOfRecords = 0;
    }
    bool read(Customers& rec)
    {
        bool check = false;
        cout << "Enter User name: ";
        read(rec.user_name, 100);
        if (rec.user_name)
        {
            cout << "Enter likes_count: ";
            cin >> rec.likes_count;
            cout << "Enter retweets_count: ";
            cin >> rec.retweets_count;
            cout << "Enter replies_count: ";
            cin >> rec.replies_count;
            cout << "Enter share videos (y/n):";
            cin >> rec.share_videos;
            check = true;
        }
        return check;
    }

    // complete
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec)
    {
        CustomersRecord tmp;
        tmp.noOfRecords = t_rec.noOfRecords + 1;
        tmp.ptr_rec = new Customers[tmp.noOfRecords];
        for (int i = 0; i < t_rec.noOfRecords; i++)
        {
            tmp.ptr_rec[i] = t_rec.ptr_rec[i];
        }
        tmp.ptr_rec[t_rec.noOfRecords] = c_rec;
        delete[] t_rec.ptr_rec;
        t_rec = tmp;


        /*
        t_rec.ptr_rec = new Customers[t_rec.noOfRecords];
        int newSize = t_rec.noOfRecords + 1;
        Customers* tmp = new Customers[newSize];
        for (int i = 0; i < t_rec.noOfRecords; i++)
        {
            tmp[i] = t_rec.ptr_rec[i];
        }
        tmp[t_rec.noOfRecords] = c_rec;
        delete [] t_rec.ptr_rec;
        t_rec.ptr_rec = tmp;
        */
    }
    
    void display(const Customers& c_rec)
    {
        cout << c_rec.user_name << ", " 
            << c_rec.likes_count << ", "
            << c_rec.retweets_count << ", "
            << c_rec.replies_count << ", "
            << c_rec.share_videos << endl;
    }

    void display(const CustomersRecord& t_rec)
    {
        int i, record = 0;
        for (i = 0; i < t_rec.noOfRecords; i++)
        {
            record = i + 1;
            cout << record << ". ";
        }
    }

}