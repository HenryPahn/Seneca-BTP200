/***********************************************************************
// OOP244 Workshop 4 p1: Soccer header file
//
// File:  Soccer.h
// Due date: Friday, 02/10/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 02/10/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_SOCCERTEAM_H_
#define SDDS_SOCCERTEAM_H_
#include <iostream>
#include <cstring>
#include <iomanip>


namespace sdds
{
    const int MAX_FOUL = 4; // maximum number of fouls

    struct SoccerTeam
    {
        char m_teamName[41]; // a statically allocated Cstring with size 41. Remember, name could be 
        // maximum 40 characters long and 1 byte is for the null byte.
        int m_noFouls; // number of fouls, it can be zero or more but cannot be a negative number
        double m_fines; // it can be equal to and more than zero.
        int m_goals; // can be zero or more

        void setTeam(const char* tname, double fines, int foul);
        void setName(const char* tname);
        void setFine(double fines, int foul);
        void setEmpty();
        bool isEmpty() const;
        void calFines();
        int fouls() const;

        SoccerTeam();
        SoccerTeam(const char* tname, double fines, int foul);
        std::ostream& display() const;   
    };
}

#endif