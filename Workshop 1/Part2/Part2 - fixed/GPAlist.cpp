/***********************************************************************
// OOP244 Workshop 1 p2: GPA list cpp file
//
// File:  GPAlist.cpp
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

#include "GPA.h"
#include "File.h"
#include "UI.h"
#include "GPAlist.h"
using namespace std; 

GPA students[86];

namespace sdds
{
    int size{}; // Number of students read

    // SECTION: loads all the students into the global array of structures.
    bool gpaQuery(const char* filename)
    {
        GPA student;
        bool flag = true;
        if (openFile(filename))
        {
            while (flag && size < 86)
            {
                flag = readName(student.name) &&
                    readSTNO(&student.stno) &&
                    readGPA(&student.gpa);
                if (flag) students[size++] = student;
            }
            closeFile();
            menu();
        }
        return size == 86;
    }

    // SECTION: sort list of students
    // swap 2 students
    void swapStudents(GPA& st1, GPA& st2) 
    {
        GPA t = st1;
        st1 = st2;
        st2 = t;
    }

    // compare 2 students' stno
    bool compareStudents(const GPA st1, const GPA st2) 
    {
        if (st1.stno > st2.stno) return 1;
        return 0;
    }

    // sort student list
    void sortStudents(GPA* list, const int n) 
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (compareStudents(list[j], list[j + 1]))
                    swapStudents(list[j], list[j + 1]);
    }

    // SECTION: display data as user's input
    // display students has GPA approximate value to user's input
    void displayApproximateGPA(const double target)
    {
        GPA* list = new GPA[86];
        int index{};
        for (int i = 0; i < size; i++)
            if (students[i].gpa == target)
                list[index++] = students[i];
        sortStudents(list, index);
        for (int i = 0; i < index; i++)
            cout << "[" << i + 1 << "] " << list[i].stno << ": " << fixed << setprecision(1) << list[i].gpa << " (" << list[i].name << ")\n";
        delete[] list;
    }

    // display students has GPA greater value than user's input
    void displayGreaterGPA(const double target)
    {
        GPA* list = new GPA[86];
        int index{};
        for (int i = 0; i < size; i++)
            if (students[i].gpa > target)
                list[index++] = students[i];
        sortStudents(list, index);
        for(int i = 0; i < index; i++)
            cout << "[" << i + 1 << "] " << list[i].stno << ": " << fixed << setprecision(1) << list[i].gpa << " (" << list[i].name << ")\n";
        delete[] list;
    }

    // display students has GPA lower value than user's input
    void displayLowerGPA(const double target)
    {
        GPA* list = new GPA[86];
        int index{};
        for (int i = 0; i < size; i++)
            if (students[i].gpa < target)
                list[index++] = students[i];
        sortStudents(list, index);
        for (int i = 0; i < index; i++)
            cout << "[" << i + 1 << "] " << list[i].stno << ": " << fixed << setprecision(1) << list[i].gpa << " (" << list[i].name << ")\n";
        delete[] list;
    }
}

