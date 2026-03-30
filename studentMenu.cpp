//---------------------------------------------------------------------------
#include <fmx.h>
#pragma hdrstop

#include "studentMenu.h"              // Include the header file for the student menu form
#include "registrationFormStudent.h"  // Include the header file for the student registration form
#include "loginFormStudent.h"         // Include the header file for the student login form

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
T_studentMenu *_studentMenu;  // Initialize a global variable for the student menu form
//---------------------------------------------------------------------------

// Constructor for the student menu form
__fastcall T_studentMenu::T_studentMenu(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
// Event handler for the registration button click
void __fastcall T_studentMenu::registrationButtonClick(TObject *Sender)
{
	_registrationFormStudent->Show();  // Show the student registration form
	this->Close();                     // Close the student menu form
}

//---------------------------------------------------------------------------
// Event handler for the login button click
void __fastcall T_studentMenu::loginButtonClick(TObject *Sender)
{
	_loginFormStudent->Show();  // Show the student login form
	this->Close();              // Close the student menu form
}
//---------------------------------------------------------------------------

