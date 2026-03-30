//---------------------------------------------------------------------------
#include <fmx.h>
#pragma hdrstop

#include "searchRecordMenu.h"
#include "professorSubmenu.h"

#include "StudentRecordList.h" // Include the StudentRecordList header

using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
T_searchRecordMenu *_searchRecordMenu;

//---------------------------------------------------------------------------

__fastcall T_searchRecordMenu::T_searchRecordMenu(TComponent* Owner)
	: TForm(Owner), _studentRecordList(new StudentRecordList()) // Initialize _studentRecordList
{
}

//---------------------------------------------------------------------------

void __fastcall T_searchRecordMenu::backButtonClick(TObject *Sender)
{
	// Clear the edit fields
	idEdit->Text = "";
	subjectEdit->Text = "";
    displayRecordLabel->Text = "";

	// Close this form (searchRecordMenu)
	this->Close();

	// Show the _professorSubmenu form
	_professorSubmenu->Show();
}

//---------------------------------------------------------------------------

void __fastcall T_searchRecordMenu::SearchEditButton1Click(TObject *Sender)
{
    int id = StrToInt(idEdit->Text); // Convert text from idEdit to integer
	string subject = AnsiString(subjectEdit->Text).c_str(); // Convert subjectEdit text to string

    // Ensure professorSubject is set
	if (subject.empty())
	{
        ShowMessage("Please enter a subject!");
        return;
    }

    // Search for record in the StudentRecordList instance
	StudentRecord* foundRecord = _studentRecordList->searchRecord(id, subject);

	if (foundRecord)
	{
		// Display the found record in displayRecordLabel
		string recordText = "Information of the Student: \nID: " + to_string(foundRecord->id) + "\n";
        recordText += "Subject: " + foundRecord->subject + "\n";
        recordText += "Mark: " + to_string(foundRecord->mark) + "\n";
		recordText += "Final Grade: " + foundRecord->grade;

        displayRecordLabel->Text = recordText.c_str();
	}
	else
	{
        ShowMessage("Record not found for the given ID and subject!");
        displayRecordLabel->Text = ""; // Clear display label if no record found
	}
}



