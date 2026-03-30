

//---------------------------------------------------------------------------
#ifndef registrationFormStudentH
#define registrationFormStudentH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
using namespace std;
//---------------------------------------------------------------------------

class T_registrationFormStudent : public TForm
{
	__published:    // IDE-managed Components
		TLabel *usernameLabel;
		TLabel *passwordLabel;
		TEdit *usernameEdit;
		TEdit *passwordEdit;
		TButton *saveButton;
		TButton *backButton;
		TLabel *Label1;
		TEdit *nameEdit;
		TLabel *idLabel;
		TEdit *idEdit;
		TImage *background;
		TRectangle *container;
		TImage *logo;
		TLabel *ATitle;
		TLabel *Label2;
		TClearEditButton *ClearEditButton1;
		TClearEditButton *ClearEditButton2;
		TClearEditButton *ClearEditButton3;
		TPasswordEditButton *PasswordEditButton1;

		void __fastcall saveButtonClick(TObject *Sender);                // Event handler for saveButton click
		void __fastcall backButtonClick(TObject *Sender);
		void __fastcall FormCreate(TObject *Sender);             // Event handler for changes in passwordEdit field

	private:    // User declarations
		   bool isUsernameInFile(const string& username, const string& filename);
	public:     // User declarations
		__fastcall T_registrationFormStudent(TComponent* Owner);        // Constructor

};

//---------------------------------------------------------------------------
extern PACKAGE T_registrationFormStudent *_registrationFormStudent; // Pointer to registration form instance
//---------------------------------------------------------------------------
#endif

