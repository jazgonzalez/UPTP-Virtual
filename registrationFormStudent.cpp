#include <fmx.h>
#include<fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#pragma hdrstop

#include "registrationFormStudent.h"
#include "loginFormStudent.h"
#include "mainMenu.h"
#include "studentSubmenu.h"

using namespace std;

#include "studentSubmenu.h" // Include the header file for the student submenu form

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
T_registrationFormStudent *_registrationFormStudent;

//---------------------------CONSTRUCTOR---------------------------------

__fastcall T_registrationFormStudent::T_registrationFormStudent(TComponent* Owner)
	: TForm(Owner)
{
}

//----------------------parseCommaDelimitedString2---------------------------------

// Function to parse a comma-delimited string and return a vector of substrings
vector<string> parseCommaDelimitedString2(const string& line)
{
	vector<string> result;              // Create a vector to store the parsed strings
	stringstream s_stream(line);        // Create a string stream object from the input line
	string substr;                      // Create a string to store each substring

	// Loop to split the line by commas and store them in a vector result = {"","","password"}
	while (getline(s_stream, substr, ','))
	{
		result.push_back(substr);
	}
	return result;
}

//------------------------convertToCharPtr--------------------------------

// Function to convert AnsiString to const char*
const char* convertToCharPtr(AnsiString ansiStr)
{
	return ansiStr.c_str();
}

//----------------------isUsernameInFile------------------------------

// Function to check if a username exists in a given file
bool T_registrationFormStudent::isUsernameInFile(const string& username, const string& filename)
{
	ifstream file(filename);    // Open the file for reading
	if (!file.is_open())    // Check if the file is open
	{
		return false;  // Return false if the file cannot be opened
	}

	string line;   // Create a string to store each line read from the file
	// Loop to read each line from the file
	while (getline(file, line))
	{

		vector<string> parsedLine = parseCommaDelimitedString2(line); // Parse the line
		if (!parsedLine.empty() && parsedLine[1] == username)   // Check if the username matches
		{
			return true;   // Return true if the username is found
		}
	}

	return false;   // Return false if the username is not found
}

//------------------------isNumeric------------------------------------

// Function to check if a string consists of numeric digits
bool isNumeric(const string& str)
{
	return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

//-----------------------saveButtonClick--------------------------------

// Event handler for the saveButton click event
void __fastcall T_registrationFormStudent::saveButtonClick(TObject *Sender)
{
	string id = AnsiString(idEdit->Text).c_str(); // Get the id from the edit box
	string name = AnsiString(nameEdit->Text).c_str(); // Get the name from the edit box
	string username = AnsiString(usernameEdit->Text).c_str(); // Get the username from the edit box
	string password = AnsiString(passwordEdit->Text).c_str(); // Get the password from the edit box

	// Check if any of the fields are empty
	if (id.empty() || name.empty() || username.empty() || password.empty())
	{
		ShowMessage("Please fill in all fields before saving."); // Show an error message
		return; // Exit function without saving
	}

	// Check if id consists of numeric digits
	if (!isNumeric(id))
	{
		ShowMessage("ID must contain numeric digits only."); // Show an error message
		return; // Exit function without saving
	}

	// Check if the username exists in either file
	if (isUsernameInFile(username, "C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECTO\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\registeredProfessors.txt") || isUsernameInFile(username, "C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\registeredStudents.txt"))
	{
		ShowMessage("Username already exists. Please choose a different username."); // Show an error message
	} else
	{
		fstream myFile;                 // Create a file stream object
		myFile.open("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\registeredStudents.txt",ios::app); // Open the file for appending

		if (myFile.is_open())   // Check if the file is open
		{
			string name = AnsiString(nameEdit->Text).c_str(); // Get the name from the edit box
			// Validate the name input for only alphabets and spaces
			bool isValidName = true;
			for (char c : name) // Iterates over each character of the name
			{
				if (!isalpha(c) && c != ' ')    // If each character is neither an alphabetic character
				{                               // nor a space
					isValidName = false;     // Is not a valid name
					break;
				}
			}

			// If the name contains invalid characters, show an error message and return
			if (isValidName==false)
			{
				ShowMessage("Invalid characters in the name field. Please enter letters only");
				return; // Exit function without saving
			}


			// Write name, username, and password to file
			myFile << name << "," << username << "," << password << "," << id << "\n" ;
			myFile.close();  // Close the file

			this->Close();   // Close the registration form

			// Clear the edit fields saving the register
			idEdit->Text = "";
			usernameEdit->Text = "";
			passwordEdit->Text = "";
			nameEdit->Text = "";

			//_studentSubmenu->SetRegistrationStudentName(name);  // Set logged-in student ID for student submenu welcome message

			_loginFormStudent->Show(); // Show the login form
		} else
		{
			ShowMessage("Error: Unable to open file for writing!"); // Show an error message
		}
	}
}

//---------------------backButtonClick---------------------------

void __fastcall T_registrationFormStudent::backButtonClick(TObject *Sender)
{
	this->Close();  // Close the _registrationFormStudent
	_loginFormStudent->Show();  // Show the _loginFormStudent
	// Clear the edit fields
	idEdit->Text = "";
	usernameEdit->Text = "";
	passwordEdit->Text = "";
	nameEdit->Text = "";
}
//---------------------------backButtonClick-----------------------------

void __fastcall T_registrationFormStudent::FormCreate(TObject *Sender)
{
	// To hide the password
	passwordEdit->Password = true;
}
