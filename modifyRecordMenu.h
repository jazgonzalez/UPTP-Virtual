#ifndef modifyRecordMenuH
#define modifyRecordMenuH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "StudentRecordList.h"
#include <FMX.Objects.hpp>

//---------------------------------------------------------------------------

class T_modifyRecordMenu : public TForm
{
	__published:	// IDE-managed Components
		TLabel *idLabel;
		TEdit *idEdit;
		TLabel *subjectLabel;
		TEdit *subjectEdit;
		TButton *backButton;
		TEdit *markEdit;
		TRectangle *container;
		TImage *background;
		TImage *logo;
		TLabel *Label1;
		TClearEditButton *ClearEditButton1;
		TClearEditButton *ClearEditButton2;
		TClearEditButton *ClearEditButton3;
		void __fastcall backButtonClick(TObject *Sender);
		//void __fastcall saveButtonClick(TObject *Sender);
		void __fastcall modifyButtonClick(TObject *Sender);
	private:
		StudentRecordList* _studentRecordList; // Declaration of _studentRecordList
	public:
		__fastcall T_modifyRecordMenu(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE T_modifyRecordMenu *_modifyRecordMenu;
//---------------------------------------------------------------------------
#endif
