/***********************************************************************
// OOP244 Workshop 4 p1: Tournament cpp file
//
// File:  Tournament.cpp
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
#include "Tournament.h"
using namespace std; 

namespace sdds
{
	// SECTION: add all information of a touornament
	// set all information of a tournament
	void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer)
	{
		bool check = name && strlen(name) && noOfteam;
		if (check)
		{
			this->m_num = noOfteam;
			this->m_name = new char[strlen(name) + 1]; 
			strcpy(m_name, name);

			m_soccer = new SoccerTeam[m_num];
			for (int i = 0; i < m_num; i++)
				m_soccer[i] = soccer[i];
		}
		else
		{
			setEmpty();
		}
	}

	// remove all information of the tournament
	void Tournament::setEmpty()
	{
		this->m_name = nullptr;
		this->m_soccer = nullptr;
		this->m_num = 0;
	}

	// SECTION: support function 
	// check the tournament information whether empty or not
	bool Tournament::isEmpty() const
	{
		return m_name && m_soccer && m_num;
	}

	// modify the match between 2 teams
	Tournament& Tournament::match(const SoccerTeam* ls)
	{
		for (int i = 0; i <1; i++) {
			if (m_soccer[i].fouls() < m_soccer[i + 1].fouls()) {
				m_soccer[i + 1].m_noFouls *= 2;
				m_soccer[i + 1].calFines();
				m_soccer[i].m_goals++;
				if (m_soccer[i + 1].m_noFouls > MAX_FOUL) {
					m_soccer[i + 1].m_noFouls = -1;
				}
			}
		}
		return *this;
	} 

	// SECTION: display function
	std::ostream& Tournament::display() const
	{
		std::ostream& out = cout;
		bool check = m_name && strlen(m_name) && m_num;
		if (check)
		{
			out.setf(ios::fixed);
			out << "Tournament name: " << m_name << endl;
			out << "list of the teams" << endl;
			out.width(45);
			out << "Fines"; 
			out.width(10);
			out << "Fouls"; 
			out.width(10); 
			out << "Goals" << endl;
			out.unsetf(ios::fixed);
			for (int i = 0; i < m_num; i++)
			{
				cout << "Team[" << i + 1 << "] :";
				m_soccer[i].display() << endl;
			}
		}
		else
		{
			cout << "Invalid Tournament";
		}
		return cout;
	}

	// SECTION: constructors
	// default constructor
	Tournament::Tournament()
	{
		setEmpty();
	}

	// constructor with 3 arguments
	Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer)
	{
		setTournament(name, noOfteam, soccer);
	}

	// deconstructor
	Tournament::~Tournament()
	{
		delete[] this->m_name; 
		delete[] this->m_soccer;
	}
}