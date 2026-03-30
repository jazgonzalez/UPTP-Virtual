//---------------------------------------------------------------------------

#ifndef loginFormProfessorH
#define loginFormProfessorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class T_loginFormProfessor : public TForm
{
__published:	// IDE-managed Components
	TLabel *usernameLabel;
	TLabel *passwordLabel;
	TEdit *usernameEdit;
	TEdit *passwordEdit;
	TButton *loginButton;
	TButton *registerButton;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall loginButtonClick(TObject *Sender);
	void __fastcall updateButtonState(); // Declaration of the updateButtonState function
	void __fastcall usernameEditChange(TObject *Sender); // Declaration of the usernameEditChange function
	void __fastcall passwordEditChange(TObject *Sender);
	void __fastcall registerButtonClick(TObject *Sender); // Declaration of the passwordEditChange function
private:	// User declarations
public:		// User declarations
	__fastcall T_loginFormProfessor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T_loginFormProfessor *_loginFormProfessor;
//---------------------------------------------------------------------------
#endif
