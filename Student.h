/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Program Design & Arrays
 * Class         : CS 301
 * Due Date      : 2/11/14
 ************************************************************************/


#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>

using namespace std;

#include "Scores.h"

#ifndef STUDENT_H_
#define STUDENT_H_

class Student : public Scores
{
public:
	Student();
	Student(string inName,
			int    inId,
			int    inContentScore,
		    int	   inPresentationScore);

	void ChangeStudentId(int inId);
	void ChangeStudentName(string inName);
	void PrintStudent();
	void Print();
	string ReturnName();
	string ReturnLastname();
	void FindLastAndFirst();




private:
	string name;
	string firstName;
	string lastName;
	int    id;



};


#endif /* STUDENT_H_ */
