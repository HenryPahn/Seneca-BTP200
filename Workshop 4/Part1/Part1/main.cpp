/***********************************************************************
// OOP244 Workshop 4 p1: main cpp file
//
// File:  main.cpp
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
#include<iostream>
#include"Tournament.h"
#include"Soccer.h"

using namespace std;
using namespace sdds;


void printHeader(const char* title)
{
	char oldFill = cout.fill('-');
	cout.width(65);
	cout << "" << endl;

	cout << "|> " << title << endl;

	cout.fill('-');
	cout.width(65);
	cout << "" << endl;
	cout.fill(oldFill);
}

int main()
{
	SoccerTeam st1[] = {
		SoccerTeam(), //default constructor
		SoccerTeam("",100.0,0), //3 argumnet constructor
		SoccerTeam("Bad1",200,-1)
	};

	printHeader("T1: Checking Constructors of Soccer Team");
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ". ";
		st1[i].display() << endl;
	}

	Tournament t[] = {
		Tournament(),
		Tournament(nullptr,5,st1),
		Tournament("Bad1", 0,st1)
	};

	printHeader("T2: Checking Constructors of Tournament");
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ". ";
		t[i].display() << endl;
	}

	SoccerTeam st2[] = {
		SoccerTeam("Scarborough Soccer Team",0.0,0),
		SoccerTeam("North York Soccer Team",100.0,1)
	};

	Tournament t1("Soccer Tournament", 2, st2);
	printHeader("T3: Checking valid Tournament with valid Teams");
	t1.display() << endl;

	cout << endl << "*****First match between two Teams*****" << endl;
	if (t1.match(st2).isEmpty())
	{
		printHeader("T4:Updated list with the winner");
		t1.display();
	}

	cout << endl << "*****Second match between two Teams*****" << endl;
	if (t1.match(st2).isEmpty())
	{
		printHeader("T5:Updated list with the winner");
		t1.display();
	}

	cout << endl << "*****Third match between two Teams*****" << endl;
	if (t1.match(st2).isEmpty())
	{
		printHeader("T6:Updated list with the winner");
		t1.display();
	}
	return 0;
}