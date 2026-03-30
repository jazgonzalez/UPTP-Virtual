#ifndef professorClassH
#define professorClassH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>

#include "ScheduleProfessor.h"
#include <FMX.Objects.hpp>

//---------------------------------------------------------------------------

class T_professorClass : public TForm
{
	__published:
		TLabel *messageLabel;
		TButton *dashboardButton;
		TImage *background;
		TRectangle *container;
		TImage *logo;
		TLabel *Label1;
		void __fastcall dashboardButtonClick(TObject *Sender);
	private:
	public:
		__fastcall T_professorClass(TComponent* Owner);
		void displayClassMessage(const std::string& professorName, ScheduleP& scheduleP);
};

//---------------------------------------------------------------------------
extern PACKAGE T_professorClass *_professorClass;
extern PACKAGE T_professorClass *_professorClass; // Declaration of _professorClass
//---------------------------------------------------------------------------
#endif
