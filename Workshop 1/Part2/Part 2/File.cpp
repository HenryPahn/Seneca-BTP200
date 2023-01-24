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
// Date: 01/19/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "GPAlist.h"
using namespace std;

namespace sdds
{
    void retrieveData(const char* filename, GPA* students, int &i) // Retrieve information from file, and assign to dynamic array
    {
        ifstream f(filename); 

        while (!f.eof()) // while file is still not end
        {
            char comma;

            // assign data from the file to variables
            f.get(students[i].name, 100, ',');
            f >> comma; // get rid of redudant comma between students name and number in the file
            f >> students[i].stno;
            f >> comma; // get rid of redudant comma between students number and gpa in the file
            f >> students[i].gpa;
            i++;
        }

        // Add a space to the first student name 
        int size{};
        while (students[0].name[size] != '\0') size++;
        for (int i = size; i > 0; i--)
            students[0].name[i] = students[0].name[i - 1];
        students[0].name[0] = ' ';
        students[0].name[size + 1] = '\0';

        i--; // the last element in students GPA array is the blank cause it is the end of the file so, the index does not include it

    }

    void swapStudents(GPA& st1, GPA& st2) // swap 2 students
    {
        GPA t = st1;
        st1 = st2;
        st2 = t;
    }

    bool compareStudents(const GPA st1,const GPA st2) // compare 2 students' gpa
    {
        if(st1.gpa > st2.gpa) return 1; 
        return 0;
    }

    void sortStudents(GPA* students, const int n) // sort student list
    {
        for (int i = 0; i < n - 1; i++) 
            for (int j = 0; j < n - i - 1; j++)
                if (compareStudents(students[j], students[j + 1]))
                    swapStudents(students[j], students[j + 1]);  
    }

	void approximateGPA(GPA* students, const int size, const double targetGPA) // display students with gpa equal to user's target
	{        
        int index{1};

        for (int i = 0; i < size; i++)
            if (students[i].gpa == targetGPA)
            {
                cout << "[" << index++ << "] " << students[i].stno << ": " << fixed << setprecision(1) << students[i].gpa << " (";
                int j = 1;
                while (students[i].name[j] != '\0') cout << students[i].name[j++];
                cout << ")\n";
            }
                
	}

	void greaterGPA(GPA* students, const int size, const double targetGPA) // display students with gpa greater than user's target 
	{
        GPA* temp = new GPA[100];
        int index{ 0 };

        // Get subarray that contains students with gpa greater than user's target 
        for (int i = 0; i < size; i++)
            if (students[i].gpa > targetGPA)
                temp[index++] = students[i];

        sortStudents(temp, index); // sort students gpa

        for (int i = 0; i < index; i++)
        {
            cout << "[" << i + 1 << "] " << temp[i].stno << ": " << fixed << setprecision(1) << temp[i].gpa << " (";
            int j = 1;
            while (temp[i].name[j] != '\0') cout << temp[i].name[j++];
            cout << ")\n";
        }

        delete[] temp;
	}

	void lowerGPA(GPA* students, const int size, const double targetGPA) // display students with gpa lower than user's target
	{
        GPA* temp = new GPA[100];
        int index{ 0 };

        // Get subarray that contains students with gpa lower than user's target
        for (int i = 0; i < size; i++)
            if (students[i].gpa < targetGPA)
                temp[index++] = students[i];

        sortStudents(temp, index); // sort students gpa

        for (int i = 0; i < index; i++)
        {
            cout << "[" << i + 1 << "] " << temp[i].stno << ": " << fixed << setprecision(1) << temp[i].gpa << " (";
            int j = 1;
            while (temp[i].name[j] != '\0') cout << temp[i].name[j++];
            cout << ")\n";
        }

        delete[] temp;
	}
}

