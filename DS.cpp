//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("registrationFormStudent.cpp", _registrationFormStudent);
USEFORM("registrationFormProfessor.cpp", _registrationFormProfessor);
USEFORM("QandAsubmenu.cpp", _QandAsubmenu);
USEFORM("professorSubmenu.cpp", _professorSubmenu);
USEFORM("studentSubmenu.cpp", _studentSubmenu);
USEFORM("searchRecordMenu.cpp", _searchRecordMenu);
USEFORM("professorClass.cpp", _professorClass);
USEFORM("gradesSubmenu.cpp", _gradesSubmenu);
USEFORM("classesSubmenu.cpp", _classesSubmenu);
USEFORM("insertRecordMenu.cpp", _insertRecordMenu);
USEFORM("modifyRecordMenu.cpp", _modifyRecordMenu);
USEFORM("mainMenu.cpp", _mainMenu);
USEFORM("loginProfessor.cpp", _loginProfessor);
USEFORM("loginFormStudent.cpp", _loginFormStudent);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(T_mainMenu), &_mainMenu);
		Application->CreateForm(__classid(T_gradesSubmenu), &_gradesSubmenu);
		Application->CreateForm(__classid(T_registrationFormProfessor), &_registrationFormProfessor);
		Application->CreateForm(__classid(T_studentSubmenu), &_studentSubmenu);
		Application->CreateForm(__classid(T_classesSubmenu), &_classesSubmenu);
		Application->CreateForm(__classid(T_loginFormStudent), &_loginFormStudent);
		Application->CreateForm(__classid(T_registrationFormStudent), &_registrationFormStudent);
		Application->CreateForm(__classid(T_QandAsubmenu), &_QandAsubmenu);
		Application->CreateForm(__classid(T_loginProfessor), &_loginProfessor);
		Application->CreateForm(__classid(T_professorSubmenu), &_professorSubmenu);
		Application->CreateForm(__classid(T_professorClass), &_professorClass);
		Application->CreateForm(__classid(T_insertRecordMenu), &_insertRecordMenu);
		Application->CreateForm(__classid(T_searchRecordMenu), &_searchRecordMenu);
		Application->CreateForm(__classid(T_modifyRecordMenu), &_modifyRecordMenu);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
