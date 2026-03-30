//---------------------------------------------------------------------------
#include <fmx.h>
#pragma hdrstop
#include <string>    // For string operations

#include "deleteRecordMenu.h"
#include "professorSubmenu.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
T_deleteRecordMenu *_deleteRecordMenu;
//---------------------------------------------------------------------------
__fastcall T_deleteRecordMenu::T_deleteRecordMenu(TComponent* Owner)
	: TForm(Owner)
{
	_studentRecordList = new StudentRecordList(); // Initialize _studentRecordList
}
//---------------------------------------------------------------------------
void __fastcall T_deleteRecordMenu::backButtonClick(TObject *Sender)
{
	this->Close();
	_professorSubmenu->Show();
}
//---------------------------------------------------------------------------
void __fastcall T_deleteRecordMenu::deleteButtonClick(TObject *Sender)
{
    int id = StrToInt(idEdit->Text.Trim()); // Get ID from idEdit and convert to integer
	string subject = AnsiString(subjectEdit->Text.Trim()).c_str(); // Get subject from subjectEdit

	// Perform deletion using _studentRecordList
	 _studentRecordList->deleteRecord(id, subject);

    // Clear input fields after deletion
    idEdit->Text = "";
	subjectEdit->Text = "";

}
//---------------------------------------------------------------------------
