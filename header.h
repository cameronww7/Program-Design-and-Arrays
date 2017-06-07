/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Program Design & Arrays
 * Class         : CS 301
 * Due Date      : 2/11/14
 ************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>

#include "Student.h"

using namespace std;

const int   STUDENT_MAX    = 50;
const int   MAX_SCORE      = 11;
const int   MIN_SCORE      = -1;
const float CONTENT_WEIGHT = .4;
const float PRESENT_WEIGHT = .6;

Student PromptUserForStudent();

int promptUserNumStudents();

void DisplayMenuTop();

void AverageWClassArray(float  &contentAverage,
			    	    float  &presentAverage,
			    	   	Student arrayStudents[],
			    	   	int     numOfStudents);
float AverageGeneric(int inArray[],
					 int numOfStudents);

int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int    IN_MIN,			// IN & OUT		- minimum option
		 	 	const int    IN_MAX);			// IN & OUT		- maximum option

void SortName(Student arrayStudents[],
	 	  	  	 int  numOfStudents);

void CalFinalScore(float   finalScores[],
				   Student arrayStudents[],
				   int     numOfStudents);

void DisplayHistogram(float   finalScores[],
			 	 	  int     numOfStudents);

#endif /* HEADER_H_ */
