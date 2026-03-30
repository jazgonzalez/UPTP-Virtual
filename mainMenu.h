//---------------------------------------------------------------------------

#ifndef mainMenuH // Header guard to prevent multiple inclusion
#define mainMenuH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.ListBox.hpp>

//---------------------------------------------------------------------------
// T_mainMenu class declaration
class T_mainMenu : public TForm
{
__published: // IDE-managed Components
    TButton *professorEdit; // Button for professor menu
	TButton *studentEdit;
	TLabel *chooseLabel;
	TRectangle *whiteBLock;
	TImage *backgound;   // Button for student menu

    // Event handlers for button clicks
    void __fastcall professorEditClick(TObject *Sender);
	void __fastcall studentEditClick(TObject *Sender);

private: // User declarations

public: // User declarations
	// Constructor
	__fastcall T_mainMenu(TComponent* Owner);
};

//---------------------------------------------------------------------------
// Global variable declaration for main menu form
extern PACKAGE T_mainMenu *_mainMenu;

//---------------------------------------------------------------------------
#endif // mainMenuH

