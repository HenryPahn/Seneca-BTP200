/***********************************************************************
// OOP244 Workshop 3 p1: Department cpp file
//
// File:  Department.cpp
// Due date: Friday, 02/03/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 02/03/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {
    // completed
    // SECTION: update Department information 
    // update department's name
    void Department::updateName(const char* newname)
    {
        if (newname[0] != '\0')
        {
            if (this->d_name) delete[] this->d_name;
            this->d_name = new char[std::strlen(newname) + 1];
            std::strcpy(this->d_name, newname);
        } 
    }

    // update department's budget
    void Department::updateBudget(double change)
    {
        this->d_budget += change; 
    }

    // add a Project to Department
    bool Department::addProject(Project& newproject)
    {
        if (remainingBudget() - newproject.m_cost > 0)
        {
            if (!noOfProjects)
            {
                this->d_Projects = new Project[1];
                this->d_Projects[0] = newproject;
                this->noOfProjects++;
            }
            else
            {
                Project* temp = new Project[noOfProjects + 1];
                int i{};
                for ( ; i < noOfProjects; i++)
                    temp[i] = d_Projects[i];
                temp[noOfProjects++] = newproject;
                delete[] this->d_Projects;
                this->d_Projects = new Project[noOfProjects];
                for (int j = 0; j < noOfProjects; j++)
                    this->d_Projects[j] = temp[j];
                delete[] temp;
            }
            return true;
        }
        return false;
    }

    // create a Department by update name, budget, and add projects
    void Department::createDepartment(const char* newname, Project& newproject, double change)
    {
        updateName(newname);
        if(addProject(newproject))
            updateBudget(change);
    }

    // SECTION: retrieve department's data
    // retrieve list of projects
    Project* Department::fetchProjects() const
    {
        return d_Projects;
    }
    
    // retrieve number of projects
    int Department::fetchNumProjects() const
    {
        return noOfProjects;
    }

    // retrieve department's budget
    double Department::fetchBudget() const
    {
        return d_budget;
    }

    // retrieve department's name
    char* Department::fetchName() const
    {
        return d_name;
    }

    // SECTION: calculation
    // return total cost of all projects
    double Department::totalexpenses()
    {
        double total{};
        for (int i = 0; i < noOfProjects; i++)
            total += d_Projects[i].m_cost;
        return total;
    }

    // return the remaining budget
    double Department::remainingBudget()
    {
        return d_budget - totalexpenses();
    }

    // SECTION: clear all the used memmory
    void Department::clearDepartment()
    {
        delete[] d_name;
        delete[] d_Projects;
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