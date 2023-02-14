/***********************************************************************
// OOP244 Workshop 4 p2: Name Tag cpp file
//
// File:  NameTag.cpp
// Due date: Friday, 02/15/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 02/13/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "NameTag.h"
using namespace std;

namespace sdds
{
	// SECTION: additional functions
	// set the name to the console
	void NameTag::setName(const char* t_name)
	{
		delete[] this->m_name;
		this->m_name = new char[strlen(t_name) + 1];
		strcpy(this->m_name, t_name);
	}

	// empty the current object
	void NameTag::setEmpty()
	{
		delete[] this->m_name;
		this->m_name = nullptr;
		this->m_num = -1;
	}

	// count digits of an integer
	int NameTag::countDigit(int n) const
	{
		int count = 0;
		if (n < 0) count = 1;
		while (n)
		{
			n /= 10;
			count++;
		}
		return count;
	}

	// SECTION: required functions
	// display a nametag due to the provided format
	std::ostream& NameTag::print() const
	{
		std::ostream& out = cout;
		bool check = m_name && strlen(m_name) && (countDigit(m_num) == 5 || m_num == 0);
		if (check)
		{
			int t_len = strlen(m_name); // the width of the box
			int length = strlen(m_name); // the length of the name

			if (length < 20) 
				t_len = 20;

			if (length > 40)
				t_len = 40;

			out.setf(ios::fixed);
			for (int i = 0; i < 7; i++) // display the box
			{
				if (i == 0 || i == 6) // display the top and bottom lines
				{
					out << "+";
					for (int i = 0; i < t_len + 2; i++)
						out << "-";
					out << "+\n";
				}
				else if(i == 1 || i == 3 || i == 5) // display the line without content
				{
					out << "|";
					for (int i = 0; i < t_len + 2; i++)
						out << " ";
					out << "|\n";
				}
				else if (i == 2) // display the line having name
				{
					out << "| ";
					if (t_len == 20)
					{
						out << m_name;
						for (int i = 0; i < t_len - length; i++)
							out << " ";
					}
					else if (t_len == 40)
						for (int i = 0; i < 40; i++)
							out << m_name[i];
					else
						out << m_name;
					out << " |\n";
				}
				else // display the line having extension number
				{
					const int displayExtension = 11; // the length of "extension" string
					const int displayNA = 3; // the length of "N/A" string
					out << "| Extension: ";
					if (countDigit(m_num) == 5)
					{
						out << m_num;
						for (int i = 0; i < t_len - countDigit(m_num) - displayExtension; i++)
							out << " ";
					}
					else
					{
						out << "N/A";
						for (int i = 0; i < t_len - displayNA - displayExtension; i++)
							out << " ";
					}
					out << " |\n";
				}
			}
			out.unsetf(ios::fixed); 
		}
		else
		{
			cout << "EMPTY NAMETAG!" << endl;
		}
		return out;
	}

	// read the input from user
	NameTag& NameTag::read()
	{
		cout << "Please enter the name: ";
		char temp[100];
		cin.get(temp, 41); // get the name
		setName(temp);
		while ((getchar()) != '\n');
		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		char option; // get the choice
		cin >> option;
		while (option != 'y' && option != 'Y' && option != 'n') // validate the choice
		{
			cout << "Only (Y) or (N) are acceptable, try agin: ";
			cin >> option;
		}
		if (option == 'y' || option == 'Y') // validate the extension number
		{
			cout << "Please enter a 5 digit phone extension: ";
			int phone;
			cin >> phone;
			while (cin.fail()) 
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(5, '\n');
				cin >> phone;
			}
			while (countDigit(phone) != 5) 
			{
				cout << "Invalid value [10000<=value<=99999]: ";
				cin >> phone;
			}
			m_num = phone;
		}
		else
		{
			m_num = 0;
		}
		while ((getchar()) != '\n');
		return *this;
	}

	// SECTION: constructors
	// default constructor
	NameTag::NameTag()
	{
		setEmpty();
	}

	// // constructor with a argument
	NameTag::NameTag(const char* t_name)
	{
		if (t_name && strlen(t_name))
		{
			setName(t_name);
		}
		else
		{
			setEmpty();
		}
	}

	// constructor with 2 arguments
	NameTag::NameTag(const char* t_name, int t_num)
	{
		if (t_name && strlen(t_name) && countDigit(t_num) == 5)
		{
			setName(t_name);
			m_num = t_num;
		}
		else
		{
			setEmpty();
		}
	}

	// deconstructor
	NameTag::~NameTag()
	{
		delete[] m_name;
		m_num = 0;
	}
}