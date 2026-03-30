#include <fmx.h> // Include the FireMonkey library header file
#pragma hdrstop

#include "studentSubmenu.h" // Include the header file for the student submenu form
#include "classesSubmenu.h" // Include the header file for the classes submenu form
#include "QandAsubmenu.h"   // Include the header file for the QandA submenu form
#include "loginFormStudent.h"  // Include the header file for the loginStudent form
#include "gradesSubmenu.h"  // Include the header file for the grades submenu form

#include <Winapi.Windows.hpp>  // Incluye ShellExecuteW
#include <Winapi.ShellAPI.hpp> // Incluye ShellExecuteW
#include <map>                // For using map
#include <string>             // For using string


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
T_studentSubmenu *_studentSubmenu; // Initialize the global instance of the student submenu form
T_gradesSubmenu *_gradesSubmenu = nullptr; // Initialize _gradesSubmenu

// Declare linkMap as a class member of T_studentSubmenu
map<String, String> documentlinkMap;
map<String, String> regulationLinkMap;
map<String, String> bookLinkMap;

//--------------------------CONSTRUCTOR--------------------------------

__fastcall T_studentSubmenu::T_studentSubmenu(TComponent* Owner)
	: TForm(Owner)
{
}

//------------------------classesButtonClick--------------------------------

void __fastcall T_studentSubmenu::classesButtonClick(TObject *Sender)
{
	_classesSubmenu->Show(); // Show the classes submenu form
	this->Close(); // Close the current student submenu form
}

//------------------------TAbuttonClick---------------------------------------

void __fastcall T_studentSubmenu::TAbuttonClick(TObject *Sender)
{
	_QandAsubmenu->Show();  // Show the QandA submenu form
	this->Close();  // Close the current student submenu form
}

//-----------------------logoutButtonClick--------------------------------------

void __fastcall T_studentSubmenu::logoutButtonClick(TObject *Sender)
{
	this->Close();
	_loginFormStudent->Show();
}

//-------------------------SetLoggedInStudentID-----------------------------------

void T_studentSubmenu::SetLoggedInStudentID(int studentID)
{
	_loggedInStudentID = studentID;
}

//------------------------SetLoggedInStudentName-----------------------------------

void T_studentSubmenu::SetLoggedInStudentName(const String& studentName)
{
	_loggedInStudentName = studentName;
	welcomeLabel->Text = "Welcome, " + studentName + "!";
}

//-------------------------gradesButtonClick---------------------------------

void __fastcall T_studentSubmenu::gradesButtonClick(TObject *Sender)
{
	if (_gradesSubmenu) // If the gradesSubmenu form is not null (it has been asigned to an object form)
	{
		// Set the logged student id to latter check the grades
		_gradesSubmenu->SetLoggedInStudentID(_loggedInStudentID);
		this->Close();  // Close the current form
		_gradesSubmenu->Show(); // Show the _gradesSubmenu
	}
	else    // Else, if the studentSubmenu form was not assigned to any object
	{
		ShowMessage("Error: gradesSubmenu is not initialized.");
	}
}

//---------------------------------------------------------------------------

