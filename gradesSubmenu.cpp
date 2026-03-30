#include <sstream>
#include <fmx.h>
#pragma hdrstop

#include "gradesSubmenu.h"  // gradesSubmenu header file
#include "studentSubmenu.h" // studentSubmenu header file

using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
T_gradesSubmenu *gradesSubmenu;

//------------------------CONSTRUCTOR------------------------------

__fastcall T_gradesSubmenu::T_gradesSubmenu(TComponent* Owner)
	: TForm(Owner), _studentRecordList(new StudentRecordList())
{                   // Initializes and dynamically allocates memory for
}                   // a StudentRecordList object

//------------------------backButtonClick------------------------------------
void __fastcall T_gradesSubmenu::backButtonClick(TObject *Sender)
{
	// Clear the edit and label fields before closing the current form
	idEdit->Text = "";
	displaySubjectLabel->Text = "";
	displayGradeLabel->Text = "";
	displayGpaLabel->Text = "";
	// Close the gradesSubmenu form
	this->Close();
	// Shows the _studentSubmenu form
	_studentSubmenu->Show();
}

//----------------------TO SET THE CURRENT LOGGED ID---------------------------------

void T_gradesSubmenu::SetLoggedInStudentID(int studentID)
{
	_loggedInStudentID = studentID; // Set the logged-in student ID
}

//------------------------TO SEARCH THE GRADES------------------------------

void __fastcall T_gradesSubmenu::SearchEditButton1Click(TObject *Sender)
{
	int studentID;  // Get the student ID entered in the idEdit field

	//If an exception occurs during the conversion (the input is not a valid integer),
	//the code execution jumps to the catch block.
	try
	{
		studentID = StrToInt(idEdit->Text.Trim()); // Convert text from idEdit to integer
	}
	catch (...)
	{
		ShowMessage("Please enter a valid student ID."); // Show message for invalid ID format
		return;
	}

	// Validate if the entered studentID matches the loggedInStudentID
	if (studentID != _loggedInStudentID)
	{
		ShowMessage("You can only view your own grades."); // Show message if IDs don't match
		return;
	}

	string allGrades = "";  // String to concatenate al grades and marks
	string allSubjects = "";    // String to concatenate all subjects
	bool found = false; // Bool variable used when searching a record
	float sumMarks = 0; // Variable to store the overall GPA
	int count=0;    // Variable to store the count of how many grades there are for a student

    // Search for grades associated with the logged-in student ID (_loggedInStudentID)
	StudentRecord* current = _studentRecordList->getHead(); // Traverse the linked list from the head
	while (current != nullptr)                              // unitl the end
	{
		if (current->id == _loggedInStudentID)  // If and id from the linked list matches with the id entered
		{
			allSubjects += current->subject + "\n"; // Saves the subject into the string
		   	allGrades += to_string(current->mark) + "\t";   // Saves the grade into the string
			allGrades += current->grade + "\n";   // Saves the grade into the string

			found = true;   // Set found to true (a record was found)
			sumMarks += current->mark;  // Summ the marks and saves into the
			count++;
		}
		current = current->next;    // Update the current to be the next float variable
	}

	float GPA=0.0;    //variable to store the GPA
	GPA = sumMarks/count;   // Calculates the GPA by dividend the sum of marks by the number of marks

	if (found)  // If the record for the student was found
	{
		UnicodeString gpaString = FloatToStrF(GPA, ffFixed, 7, 2);  // convert (7 numbers and 2 decimals)

		displaySubjectLabel->Text = UnicodeString(allSubjects.c_str());   // Display the subjects in the displaySubjectLabel
		displayGradeLabel->Text = UnicodeString(allGrades.c_str()); // Display the grades in the displayGradesLabel
		displayGpaLabel->Text = "Your overall GPA is: " + gpaString;    // Display the GPA in the displayGpaLabel
	} else
	{
		ShowMessage("No grades found for your student ID!"); // Show message if no record found
		displayGradesLabel->Text = ""; // Clear display label if no record found
	}
}


