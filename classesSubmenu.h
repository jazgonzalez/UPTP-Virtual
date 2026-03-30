#ifndef classesSubmenuH
#define classesSubmenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "ScheduleManager.h"  // Include the ScheduleManager header file
#include <FMX.Objects.hpp>

//---------------------------------------------------------------------------
class T_classesSubmenu : public TForm // Define the classes submenu class inheriting from TForm
{
__published:	// IDE-managed Components
	TLabel *classesLabel;
	TButton *backButton;
	TRectangle *container;
	TImage *bg;
	TImage *logo;
	TLabel *Label1;
	void __fastcall backButtonClick(TObject *Sender); // Label to display class information

private:	// User declarations

	void initializeSchedule(); // Function to initialize and display the class schedule
	Schedule manager; // Declare the Schedule object with a fixed max capacity

public:		// User declarations
	__fastcall T_classesSubmenu(TComponent* Owner); // Constructor for the classes submenu form
	//friend class Schedule; // Allow Schedule to access private members
};
//---------------------------------------------------------------------------
extern PACKAGE T_classesSubmenu *_classesSubmenu; // Declare the global instance of the classes submenu form
//---------------------------------------------------------------------------
#endif

