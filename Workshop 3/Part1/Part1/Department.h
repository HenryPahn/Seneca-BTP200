/***********************************************************************
// OOP244 Workshop 3 p1: Department header file
//
// File:  Department.h
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

#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_

namespace sdds {
    const int MAX_TOPIC_LENGTH = 25;

    struct Project {
        char m_topic[MAX_TOPIC_LENGTH+1];
        double m_cost;
    };

	//class Department does here
	class Department
	{
        char* d_name;
        Project* d_Projects;
        int noOfProjects;
        double d_budget = 15345.99;
	public:
        void updateName(const char* newname);
        void updateBudget(double change);
        bool addProject(Project& newproject);
        void createDepartment(const char* newname, Project& newproject, double change);
        Project* fetchProjects() const;
        int fetchNumProjects() const;
        double fetchBudget() const;
        char* fetchName() const;
        double totalexpenses();
        double remainingBudget();
        void clearDepartment();
     };
        
	//helper functions - do not belong inside the class
    void display(const Project& project);
    void display(const Department& department);
}
#endif // !SDDS_DEPARTMENT_H_