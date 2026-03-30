//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "mainMenu.h"   //  mainMenu header file
#include "loginProfessor.h" //  loginProfessor header file
#include "loginFormStudent.h"   //  loginFormStudent header file

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
T_mainMenu *_mainMenu;

//--------------------------CONSTRUCTOR----------------------------------

__fastcall T_mainMenu::T_mainMenu(TComponent* Owner)
	: TForm(Owner)
{
}

//-------------------------professorEditClick--------------------------------

void __fastcall T_mainMenu::professorEditClick(TObject *Sender)
{
	// Show the professor login menu
	_loginProfessor->Show();

}

//------------------------studentEditClick------------------------------------

void __fastcall T_mainMenu::studentEditClick(TObject *Sender)
{
	// Show the student login menu
	_loginFormStudent->Show();

}

