#ifndef gradesSubmenuH
#define gradesSubmenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include "StudentRecordList.h"
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>

class T_gradesSubmenu : public TForm
{
	__published:
		TLabel *idLabel;
		TEdit *idEdit;
		TLabel *displayGradesLabel;
		TButton *backButton;
		TSearchEditButton *SearchEditButton1;
		TRectangle *container;
		TImage *bg;
		TImage *logo;
		TLabel *Atitle;
		TLabel *displaySubjectLabel;
		TLabel *displayGradeLabel;
		TLabel *headingLabel;
		TLabel *Label1;
		TLabel *Label2;
		TLabel *displayGpaLabel;

		void __fastcall backButtonClick(TObject *Sender);
		void __fastcall SearchEditButton1Click(TObject *Sender);

	private:
		StudentRecordList* _studentRecordList; // Instance of StudentRecordList
		int _loggedInStudentID; // ID of the logged-in student

	public:
		__fastcall T_gradesSubmenu(TComponent* Owner);   // Constructor
		void SetLoggedInStudentID(int studentID); // Method to set logged-in student ID
};

extern PACKAGE T_gradesSubmenu *gradesSubmenu;

#endif





