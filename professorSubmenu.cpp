#include <fmx.h>
#pragma hdrstop

#include "professorSubmenu.h"    // professorSubmenu header file
#include "loginProfessor.h" 	// loginProfessor header file
#include "insertRecordMenu.h"   // searchRecordMenu header file
#include "searchRecordMenu.h"   // searchRecordMenu header file
#include "modifyRecordMenu.h"   // modifyRecordMenu header file

#include <ShellAPI.h>  // Needed for ShellExecute (to open url)

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
T_professorSubmenu *_professorSubmenu;

//--------------------------CONSTRUCTOR---------------------------------

__fastcall T_professorSubmenu::T_professorSubmenu(TComponent* Owner)
	: TForm(Owner)
{
}

//-------------------------SetLoggedInProfessorName--------------------------------

void T_professorSubmenu::SetLoggedInProfessorName(const String& professorName)
{
	_loggedInProfessorName = professorName; // Set the logged in professor name
	welcomeLabel->Text = "Welcome Professor " + professorName + "!";    // Display the welcome message
}

//--------------------------insertRecordButtonClick--------------------------------

void __fastcall T_professorSubmenu::insertRecordButtonClick(TObject *Sender)
{
	this->Close();  // Close the _professorSubmenu
	_insertRecordMenu->Show();  // Show the _insertRecordMenu
}

//---------------------------searchRecordButtonClick-------------------------------

void __fastcall T_professorSubmenu::searchRecordButtonClick(TObject *Sender)
{
	this->Close();  // Close the _professorSubmenu
	_searchRecordMenu->Show();  // Show the _searchRecordMenu
}

//--------------------------logoutButtonClick-----------------------------

void __fastcall T_professorSubmenu::logoutButtonClick(TObject *Sender)
{
	this->Close();  // Close the _professorSubmenu
	_loginProfessor->Show();    // Show the _loginProfessor
}

//--------------------------modifyRecordButtonClick---------------------------------

void __fastcall T_professorSubmenu::modifyRecordButtonClick(TObject *Sender)
{
	this->Close();  // Close the _professorSubmenu
	_modifyRecordMenu->Show();  // Show the _modifyRecordMenu
}

//----------------------------formButtonClick-----------------------------

void __fastcall T_professorSubmenu::formButtonClick(TObject *Sender)
{
	// URL to open (for the professor to create an evaluation form)
	UnicodeString url = L"https://forms.app/myforms";

	// Open the URL using ShellExecute
	ShellExecuteW(NULL, L"open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
