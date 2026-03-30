//---------------------------------------------------------------------------
#ifndef registrationFormProfessorH
#define registrationFormProfessorH
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

class T_registrationFormProfessor : public TForm
{
	__published:    // IDE-managed Components
		TLabel *usernameLabel;             // Label for displaying "Username"
		TLabel *passwordLabel;             // Label for displaying "Password"
		TEdit *usernameEdit;               // Edit field for entering username
		TEdit *passwordEdit;               // Edit field for entering password
		TButton *saveButton;
		TButton *backButton;
		TLabel *nameLabel;
		TEdit *nameEdit;
		TImage *bg;
		TRectangle *container;
		TImage *logo;
		TClearEditButton *ClearEditButton1;
		TClearEditButton *ClearEditButton2;
		TPasswordEditButton *PasswordEditButton1;
		TLabel *Label1;               // Button for saving registration information

		void __fastcall saveButtonClick(TObject *Sender);                // Event handler for saveButton click
		void __fastcall backButtonClick(TObject *Sender);
		void __fastcall FormCreate(TObject *Sender);

	private:    // User declarations
			// Function to check if a username exists in a given file
			bool isUsernameInFile(const std::string& username, const std::string& filename);

	public:     // User declarations
		__fastcall T_registrationFormProfessor(TComponent* Owner);       // Constructor
};

//---------------------------------------------------------------------------
extern PACKAGE T_registrationFormProfessor *_registrationFormProfessor; // Pointer to registration form instance
//---------------------------------------------------------------------------
#endif

