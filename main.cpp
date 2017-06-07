/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Program Design & Arrays
 * Class         : CS 301
 * Due Date      : 2/11/14
 ************************************************************************/

#include "header.h"



/************************************************************************
 *
 * _______________________________________________________________________
 *
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ************************************************************************/
int main()
{
	int numOfStudents         = 0;
	float contentAverage      = 0;
	float presentationAverage = 0;

	Student arrayStudents[STUDENT_MAX];
	float   finalScore[STUDENT_MAX];

	Student temp;

	for(int index = 0; index < STUDENT_MAX; index++)
	{
		finalScore[index] = 0;
	}

	numOfStudents = promptUserNumStudents();

	//gets students
	for(int index = 0; index < numOfStudents; index++)
	{
		cout << "\t\nStudent # " << (index + 1);
		arrayStudents[index] = PromptUserForStudent();
	}
	//	sorts names
	SortName(arrayStudents,
		 	  numOfStudents);

	// averages the scores
	if(numOfStudents > 2)
	{
		AverageWClassArray(contentAverage,
					   presentationAverage,
					   arrayStudents,
					   numOfStudents);
	}

//	//populates basic arrays for averaging
//	for(int index = 0; index < numOfStudents; index++)
//	{
//		contentArray[index] = arrayStudents[index].ReturnContentScore();
//		presentArray[index] = arrayStudents[index].ReturnPresentationScore();
//	}
//
//	contentAverage      = AverageGeneric(contentArray,
//			 	 	 	 	 	 	     numOfStudents);
//	presentationAverage = AverageGeneric(presentArray,
//	 	 	 		 	 	             numOfStudents);


	CalFinalScore(finalScore,
				  arrayStudents,
				  numOfStudents);

	// Displays Students
	DisplayMenuTop();
	for(int index = 0; index < numOfStudents; index++)
	{
		arrayStudents[index].Print();
		cout << "    " << fixed << setprecision(2) << setw(4) << finalScore[index] << "    |";
		cout << endl;
	}
	cout << "\t|_________________________________________"
			"______________________________________|\n";

	if(contentAverage == 0 || presentationAverage == 0)
	{
		cout << "\nAverage Content Score      : Student Population too Small";
		cout << "\nAverage Presentation Score : Student Population too Small";
	}
	else
	{
		cout << "\nAverage Content Score      : " << contentAverage;
		cout << "\nAverage Presentation Score : " << presentationAverage;
	}
	cout << endl << endl;

	//displays a Histogram of Averaged Scores
	DisplayHistogram( finalScore,
				 	 numOfStudents);




	return 0;
}



