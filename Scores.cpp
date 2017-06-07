/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Program Design & Arrays
 * Class         : CS 301
 * Due Date      : 2/11/14
 ************************************************************************/

#include "Scores.h"


// CONSTRUCTOR -- Default constructor
Scores::Scores()
{
	contentScore 	  = -1;
	presentationScore = -1;


}

// CONSTRUCTOR -- Each of the class data members is passed in and stored
Scores::Scores(int inContentScore,
		       int inPresentationScore)

{
	contentScore      = inContentScore;
	presentationScore = inPresentationScore;
}

int Scores::ReturnContentScore()
{
	return contentScore;
}

int Scores::ReturnPresentationScore()
{
	return presentationScore;
}

void Scores::ChangeContentScore(int inContentScore)
{
	contentScore = inContentScore;
}

void Scores::ChangePrensentationScore(int inPrensentationScore)
{
	presentationScore = inPrensentationScore;
}

void Scores::Print()
{
	cout << "    " << setw(2) <<  presentationScore << "      | "
		 << "   " << setw(2) <<  contentScore      << "   | ";
}
