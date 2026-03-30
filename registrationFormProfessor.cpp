#include <fmx.h>        // Include the FMX library
#include <fstream>      // Include the file stream library
#include <string>       // Include the string library
#include <vector>       // Include the vector library
#include <sstream>      // Include the string stream library
#include <cstring>      // Include the C string library
#pragma hdrstop

//---------------------------------------------------------------------------

#include "registrationFormProfessor.h"  // registrationFormProfessor header file
#include "loginProfessor.h"             // loginProfessor header file
#include "mainMenu.h"                   // mainMenu header file
#include "professorSubmenu.h"

using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"

//---------------------------------------------------------------------------

// Create an instance of the T_registrationFormProfessor class
T_registrationFormProfessor *_registrationFormProfessor;

//--------------------------CONSTRUCTOR----------------------------

__fastcall T_registrationFormProfessor::T_registrationFormProfessor(TComponent* Owner)
	: TForm(Owner)
{
}

//-------------------------parseCommaDelimitedString5-------------------------------

vector<string> parseCommaDelimitedString5(const string& line)
{
	vector<string> result;              // Create a vector to store the parsed strings
	stringstream s_stream(line);        // Create a string stream object from the input line
	string substr;                      // Create a string to store each substring

	// Loop to split the line by commas
	while (getline(s_stream, substr, ','))
	{
		result.push_back(substr);       // Add each substring to the result vector
	}
	return result;                      // Return the result vector
}

//---------------------convertToCharPtr5------------------------------------

// Function to convert an AnsiString to a const char* pointer
const char* convertToCharPtr5(AnsiString ansiStr)
{
	return ansiStr.c_str();             // Return the C string representation of the AnsiString
}

//-------------------------isUsernameInFile--------------------------------

// Function to check if a username exists in a given file
bool T_registrationFormProfessor::isUsernameInFile(const string& username, const string& filename) {
	ifstream file(filename);     // Open the file for reading
	if (!file.is_open())   // Check if the file is open
	{
		return false;     // Return false if the file cannot be opened
	}

	string line;   // Create a string to store each line read from the file
	// Loop to read each line from the file
	while (getline(file, line))
	{
		vector<string> parsedLine = parseCommaDelimitedString5(line); // Parse the line
		if (!parsedLine.empty() && parsedLine[1] == username)  // Check if the username matches
		{
			return true;  // Return true if the username is found
		}
	}

	return false;    // Return false if the username is not found
}

//----------------------------saveButtonClick-------------------------------

// Event handler for the save button click
void __fastcall T_registrationFormProfessor::saveButtonClick(TObject *Sender) {
	string username = AnsiString(usernameEdit->Text).c_str(); // Get the username from the edit box

	// Check if the username exists in either file
	if (isUsernameInFile(username, "C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\registeredProfessors.txt") || isUsernameInFile(username, "C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\registeredStudents.txt"))
	{
		ShowMessage("Username already exists. Please choose a different username."); // Show an error message
	} else
	{
		fstream myFile; // Create a file stream object
		myFile.open("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\registeredProfessors.txt", ios::app); // Open the file for appending

		if (myFile.is_open())     // Check if the file is open
		{
			string name = AnsiString(nameEdit->Text).c_str(); // Get the name from the edit box
			string username = AnsiString(usernameEdit->Text).c_str(); // Get the username from the edit box
			string password = AnsiString(passwordEdit->Text).c_str(); // Get the password from the edit box

			// Check if any of the fields are empty
			if (name.empty() || username.empty() || password.empty())
			{
				 ShowMessage("Please fill in all fields before saving."); // Show an error message
				return; // Exit function without saving
			}


			// Validate the name input for only alphabets and spaces
			bool isValidName = true;
			for (char c : name) // Iterates over each character of the name
			{
				if (!isalpha(c) && c != ' ')    // If each character is neither an alphabetic character
				{                               // nor a space
					isValidName = false;    // Is not a valid name
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
			myFile << name << "," << username << "," << password << "\n";
            myFile.close();              // Close the file

			this->Close();               // Close the registration form
			// Clear the edit fields
			usernameEdit->Text = "";
			passwordEdit->Text = "";
			nameEdit->Text = "";

			_loginProfessor->Show();  // Show the login form
		}
		else
		{
			ShowMessage("Error: Unable to open file for writing!"); // Show an error message
		}
	}
}

//--------------------------backButtonClick----------------------------

// Event handler for the back button click
void __fastcall T_registrationFormProfessor::backButtonClick(TObject *Sender) {

	this->Close();            // Close the registration form
	_loginProfessor->Show();  // Show the login form
	// Clear the edit fields
	usernameEdit->Text = "";
	passwordEdit->Text = "";
	nameEdit->Text = "";
}

//-------------------------FormCreate-----------------------------------

void __fastcall T_registrationFormProfessor::FormCreate(TObject *Sender)
{
	// To hide the password
	passwordEdit->Password = true;
}


