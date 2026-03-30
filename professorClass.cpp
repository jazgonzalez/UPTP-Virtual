#include <fmx.h>
#pragma hdrstop

#include "professorClass.h" // professorClass header file

//T_professorClass *professorClass = nullptr; // Definition of professorClass
T_professorClass *_professorClass = nullptr; // Definition of _professorClass

#include "professorSubmenu.h"   // professorSubmenu header file

using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"

//--------------------------CONSTRUCTOR---------------------------------

__fastcall T_professorClass::T_professorClass(TComponent* Owner)
	: TForm(Owner)  // Initializes the form with its owner component
{
}

//--------------------------displayClassMessage-------------------------------

void T_professorClass::displayClassMessage(const string& professorName, ScheduleP& scheduleP)
{
	// Covert string to UnicodeString (ensures that any Unicode characters are correctly displayed)
	// The finNextClass function in ScheduleProfessor.cpp returns a System::UnicodeString variable
	System::UnicodeString message = scheduleP.findNextClass(professorName);
    // Displays the message
	messageLabel->Text = message.c_str();
}

//-------------------------dashboardButtonClick-----------------------------

void __fastcall T_professorClass::dashboardButtonClick(TObject *Sender)
{
	this->Close();  // Close the current _professorClass form
	_professorSubmenu->Show();  // Show the _professorSubmenu form
}

