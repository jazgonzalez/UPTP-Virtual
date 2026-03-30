#include <fmx.h>
#include <fstream>  // To create an object file
#include <string>

// libraries in order to use vectors
#include <vector>
#include<sstream>

#pragma hdrstop

#include "loginProfessor.h" // loginProfessor header file
#include "registrationFormProfessor.h"  // registrationFormProfessor header file
#include "mainMenu.h"   // mainMenu header file
#include "professorClass.h" // professorClass header file
#include "professorSubmenu.h"   // professorSubmenu header file

using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
T_loginProfessor *_loginProfessor;

//---------------------------CONSTRUCTOR-------------------------------

__fastcall T_loginProfessor::T_loginProfessor(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------parseCommaDelimitedString-----------------------------
/*
	This function takes a single string containing comma-separated values
	and splits it into individual strings, which are then stored in a vector.
*/
vector<string> parseCommaDelimitedString(const string& line)
{
	vector<string> result;     // Create a vector of strings called result=[]
	stringstream s_stream(line);   // Create a stringstream object called s_stream and pass the
								   // line parameter (name,username,password) that the function receives
	string substr;

	while (getline(s_stream, substr, ','))  // Read each line until encounter a comma delimiter
	{
		result.push_back(substr);    // Store name,username,password into the reult vector --> result=[name,username,password]
	}
	return result;   // Return the variable
}

//-----------------------convertToCharPtr0---------------------------

// Function called convertToCharPtr() that return a const char pointer  and receive an ansistring
const char* convertToCharPtr0(AnsiString ansiStr)
{
	return ansiStr.c_str();   //c.str() converts the data into a variable that can be stored into a const char pointer
}

//----------------------registerButtonClick---------------------------------

void __fastcall T_loginProfessor::registerButtonClick(TObject *Sender)
{
	Close(); // Close the current form
	_registrationFormProfessor->Show(); // Shows the _registrationFormProfessor form

}
//-------------------------loginButtonClick-------------------------------

void __fastcall T_loginProfessor::loginButtonClick(TObject *Sender)
{
	ifstream myFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\registeredProfessors.txt");    // Open the txt file for reading

	if (myFile.is_open())   // If the file is open
	{
		string line;    // Create a variable that represents data about one user

		while (getline(myFile, line))    // Iterate through the file and read line by line
		{
			vector<string> parsedLine = parseCommaDelimitedString(line);  // Call the function, pass a line to it
																		  // and store the result into a vector

			// Check if there are at least 3 elements in the parsed line
			if (parsedLine.size() >= 3)
			{
				const char* name = parsedLine[0].c_str(); 	   // ame is the first element
				const char* username = parsedLine[1].c_str();  // username is the first element
				const char* password = parsedLine[2].c_str();  // password is the second element
															   // c.str() converts the data into a variable that can be stored into a const char pointer

				// If the username from the file and the username entered in the login form are equal, return 0 (username already exists)
				// Otherwise if the password from the file and the password entered in the login form are equal (login)
				if (strcmp(username, convertToCharPtr0(usernameEdit->Text)) == 0 && strcmp(password, convertToCharPtr0(passwordEdit->Text)) == 0)
				{
					myFile.close(); // Close the txt file after login

					// Clear the edit fields
					usernameEdit->Text = "";
					passwordEdit->Text = "";

					 // To show schdule of the professor
					 string professorName=parsedLine[0];   // Stores the professor name in a new variable

					 ScheduleP scheduleP; // Creates a new object
					 scheduleP.loadProfessorClasses();
					_professorClass = new T_professorClass(this);   // Dynamically allocates memory for _professorClass

					// Call the function to display the classes of the professor, providing its name and schedule
					_professorClass->displayClassMessage(professorName, scheduleP);

					// Function to save the logged professor's name (to use in the welcome message)
					_professorSubmenu->SetLoggedInProfessorName(name);

					_professorClass->Show();    // Show the _professorClass

					this->Close();  // Close the _loginProfessor form

					return; // Exit the function after successful login
				}
			}
		}

		// Close the file
		myFile.close();

		// Display message for incorrect username or password
		ShowMessage("Incorrect username or password!");
	}
	else
	{
		// Display message for file open error
		ShowMessage("Error: Unable to open file!");
	}
}

//-----------------------backButtonClick----------------------------------

void __fastcall T_loginProfessor::backButtonClick(TObject *Sender)
{
	this->Close();  // Close the current form (_loginProfessor)
    // Clear the edits
	usernameEdit->Text = "";
	passwordEdit->Text = "";
	_mainMenu->Show();  // Shows the _mainMenu form
}

//----------------------FormCreate----------------------------------

void __fastcall T_loginProfessor::FormCreate(TObject *Sender)
{
	// Establish the passwordEdit as a password field (hide the password)
    passwordEdit->Password = true;
}


