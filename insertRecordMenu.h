//---------------------------------------------------------------------------

#ifndef insertRecordMenuH
#define insertRecordMenuH
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

class T_insertRecordMenu : public TForm
{
	__published:	// IDE-managed Components
		TLabel *idLabel;         // Label for displaying "ID"
		TEdit *idEdit;           // Edit box for entering student ID
		TLabel *markLabel;       // Label for displaying "Mark"
		TEdit *markEdit;         // Edit box for entering student mark
		TButton *saveButton;     // Button to save the record
		TButton *backButton;     // Button to go back to the previous menu
		TLabel *subjectLabel;    // Label for displaying "Subject"
		TEdit *subjectEdit;
		TRectangle *container;
		TImage *logo;
		TImage *bg;
		TClearEditButton *ClearEditButton1;
		TClearEditButton *ClearEditButton2;
		TClearEditButton *ClearEditButton3;
		TLabel *tittle;
		void __fastcall backButtonClick(TObject *Sender);  // Event handler for back button click
		void __fastcall saveButtonClick(TObject *Sender);  // Event handler for save button click

	private:
		StudentRecordList* _studentRecordList; // Instance of StudentRecordList to manage student records

	public:
		__fastcall T_insertRecordMenu(TComponent* Owner);  // Constructor for initializing the form
		void updateUI();
};

//---------------------------------------------------------------------------
extern PACKAGE T_insertRecordMenu *_insertRecordMenu;  // Global instance of the insert record menu form
//---------------------------------------------------------------------------
#endif // insertRecordMenuH
