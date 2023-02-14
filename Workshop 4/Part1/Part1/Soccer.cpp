/***********************************************************************
// OOP244 Workshop 4 p1: Soccer cpp file
//
// File:  Soccer.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "Soccer.h"
using namespace std; 

namespace sdds
{
    // SECTION: add a team information
    // set the team name, fine, and fouls of the team 
    void SoccerTeam::setTeam(const char* tname, double fines, int foul)
    {
        setName(tname);
        setFine(fines, foul);
    }

    // set the team name 
    void SoccerTeam::setName(const char* tname)
    {
        if (tname && strlen(tname))
            strcpy(this->m_teamName, tname);
    }
    
    // set the fines and fouls 
    void SoccerTeam::setFine(double fines, int foul)
    {
        if (fines >= 0 && foul >= 0)
        {
            this->m_fines = fines; 
            this->m_noFouls = foul;
        }
        else
        {
            setEmpty();
        }
    }

    // delete a team information
    void SoccerTeam::setEmpty()
    {
        this->m_teamName[0] = '\0';
        this->m_noFouls = -1;
        this->m_fines = -1;
        this->m_goals = 0;
    }

    // SECTION: support function
    // check the team information where empty or not
    bool SoccerTeam::isEmpty() const
    {
        return m_teamName && m_fines && m_noFouls;
    }

    // caculate the fine of the team
    void SoccerTeam::calFines()
    {
       this-> m_fines *= 1.2;
    }

    // return the number of foul of the team
    int SoccerTeam::fouls() const
    {
        return m_noFouls;
    }

    // SECTION: constructors
    // default constructor
    SoccerTeam::SoccerTeam()
    {
        setEmpty();
    }

    // constructor SoccerTeam struct with 3 arguments
    SoccerTeam::SoccerTeam(const char* tname, double fines, int foul)
    {
        setEmpty();
        setTeam(tname, fines, foul);
    }

    // SECTION: display team information
    std::ostream& SoccerTeam::display() const
    {
        std::ostream& out = cout;
        bool check = m_teamName && strlen(m_teamName) && m_fines >= 0 && m_noFouls >= 0;
        if (check)
        {
            out.setf(ios::fixed);
            out.precision(2);
            out.fill(' ');
            out.width(30);
            out << left << m_teamName;
            out.width(6);
            out << right << m_fines;
            out.width(6);
            out << m_noFouls; 
            out.width(10);
            out << m_goals;
            if (m_goals) cout << "w";
            else out << " ";
            out.unsetf(ios::fixed);
        }
        else
        {
            cout << "Invalid Team";
        }
        return out;
    }
}