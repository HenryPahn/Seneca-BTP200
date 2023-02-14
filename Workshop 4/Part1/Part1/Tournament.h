/***********************************************************************
// OOP244 Workshop 4 p1: Tournament header file
//
// File:  Tournament.h
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

#ifndef SDDS_TOURNAMENT_H_
#define SDDS_TOURNAMENT_H_
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Soccer.h"

namespace sdds
{
	class Tournament
	{
		char* m_name;//points to a dynamically allocated Cstring
		int m_num;//size of the dynamically allocated array of soccer team. It should be more then zero.
		SoccerTeam* m_soccer = nullptr;//pointer to the dynamically allocated array of soccerTeam
	
	public:
		void setTournament(const char* name, int noOfteam, const SoccerTeam* soccer);
		void setEmpty();
		bool isEmpty() const;
		Tournament& match(const SoccerTeam* ls);
		std::ostream& display() const;
		
		Tournament();
		Tournament(const char* name, int noOfteam, const SoccerTeam* soccer);
		~Tournament();
	};
}

#endif