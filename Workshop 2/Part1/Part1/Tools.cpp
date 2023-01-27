/***********************************************************************
// OOP244 Workshop 2 p1: Tools cpp file
//
// File:  Tools.cpp
// Due date: Friday, 01/27/2023
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//
// -----------------------------------------------------------
// Name: Hoang Phan
// Seneca ID: 10166229
// Seneca email: pphan-thanh-hoang@myseneca.ca
// Date: 01/27/2023 winter 2023
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }

    // To Do: read functions (4 overloaded read functions)
    int read(char data[]) {
        return fscanf(fp, "%60[^\n]\n", data) == 1;
    }

    int read(int &data) {
        return fscanf(fp, "%d,", &data) == 1;
    }

    int read(double &data) {
        return fscanf(fp, "%lf,", &data) == 1;
    }

    int read(char &data) {
        return fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &data) == 1;
    }

    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}