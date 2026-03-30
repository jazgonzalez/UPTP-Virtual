#include <fmx.h>
#pragma hdrstop
#include "classesSubmenu.h"   // classesSubmenu header file
#include "ScheduleManager.h" // ScheduleManager header file
#include "studentSubmenu.h" //  studentSubmenu header file

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
T_classesSubmenu *_classesSubmenu;

//--------------------------------CONSTRUCTOR-------------------------------------------

__fastcall T_classesSubmenu::T_classesSubmenu(TComponent* Owner)
	: TForm(Owner), manager(100) // Initialize the dynamic array "manager" with a max capacity of 100
{
	// Center the text horizontally
	classesLabel->TextSettings->HorzAlign = TTextAlign::Center;
	// calls the method that add classes to the schedule
	initializeSchedule();
	// Call the function to find and display the next class
	manager.findNextClass(this);
}

//----------------------ADD CLASSES TO THE SCHEDULE OF STUDENTS-------------------------

void T_classesSubmenu::initializeSchedule()
{
	//0 = Sunday, 1 = Monday, 2 = Tuesday , 3 = Wednesday
	//4 = Thursday, 5 = Friday, 6 = Saturday
	//addClass(subject, day, initial hour, initial minute, end hour, end minute, classroom)

    // Adding classes on Monday
	manager.addClass("Engineering Materials", 1, 8, 0, 10, 0, "A2");
    manager.addClass("Introduction To Industrial Engineering", 1, 10, 30, 12, 30, "A2");
	manager.addClass("Data Structures - Practice", 1, 13, 30, 15, 30, "PC LAB");
	manager.addClass("Chinese III", 1, 16, 0, 18, 0, "A2");


    // Adding classes on Tuesday
    manager.addClass("Engineering Materials", 2, 8, 0, 10, 0, "A3");
    manager.addClass("Digital Logic Design - Practice", 2, 10, 30, 12, 30, "Electronics Lab");
    manager.addClass("Data Structures - Theory", 2, 13, 30, 17, 00, "A3");

	// Adding classes on Wednesday
    manager.addClass("English III", 3, 8, 0, 10, 0, "A1");
    manager.addClass("Object Oriented Programming - Theory", 3, 10, 30, 14, 30, "PC LAB");
    manager.addClass("Introduction to Industrial Engineering", 3, 14, 30, 18, 0, "A1");

    // Adding classes on Thursday
	manager.addClass("Digital Logic Design - Practice", 4, 8, 0, 10, 0, "Electronics Lab");
	manager.addClass("Digital Logic Design - Theory", 4, 10, 30, 14, 30, "Electronics Lab");

    // Adding classes on Friday
	manager.addClass("English III", 5, 8, 0, 10, 0, "A1");
	manager.addClass("Chinese III", 5, 10, 30, 12, 30, "A5");
	manager.addClass("Object Oriented Programming - Practice", 5, 13, 30, 15, 30, "PC LAB");
}

//-------------------------------backButton--------------------------------------------

void __fastcall T_classesSubmenu::backButtonClick(TObject *Sender)
{
	// Close the current form (T_classesSubmenu) and show the student submenu form
	this->Close();
	_studentSubmenu->Show();
}