void __fastcall T_studentSubmenu::FormCreate(TObject *Sender)
{
	// Add links to documentComboEdit with their corresponding text
	documentlinkMap["Tuition Fees"] = "https://onedrive.live.com/?authkey=%21AMnIHz32S1I5oVE&cid=A969866388F871B9&id=A969866388F871B9%211275&parId=A969866388F871B9%211271&o=OneUp";
	documentlinkMap["Academic Calendar"] = "https://onedrive.live.com/?cid=A969866388F871B9&id=A969866388F871B9%211281&parId=A969866388F871B9%211276&o=OneUp";
	documentlinkMap["Regulations for Evaluations"] = "https://onedrive.live.com/?cid=A969866388F871B9&id=A969866388F871B9%211278&parId=A969866388F871B9%211276&o=OneUp";
	documentlinkMap["Tuition Fees"]="https://onedrive.live.com/?cid=A969866388F871B9&id=A969866388F871B9%211280&parId=A969866388F871B9%211276&o=OneUp";
	documentlinkMap["Final Exam Schedule"]="https://onedrive.live.com/?cid=A969866388F871B9&id=A969866388F871B9%211279&parId=A969866388F871B9%211276&o=OneUp";
	documentlinkMap["Class Schedule"]="https://onedrive.live.com/?cid=A969866388F871B9&id=A969866388F871B9%211282&parId=A969866388F871B9%211276&o=OneUp";
    documentlinkMap["Professor Evaluation Form"]="https://forms.app/form/667f33b50ab1f7718d244aaf/create";
	// Populate documentComboEdit with text entries
	for (const auto& pair : documentlinkMap)
	{
		DocumentComboEdit->Items->Add(pair.first);
	}

	// Add links to regulationLinkMap with their corresponding text
	regulationLinkMap["Degree Regulations"] = "https://onedrive.live.com/?authkey=%21AMnIHz32S1I5oVE&cid=A969866388F871B9&id=A969866388F871B9%211286&parId=A969866388F871B9%211285&o=OneUp";
	regulationLinkMap["Validation of Subjects"] = "https://onedrive.live.com/?authkey=%21AMnIHz32S1I5oVE&cid=A969866388F871B9&id=A969866388F871B9%211317&parId=A969866388F871B9%211285&o=OneUp";

	// Populate RegulationComboEdit with text entries
	for (const auto& pair : regulationLinkMap)
	{
		RegulationComboEdit->Items->Add(pair.first);
	}

	// Add links to bookLinkMap with their corresponding text
	bookLinkMap["First Year - Drive"] = "https://onedrive.live.com/?id=A969866388F871B9%211287&cid=A969866388F871B9";
	bookLinkMap["Second Year - Drive"] = "https://onedrive.live.com/?id=A969866388F871B9%211291&cid=A969866388F871B9";

	// Populate bookComboEdit with text entries
	for (const auto& pair : bookLinkMap)
	{
		BookComboEdit->Items->Add(pair.first);
	}

}

//---------------------------------------------------------------------------

void __fastcall T_studentSubmenu::DocumentComboEditChange(TObject *Sender)
{
	// Get the selected text
	String selectedText = DocumentComboEdit->Text;

	// Check if the selected text has a corresponding link in linkMap
	if (documentlinkMap.find(selectedText) != documentlinkMap.end())
	{
		// Retrieve the link associated with the selected text
		String selectedLink = documentlinkMap[selectedText];

		// Check if the link is not empty
		if (!selectedLink.IsEmpty())
		{
			// Convert the link to WideString
			WideString wideLink = selectedLink;

			// Open the link in the default browser
			ShellExecute(0, L"open", wideLink.c_bstr(), NULL, NULL, SW_SHOWNORMAL);
		}
	}
}

//---------------------------------------------------------------------------

void __fastcall T_studentSubmenu::RegulationComboEditChange(TObject *Sender)
{
	// Get the selected text
	String selectedText = RegulationComboEdit->Text;

	// Check if the selected text has a corresponding link in regulationLinkMap
	if (regulationLinkMap.find(selectedText) != regulationLinkMap.end())
	{
		// Retrieve the link associated with the selected text
		String selectedLink = regulationLinkMap[selectedText];

		// Check if the link is not empty
		if (!selectedLink.IsEmpty())
		{
			// Convert the link to WideString
			WideString wideLink = selectedLink;

			// Open the link in the default browser
			ShellExecute(0, L"open", wideLink.c_bstr(), NULL, NULL, SW_SHOWNORMAL);
		}
	}
}

//---------------------------------------------------------------------------

void __fastcall T_studentSubmenu::BookComboEditChange(TObject *Sender)
{
	// Get the selected text
	String selectedText = BookComboEdit->Text;

	// Check if the selected text has a corresponding link in regulationLinkMap
	if (bookLinkMap.find(selectedText) != bookLinkMap.end())
	{
		// Retrieve the link associated with the selected text
		String selectedLink = bookLinkMap[selectedText];

		// Check if the link is not empty
		if (!selectedLink.IsEmpty())
		{
			// Convert the link to WideString
			WideString wideLink = selectedLink;

			// Open the link in the default browser
			ShellExecute(0, L"open", wideLink.c_bstr(), NULL, NULL, SW_SHOWNORMAL);
		}
	}
}



