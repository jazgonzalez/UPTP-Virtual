#ifndef professorSubmenuH
#define professorSubmenuH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>

//---------------------------------------------------------------------------

class T_professorSubmenu : public TForm
{
	__published:	// IDE-managed Components
		TButton *insertRecordButton;
		TButton *searchRecordButton;
		TButton *modifyRecordButton;
		TButton *formButton;
		TButton *logoutButton;
		TRectangle *container;
		TImage *background;
		TImage *logo;
		TLabel *welcomeLabel;
		void __fastcall insertRecordButtonClick(TObject *Sender);
		void __fastcall searchRecordButtonClick(TObject *Sender);
		void __fastcall logoutButtonClick(TObject *Sender);
		void __fastcall modifyRecordButtonClick(TObject *Sender);
		void __fastcall formButtonClick(TObject *Sender);
	private:
		String _loggedInProfessorName;    // For the welcome message
	public:
		__fastcall T_professorSubmenu(TComponent* Owner);
		void SetLoggedInProfessorName(const String& professorName);  /// For the welcome message
};

//---------------------------------------------------------------------------
extern PACKAGE T_professorSubmenu *_professorSubmenu;
//---------------------------------------------------------------------------
#endif
