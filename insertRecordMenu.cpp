#include <fmx.h>
#pragma hdrstop
#include <System.SysUtils.hpp>
#include "insertRecordMenu.h"    // insertRecordMenu header file
#include "professorSubmenu.h"   // professorSubmenu header file
#include "StudentRecordList.h" // StudentRecordList header file

using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
T_insertRecordMenu *_insertRecordMenu;

//------------------------CONSTRUCTOR-------------------------------------

__fastcall T_insertRecordMenu::T_insertRecordMenu(TComponent* Owner)
	: TForm(Owner), _studentRecordList(new StudentRecordList()) // Initialize _studentRecordList in the constructor
{
}

//-------------------------backButtonClick---------------------------------

void __fastcall T_insertRecordMenu::backButtonClick(TObject *Sender)
{
	Close(); // Close the current form (T_insertRecordMenu)
	_professorSubmenu->Show(); // Show the professor submenu
}

//-------------------------saveButtonClick-----------------------------------

void __fastcall T_insertRecordMenu::saveButtonClick(TObject *Sender)
{
	int id = StrToInt(idEdit->Text); // Extract the text entered in idEdit, converts it to integer
	float mark = StrToFloat(markEdit->Text.Trim()); // Extract the text entered in markEdit, converts it to float
	string subject = AnsiString(subjectEdit->Text).c_str(); // Extract subject from subjectEdit and convert it to string

	string grade; // Variable to hold the grade as string

	// Determine grade based on mark
	if (mark >= 0 && mark <= 59)
	{
		grade = "D";
	}
	else if (mark >= 60 && mark <= 65)
	{
		grade = "C";
	}
	else if (mark >= 66 && mark <= 70)
	{
        grade = "C+";
	}
	else if (mark >= 71 && mark <= 76)
	{
        grade = "B";
	}
	else if (mark >= 77 && mark <= 84)
	{
        grade = "B+";
	}
	else if (mark >= 85 && mark <= 91)
	{
        grade = "A";
	}
	else if (mark >= 92 && mark <= 100)
	{
		grade = "A+";
	}
	else
	{
		ShowMessage("Invalid mark entered!"); // Display message if the mark is not between 0 and 100
		return;
	}


	// Insert record into linked list and file
	_studentRecordList->insertRecord(id, subject, mark, grade);

	// Clear the edit fields after saving
	idEdit->Text = "";
	markEdit->Text = "";
	subjectEdit->Text = "";
}



