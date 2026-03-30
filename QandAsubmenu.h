#ifndef QandAsubmenuH
#define QandAsubmenuH

//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>

//---------------------------------------------------------------------------

class T_QandAsubmenu : public TForm
{
	__published:	// IDE-managed Components
		TLabel *QandALabel;
		TButton *backButton;
		TImage *background;
		TRectangle *container;
		TImage *logo;
		TLabel *QandATitle;
		TLabel *ParticipateMessage;
		void __fastcall backButtonClick(TObject *Sender);    // Label to display Q&A information
	private:	// User declarations
	public:		// User declarations
		__fastcall T_QandAsubmenu(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE T_QandAsubmenu *_QandAsubmenu;
//---------------------------------------------------------------------------
#endif
