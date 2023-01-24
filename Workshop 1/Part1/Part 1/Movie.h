#pragma once
/***********************************************************************
// OOP244 Workshop 1 p1: Movie header file
//
// File:  Movie.h
// Due date: Friday, 01/20/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 01/16/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_MOVIE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define SDDS_MOVIE_H
	#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "File.h"

namespace sdds
{
	struct Movie
	{
		char m_title[128];
		int m_year;
		char m_rating[6];
		int m_duration;
		char m_genres[10][11];
		float m_consumerRating;
	};

	bool loadMovies();
	bool hasGenre(const Movie* mvp, const char genre[]);
	void displayMovie(const Movie* mvp);
	void displayMoviesWithGenre(const char genre[]);
}

#endif