/************************************************************************
 * int promptUserNumStudents()
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
int promptUserNumStudents()
{
	return NumberError("Enter Number of Students : ", 0,32);
}


/************************************************************************
 * void DisplayMenuTop()
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
void DisplayMenuTop()
{
	cout << "\n\t _______________________________________________________________________________\n";
	cout <<   "\t|    ID     |       Student Name         | Presentation | Content | Final Score |\n";
	cout <<   "\t|-----------|----------------------------|--------------|---------|-------------|\n";
}


/************************************************************************
 *Student PromptUserForStudent()
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
Student PromptUserForStudent()
{
	Student tempStudent;
	string  tempName;
	int     tempId;
	int 	tempContentScore;
	int 	tempPresentationScore;


	cout << "\nEnter Student's Name      : ";
	getline(cin, tempName);

	tempId 				  = NumberError("Enter Student's Id Number : ", 0,100000);
	tempContentScore      = NumberError("Enter Content Score       : ", 0,10);
	tempPresentationScore = NumberError("Enter Presentation Score  : ", 0,10);


	tempStudent.ChangeStudentName(tempName);
	tempStudent.ChangeStudentId(tempId);
	tempStudent.ChangeContentScore(tempContentScore);
	tempStudent.ChangePrensentationScore(tempPresentationScore);


	return tempStudent;
}



/************************************************************************
 * void AverageWClassArray
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
void AverageWClassArray(float  &contentAverage,
			 	 	    float  &presentAverage,
			 	 	   	Student arrayStudents[],
			 	 	   	int     numOfStudents)
{
	float conAverage    = 0.0;
	float preAverage    = 0.0;
	int topScoreCon     = MIN_SCORE;
	int topScorePre     = MIN_SCORE;
	int lowScoreCon     = MAX_SCORE;
	int lowScorePre     = MAX_SCORE;
	int totalCon        = 0;
	int totalPre        = 0;

	for(int index = 0; index < numOfStudents; index++)
	{
		if(arrayStudents[index].ReturnContentScore() > topScoreCon)
		{
			topScoreCon = arrayStudents[index].ReturnContentScore();
		}
		if(arrayStudents[index].ReturnContentScore() < lowScoreCon)
		{
			lowScoreCon = arrayStudents[index].ReturnContentScore();
		}
		totalCon = totalCon + arrayStudents[index].ReturnContentScore();
	}

	for(int index = 0; index < numOfStudents; index++)
	{
		if(arrayStudents[index].ReturnPresentationScore() > topScorePre)
		{
			topScorePre = arrayStudents[index].ReturnPresentationScore();
		}
		if(arrayStudents[index].ReturnPresentationScore() < lowScorePre)
		{
			lowScorePre = arrayStudents[index].ReturnPresentationScore();
		}

		totalPre = totalPre + arrayStudents[index].ReturnPresentationScore();
	}

	totalCon = totalCon - topScoreCon - lowScoreCon;
	totalPre = totalPre - topScorePre - lowScorePre;
	numOfStudents = numOfStudents - 2;

	conAverage = totalCon / float(numOfStudents);
	preAverage = totalPre / float(numOfStudents);

	contentAverage = conAverage;
	presentAverage = preAverage;


}


/************************************************************************
 * float AverageGeneric
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
float AverageGeneric(int inArray[],
					 int numOfStudents)
{
	float average  = 0.0;
	int   topScore = MIN_SCORE;
	int   lowScore = MAX_SCORE;
	int   total    = 0;

	for(int index = 0; index < numOfStudents; index++)
	{
		if(inArray[index] > topScore)
		{
			topScore = inArray[index];
		}
		if(inArray[index] < lowScore)
		{
			lowScore = inArray[index];
		}

		total = total + inArray[index];
	}

	total = total - topScore - lowScore;
	numOfStudents = numOfStudents - 2;

	average = total / float(numOfStudents);

	return average;
}


/************************************************************************
 * void SortName
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
void SortName(Student arrayStudents[],
	 	  	  	 int     numOfStudents)
{

	Student temp;
	int i;
	int j;

	//inilization
	j = 0;


	//Calculation
	for(i= 1; i < numOfStudents; ++i)
	{
		//makes temp become the first int and compares
		temp = arrayStudents[i];
		j = i -1;
		while ( j >= 0 && arrayStudents[j].ReturnLastname() > temp.ReturnLastname())

		{
			arrayStudents[ j + 1] = arrayStudents[j];
			j = j - 1;
		}
		arrayStudents[j + 1] = temp;
	}
}

void CalFinalScore(float   finalScores[],
				   Student arrayStudents[],
				   int     numOfStudents)

{
	float temp = 0.0;

	for(int index = 0; index < numOfStudents; index++)
	{
//		cout << endl << " CalFin Con" << arrayStudents[index].ReturnContentScore();
//		cout << endl << " CalFin Pre" << arrayStudents[index].ReturnPresentationScore();
//		cout << endl;
		temp =(arrayStudents[index].ReturnContentScore()      * CONTENT_WEIGHT)
															  +
			  (arrayStudents[index].ReturnPresentationScore() * PRESENT_WEIGHT);

		finalScores[index] = temp;
	}



}




/************************************************************************
 * void DisplayHistogram
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
void DisplayHistogram(float   finalScores[],
			 	 	  int     numOfStudents)
{
	int count = 0;
	int temp;
	cout << setfill('*');

	for(int index1 = 0; index1 < 11; index1++)
	{
		for(int index2 = 0; index2 < numOfStudents; index2++)
		{
			temp = finalScores[index2];
			if(temp == index1)
			{
				count = count + 1;
			}

		}
		if(count >= 1)
		{
			cout <<  setfill(' ') << setw(2) << index1 << "-< " <<setfill('*')
				 << setw(count) << "*" ;
		}
		else
		{
			cout << setfill(' ') << setw(2) << index1 << "-< " << setfill('*');
		}
		cout << endl;
		count = 0;

	}
	cout << setfill(' ');





}


/************************************************************************
 *  int NumberError
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int IN_MIN,			// IN & OUT		- minimum option
		 	 	const int IN_MAX)			// IN & OUT		- maximum option
{
	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	int option;						// IN & OUT		- user input choice

	do
	{
		someBool = false;

		// OUTPUT - the menu
		cout << MENU_FORMAT;

		/*****************************************************************
		 * This is a check for the user's input. It will first check
		 * 	if the user has put in a vaild number, if invaild it will
		 *	clear the input then reoutput the menu until and do the
		 *	check's until the user puts in a vaild entry.
		 *****************************************************************/
		if(!(cin >> option))
		{
			cout << "\n**** Please input a NUMBER between " << IN_MIN
				 << " and " << IN_MAX << " ****";
			cin.clear();

			someBool  = true;
			cout << endl << endl;
		}
		else if (option > IN_MAX || option < IN_MIN)
		{
			cout << endl;
			cout << "**** The number " << option << " is an invalid "
					"entry     ****\n";
			cout << "**** Please input a number between "
				 << IN_MIN << " and " << IN_MAX << " ****\n";
			cout << endl;
			someBool = true;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(someBool);

	return option;
}

