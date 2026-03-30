#include <fmx.h>
#pragma hdrstop

#include "QandAsubmenu.h"   // QandAsubmenu header file
#include "studentSubmenu.h" // studentSubmenu header file

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
T_QandAsubmenu *_QandAsubmenu;

//---------------------CONSTRUCTOR-----------------------------------

__fastcall T_QandAsubmenu::T_QandAsubmenu(TComponent* Owner)
	: TForm(Owner)
{
		// Set the text for the Q&A label with the TA office hours
    	QandALabel->Text =
        "TA Pablo Maldonado\n"
        "Monday and Wednesday: 8:30 to 12:30\n\n"
        "TA Horacio Sosa\n"
        "Tuesday: 14:30 to 15:30\n\n"
        "TA Maria Espinola\n"
        "Thursday: 14:30 to 15:30\n\n"
        "TA Cesar Clerx\n"
		"Monday and Wednesday: 16:30 to 18:00";
}

//-------------------------backButtonClick---------------------------------

void __fastcall T_QandAsubmenu::backButtonClick(TObject *Sender)
{
     // Close the current form (QandASubmenu) and show the student submenu form
    this->Close();
    _studentSubmenu->Show();
}




