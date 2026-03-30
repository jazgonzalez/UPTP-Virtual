/*
//---------------------------------------------------------------------------

#ifndef searchRecordMenuH
#define searchRecordMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>

#include "StudentRecordList.h" // Include the StudentRecordList header
//---------------------------------------------------------------------------
class T_searchRecordMenu : public TForm
{
__published:	// IDE-managed Components
	TLabel *idLabel;
	TEdit *idEdit;
	TButton *searchButton;
	TButton *backButton;
	TLabel *displayRecordLabel;
	TEdit *subjectEdit;
	TLabel *subjectLabel;
	void __fastcall backButtonClick(TObject *Sender);
	void __fastcall searchButtonClick(TObject *Sender);
private:	// User declarations
	StudentRecordList* _studentRecordList; // Declare _studentRecordList
public:		// User declarations
	__fastcall T_searchRecordMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T_searchRecordMenu *_searchRecordMenu;
//---------------------------------------------------------------------------
#endif
*/

#ifndef searchRecordMenuH
#define searchRecordMenuH
//---------------------------------------------------------------------------

// Include necessary headers for FMX components and standard library
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>

// Include for std::string
#include <string>

// Include the StudentRecordList header where StudentRecordList class is defined
#include "StudentRecordList.h"

//---------------------------------------------------------------------------
class T_searchRecordMenu : public TForm
{
__published:    // IDE-managed Components
    TLabel *idLabel;                // Label for ID input
    TEdit *idEdit;          // Button for initiating search
    TButton *backButton;            // Button for going back
    TLabel *displayRecordLabel;     // Label for displaying search results
    TEdit *subjectEdit;             // Edit box for entering subject
	TLabel *subjectLabel;
	TSearchEditButton *SearchEditButton1;
	TRectangle *container;
	TImage *bg;
	TClearEditButton *ClearEditButton1;
	TImage *logo;
	TLabel *title;           // Label for subject input

    // Event handlers for button clicks
	void __fastcall backButtonClick(TObject *Sender);
	//void __fastcall searchButtonClick(TObject *Sender);
	void __fastcall SearchEditButton1Click(TObject *Sender);

private:    // User declarations
    StudentRecordList* _studentRecordList; // Pointer to manage student record list

public:    // User declarations
    __fastcall T_searchRecordMenu(TComponent* Owner); // Constructor declaration
};

extern PACKAGE T_searchRecordMenu *_searchRecordMenu; // Declaration for form instance
//---------------------------------------------------------------------------

#endif // End of searchRecordMenuH
//---------------------------------------------------------------------------


