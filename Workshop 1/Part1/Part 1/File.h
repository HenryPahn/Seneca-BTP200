/***********************************************************************
// OOP244 Workshop 1 p1: File header file
//
// File:  File.h
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

#pragma once
#ifndef SDDS_FILE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define SDDS_FILE_H
#include "Movie.h"

namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);
}

#endif