#include <fmx.h>
#pragma hdrstop
#include <string>    // For string operations

#include "modifyRecordMenu.h"   // modifyRecordMenu header file
#include "professorSubmenu.h"   // professorSubmenu header file
#include "studentRecordList.h"  // studentRecordList header file

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
T_modifyRecordMenu *_modifyRecordMenu;

//----------------------CONSTRUCTOR---------------------------------

__fastcall T_modifyRecordMenu::T_modifyRecordMenu(TComponent* Owner)
	: TForm(Owner)
{
	_studentRecordList = new StudentRecordList(); // Initialize _studentRecordList
}

//-----------------------backButtonClick---------------------------------

void __fastcall T_modifyRecordMenu::backButtonClick(TObject *Sender)
{
    // Clear input fields
	idEdit->Text = "";
	subjectEdit->Text = "";
	markEdit->Text = "";
	this->Close();  // Close the current form (_modifyRecordMenu)
	_professorSubmenu->Show();  // Show the _professorSubmenu
}

//--------------------------modifyButtonClick--------------------------------

void __fastcall T_modifyRecordMenu::modifyButtonClick(TObject *Sender)

{
	int id = StrToInt(idEdit->Text.Trim()); // Get ID from idEdit and convert to integer
	string subject = AnsiString(subjectEdit->Text.Trim()).c_str(); // Get subject from subjectEdit
	float mark = StrToFloat(markEdit->Text.Trim()); // Get mark from markEdit and convert to float
	_studentRecordList->modifyMark(id, subject, mark);

	// Clear input fields after updating
	idEdit->Text = "";
	subjectEdit->Text = "";
	markEdit->Text = "";
}





