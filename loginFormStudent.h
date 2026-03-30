#ifndef loginFormStudentH
#define loginFormStudentH

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.ExtCtrls.hpp>

#include "mainMenu.h"
#include "registrationFormStudent.h"
#include <FMX.Objects.hpp>

//---------------------------------------------------------------------------

class T_loginFormStudent : public TForm
{
	__published:
		TLabel *usernameLabel;
		TLabel *passwordLabel;
		TEdit *usernameEdit;
		TEdit *passwordEdit;
		TButton *loginButton;
		TButton *registerButton;
		TLabel *Label1;
		TLabel *Label2;
		TButton *backButton;
		TPasswordEditButton *PasswordEditButton1;
		TClearEditButton *ClearEditButton1;
		TRectangle *container;
		TImage *background;
		TImage *logo;

		void __fastcall loginButtonClick(TObject *Sender);
		void __fastcall registerButtonClick(TObject *Sender);
		void __fastcall backButtonClick(TObject *Sender);
		void __fastcall FormCreate(TObject *Sender);

	private:
			  int _loggedInStudentID; // Variable to store logged-in student ID
	public:
		__fastcall T_loginFormStudent(TComponent* Owner, TForm *mainMenu);  // Constructor
		void SetLoggedInStudentID(int studentID); // Method to set logged-in student ID
};

//---------------------------------------------------------------------------
extern PACKAGE T_loginFormStudent *_loginFormStudent; // Pointer to login form instance
//---------------------------------------------------------------------------
#endif

