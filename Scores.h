/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Program Design & Arrays
 * Class         : CS 301
 * Due Date      : 2/11/14
 ************************************************************************/

#ifndef SCORES_S_
#define SCORES_S_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>
using namespace std;

class Scores
{
public:
	Scores();
	Scores(int inContentScore,
		   int inPresentationScore);

	int ReturnContentScore();
	int ReturnPresentationScore();

	void ChangeContentScore(int inContentScore);
	void ChangePrensentationScore(int inPrensentationScore);
	void Print();


private:
	int contentScore;
	int presentationScore;

};
#endif /* SCORES_S_ */
