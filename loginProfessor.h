//---------------------------------------------------------------------------

#ifndef loginProfessorH
#define loginProfessorH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>

//---------------------------------------------------------------------------

class T_loginProfessor : public TForm
{
	__published:	// IDE-managed Components
		TLabel *usernameLabel;
		TLabel *passwordLabel;
		TEdit *usernameEdit;
		TEdit *passwordEdit;
		TButton *loginButton;
		TButton *registerButton;
		TLabel *loginTittle;
		TLabel *Label2;
		TButton *backButton;
		TPasswordEditButton *PasswordEditButton1;
		TRectangle *container;
		TImage *bg;
		TImage *logo;
		TClearEditButton *ClearEditButton1;
		void __fastcall registerButtonClick(TObject *Sender);
		void __fastcall loginButtonClick(TObject *Sender);
		void __fastcall backButtonClick(TObject *Sender);
		void __fastcall FormCreate(TObject *Sender);
	private:	// User declarations
	public:		// User declarations
		__fastcall T_loginProfessor(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE T_loginProfessor *_loginProfessor;
//---------------------------------------------------------------------------
#endif
