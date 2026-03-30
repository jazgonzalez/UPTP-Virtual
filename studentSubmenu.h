//---------------------------------------------------------------------------
#ifndef studentSubmenuH
#define studentSubmenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
using namespace std;
//---------------------------------------------------------------------------
class T_studentSubmenu : public TForm // Define the student submenu class inheriting from TForm
{
__published:	// IDE-managed Components
	TButton *classesButton; // Button to access classes submenu
	TButton *gradesButton; // Button to access grades submenu
	TButton *TAbutton; // Button to access TA submenu
	TButton *logoutButton;
	TComboEdit *DocumentComboEdit;
	TComboEdit *RegulationComboEdit;
	TComboEdit *BookComboEdit;
	TRectangle *CONTAINER;
	TImage *background;
	TImage *logoImage;
	TLabel *welcomeLabel; // Button to logout
	void __fastcall classesButtonClick(TObject *Sender);
	void __fastcall TAbuttonClick(TObject *Sender);
	void __fastcall logoutButtonClick(TObject *Sender);
	void __fastcall gradesButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DocumentComboEditChange(TObject *Sender);
	void __fastcall RegulationComboEditChange(TObject *Sender);
	void __fastcall BookComboEditChange(TObject *Sender);


private:	// User declarations
	int _loggedInStudentID; // Declare _loggedInStudentID as a private member
	String _loggedInStudentName;    //for the welcome message
	//String _RegistrationStudentName;    //for the welcome message
public:		// User declarations
	__fastcall T_studentSubmenu(TComponent* Owner); // Constructor for the student submenu form
	void SetLoggedInStudentID(int studentID); // Method to set logged-in student ID
	void SetLoggedInStudentName(const String& studentName);  //for the welcome message
	//void SetRegistrationStudentName(const String& studentName);

};
//---------------------------------------------------------------------------
extern PACKAGE T_studentSubmenu *_studentSubmenu; // Declare the global instance of the student submenu form
//---------------------------------------------------------------------------
#endif

