//---------------------------------------------------------------------------

#ifndef professorMenuH
#define professorMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class T_professorMenu : public TForm
{
__published:	// IDE-managed Components
	TButton *registrationButton;
	TButton *loginButton;
	void __fastcall registrationButtonClick(TObject *Sender);
	void __fastcall loginButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall T_professorMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T_professorMenu *_professorMenu;
//---------------------------------------------------------------------------
#endif
