//---------------------------------------------------------------------------
#ifndef studentMenuH
#define studentMenuH
//---------------------------------------------------------------------------

// Include necessary header files for FMX framework components
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------

// Declaration of the student menu form class
class T_studentMenu : public TForm
{
__published:	// IDE-managed Components
    TButton *registrationButton; // Button for registration
    TButton *loginButton; // Button for login

    // Event handlers for button clicks
    void __fastcall registrationButtonClick(TObject *Sender);
    void __fastcall loginButtonClick(TObject *Sender);

private:	// User declarations

public:		// User declarations
    __fastcall T_studentMenu(TComponent* Owner); // Constructor declaration
};

//---------------------------------------------------------------------------
extern PACKAGE T_studentMenu *_studentMenu; // Declaration of global variable for the student menu form
//---------------------------------------------------------------------------

#endif comment

