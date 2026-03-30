//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "professorMenu.h"
#include "registrationFormProfessor.h"
#include "loginFormProfessor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
T_professorMenu *_professorMenu;
//---------------------------------------------------------------------------
__fastcall T_professorMenu::T_professorMenu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_professorMenu::registrationButtonClick(TObject *Sender)
{
	_registrationFormProfessor->Show();
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_professorMenu::loginButtonClick(TObject *Sender)
{
	_loginFormProfessor->Show();
	this->Close();
}
//---------------------------------------------------------------------------
