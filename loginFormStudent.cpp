#include <fmx.h>
#include <fstream>  // To create an object file
#include <string>

// libraries in order to use vectors
#include <vector>
#include<sstream>
#include <cstring>
#pragma hdrstop

#include "loginFormStudent.h"   // loginFormStudent header file
#include "studentSubmenu.h" // StudentRecordList header file
#include "mainMenu.h"   // mainMenu header file
#include "registrationFormStudent.h"    // registrationFormStudent header file
#include "gradesSubmenu.h"  // Include the header file for the grades submenu form

using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
T_loginFormStudent *_loginFormStudent;
//T_gradesSubmenu *_gradesSubmenu = nullptr; // Initialize _gradesSubmenu

//---------------------------CONSTRUCTOR-------------------------------

__fastcall T_loginFormStudent::T_loginFormStudent(TComponent* Owner, TForm *mainMenu)
	: TForm(Owner)
{
}

//---------------------parseCommaDelimitedString3-----------------------------
/*
	This function takes a single string containing comma-separated values
	and splits it into individual strings, which are then stored in a vector.
*/
vector<string> parseCommaDelimitedString3(const string& line)
{
	vector<string> result;     // Create a vector of strings called result=[]
	stringstream s_stream(line);   // Create a stringstream object called s_stream and pass the
								   // line parameter (name,username,password) that the function receives
	string substr;

	while (getline(s_stream, substr, ','))  // Read each line until encounter a comma delimiter
	{
		result.push_back(substr);   // Store name,username,password into the reult vector --> result=[name,username,password]
	}
	return result;   // Return the variable
}

//-------------------ANSISTRING TO CHAR POINTER---------------------------------

const char* convertToCharPtr3(AnsiString ansiStr)
{
	return ansiStr.c_str();   // c.str() converts the data into a variable that can be stored into a const char pointer
}

//-------------------------loginButtonClick---------------------------------

void __fastcall T_loginFormStudent::loginButtonClick(TObject *Sender)
{
	ifstream myFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\registeredStudents.txt");  // Open the txt file for reading

	if (myFile.is_open())   // If the file is open
	{
		string line;    // Create a variable that represents data about one user

		while (getline(myFile, line))    // Iterate through the file and read line by line
		{
			vector<string> parsedLine = parseCommaDelimitedString3(line);  // Call the function, pass a line to it
																		  // and store the result into a vector

			// Check if there are at least 4 elements in the parsed line
			if (parsedLine.size() >= 4 )	// Check if the parsed line has at least 4 elements (name, username, password, id) before accessing them
			{	const char* name = parsedLine[0].c_str(); 	   // name is the first element
				const char* username = parsedLine[1].c_str();  // username is the first element
				const char* password = parsedLine[2].c_str();  // password is the second element
				const char* id = parsedLine[3].c_str();		   // id is the third element
															   // c.str() converts the data into a variable that can be stored into a const char pointer

				int studentID = stoi(parsedLine[3]); // Convert id to integer

				// If the username from the file and the username entered in the login form are equal, return 0 (username already exists)
				// Otherwise if the password from the file and the password entered in the login form are equal (login)
				if (strcmp(username, convertToCharPtr3(usernameEdit->Text)) == 0 && strcmp(password, convertToCharPtr3(passwordEdit->Text)) == 0)
				{
					myFile.close(); // Close the txt file after login

					// Clear the edit fields
					usernameEdit->Text = "";
					passwordEdit->Text = "";

					this->Close();  // Close the loginFormStudent

					// Set logged-in student ID for student submenu
					_studentSubmenu->SetLoggedInStudentID(studentID);

					// Set logged-in student ID for student submenu welcome message
					_studentSubmenu->SetLoggedInStudentName(name);

					_studentSubmenu->Show();   // After login, shows the student's submenu

					return; // Exit the function after successful login
				}
			}
		}

		// Close the file
		myFile.close();
		// Display message for incorrect username or password, if the account is not found
		ShowMessage("Incorrect username or password!");
	}
	else
	{
		// Display message for file open error
		ShowMessage("Error: Unable to open file!");
	}
}

//------------------------registerButtonClick---------------------------------

void __fastcall T_loginFormStudent::registerButtonClick(TObject *Sender)
{
		 this->Close(); // Close the current form (_loginFormStudent)
		_registrationFormStudent->Show();   // Show the _registrationFormStudent form
}

//-------------------------backButtonClick--------------------------------

void __fastcall T_loginFormStudent::backButtonClick(TObject *Sender)
{
	// Clear the fields
	usernameEdit->Text = "";
	passwordEdit->Text = "";
	this->Close();        // Close the current form (_loginFormStudent)
	_mainMenu->Show();    // Show the _mainMenu form
}

//--------------------------FormCreate---------------------------------

void __fastcall T_loginFormStudent::FormCreate(TObject *Sender)
{
    // Establish the passwordEdit as a password field (hide the password)
	passwordEdit->Password = true;
}

