//---------------------------------------------------------------------------

#ifndef deleteRecordMenuH
#define deleteRecordMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "StudentRecordList.h"  // Include your StudentRecordList header file
//---------------------------------------------------------------------------
class T_deleteRecordMenu : public TForm
{
__published:	// IDE-managed Components
	TLabel *idLabel;
	TEdit *idEdit;
	TLabel *subjectLabel;
	TEdit *subjectEdit;
	TButton *deleteButton;
	TButton *backButton;
	void __fastcall backButtonClick(TObject *Sender);
	void __fastcall deleteButtonClick(TObject *Sender);
private:	// User declarations
	StudentRecordList* _studentRecordList; // Declaration of _studentRecordList
public:		// User declarations
	__fastcall T_deleteRecordMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T_deleteRecordMenu *_deleteRecordMenu;
//---------------------------------------------------------------------------
#endif
