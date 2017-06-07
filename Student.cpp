/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Program Design & Arrays
 * Class         : CS 301
 * Due Date      : 2/11/14
 ************************************************************************/

#include "Student.h"



// CONSTRUCTOR -- Default constructor
Student::Student() : Scores()
{
	name	= "n/a";
	firstName = "n\a";
	lastName = "n/a";
	id       = -1;

}

// CONSTRUCTOR -- Each of the class data members is passed in and stored
Student::Student(string inName,
				 int    inId,
				 int    inContentScore,
				 int	inPresentationScore)
				 	 :Scores(inContentScore,
				 			 inPresentationScore)

{
	name 	  = inName;
	id        = inId;
}

void Student::ChangeStudentName(string inName)
{
	name = inName;
}

void Student::ChangeStudentId(int inId)
{
	id        = inId;
}

void Student::PrintStudent()
{
	cout << id << " : "<< name << endl;
}

string Student::ReturnName()
{
	return name;
}

string Student::ReturnLastname()
{
	FindLastAndFirst();
	return lastName;
}

void Student::FindLastAndFirst()
{
	string firstNameTemp 	= "";
	string lastNameTemp		= "";
	string middleName 		= "";
	string temp 			= "";
	int    counter 			= 0;
	int    index 			= 0;
	int    nameSize;

	nameSize = name.length();

	while(nameSize != counter)
	{
		temp = temp + name[counter];

		if(name[counter] == ' ')
		{

			switch(index)
			{
			case 0 : firstName  = temp;
				break;
			case 1 : lastName = temp;
				break;
			}
			index++;
			temp = "";
		}
		counter++;
	}
	lastName  = temp;
}


void Student::Print()
{

	cout << left;
	cout << "\t|" << setw(10) <<  id << " | "<< setw(25) << name << "  |  ";
	Scores::Print();
	cout << right;

}



