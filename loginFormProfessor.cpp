//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>  //to create an object file
#include <string>
//libraries in order to use vectors
#include <vector>
#include<sstream>

#pragma hdrstop

#include "loginProfessor.h"
#include "registrationFormProfessor.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
T_loginProfessor *_loginProfessor;
//---------------------------------------------------------------------------
__fastcall T_loginProfessor::T_loginProfessor(TComponent* Owner)
	: TForm(Owner)
{
}

//function called  parseCommaDelimitedString that return vector of strings
std::vector<std::string> parseCommaDelimitedString(const std::string& line)
{
	std::vector<std::string> result;     //create a vector of strings called result=[]
	std::stringstream s_stream(line);   //create a stringstream object called s_stream and pass the
										//line parameter (name,user,passw) that the function receives
	std::string substr;

	while (getline(s_stream, substr, ','))  //read each line until encounter a comma delimiter
	{
		result.push_back(substr);   //  store name,username,password into the reult vector --> result=[name,username,password]
	}
	return result;   //return the variable
}

//function called convertToCharPtr() that return a const char pointer  and receive an ansistring
const char* convertToCharPtr(AnsiString ansiStr)
{
	return ansiStr.c_str();   //c.str() converts the data into a variable that can be stored into a const char pointer
}

//---------------------------------------------------------------------------
void __fastcall T_loginProfessor::registerButtonClick(TObject *Sender)
{
	_registrationFormProfessor->Show();
}
//---------------------------------------------------------------------------
//evet handler for login button
void __fastcall T_loginProfessor::loginButtonClick(TObject *Sender)
{
	std::ifstream myFile("registeredUsers.txt");

	if (myFile.is_open())   //if the file is open
	{
		std::string line;    //create a variable that represents data about one user

		while (getline(myFile, line))    //iterate through the file and read line by line
		{
			std::vector<std::string> parsedLine = parseCommaDelimitedString(line);  //call the function, pass a line to  it
																					// and store the result into a vector

			// Check if there are at least two elements in the parsed line
			if (parsedLine.size() >= 2)
			{
				const char* name = parsedLine[0].c_str(); 	   // Assuming name is the first element
				const char* username = parsedLine[1].c_str();  // Assuming username is the first element
				const char* password = parsedLine[2].c_str();  // Assuming password is the second element
															   //c.str() converts the data into a variable that can be stored into a const char pointer

				//if the username from the file and the username entered in the login form are equal, return 0
				//and  if the password from the file and the password entered in the login form are equal
				if (std::strcmp(username, convertToCharPtr(usernameEdit->Text)) == 0 && std::strcmp(password, convertToCharPtr(passwordEdit->Text)) == 0) {
					ShowMessage("Login successful!");    //if they are the same, print a message
					myFile.close(); //close the file

					// Clear the edit fields

					usernameEdit->Text = "";
					passwordEdit->Text = "";

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
//---------------------------------------------------------------------------

