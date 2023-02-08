/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name  : Zoey Lin
Student ID#: 139452221
Email      : zlin104@myseneca.ca
Date       : 2023/02/02
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {

    void Department::updateName(const char* newname)
    {
        if (newname[0] != '\0')
        {
            if (this->name)
            {
                delete[] this->name;
            }
            this->name = new char[std::strlen(newname) + 1];
            std::strcpy(this->name, newname);
        }
    }

    void Department::updateBudget(double change)
    {
        this->budget += change;
    }

    bool Department::addProject(Project& newproject)
    {
        bool success = false;
        double totalCost = newproject.m_cost + totalexpenses();
        if (totalCost < this->budget)
        {
            success = true;
            if (nProject == 0)
            {
                projects = new Project;
                this->projects[0] = newproject;
                nProject++;
            }
            else
            {
                
                int newSize = nProject + 1;
                Project* tmp = new Project[newSize];
                int i;
                for (i = 0; i < nProject; i++)
                {
                    tmp[i] = projects[i];
                }
                tmp[i] = newproject;
                delete[] this->projects;
                nProject++;
                projects = tmp;
                /*this->projects = new Project[newSize];
                this->projects = tmp;
                delete[] tmp; */               
            }
        }
        return success;
    }

    void Department::createDepartment(const char* newname,
        Project& newproject, double change)
    {
        updateBudget(change);
        if (addProject(newproject))
        {
            updateName(newname);
        }
    }

    Project* Department::fetchProjects() const
    {
        return projects;
    }

    int Department::fetchNumProjects() const
    {
        return nProject;
    }

    double Department::fetchBudget() const
    {
        return this->budget;
    }

    char* Department::fetchName() const
    {
        return this->name;
    }

    double Department::totalexpenses()
    {
        int i;
        double expense{};
        for (i = 0; i < nProject; i++)
        {
            expense += projects[i].m_cost;
        }
        return expense;
    }

    double Department::remainingBudget()
    {
        double rest;
        rest = budget - totalexpenses();
        return rest;
    }

    void Department::clearDepartment()
    {
        delete[] this->name;
        delete[] projects;
    }



    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
        Project* temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget()
            << " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++) {
            display(temp[i]);
        }
    }

}