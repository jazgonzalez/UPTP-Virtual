#include "StudentRecordList.h"

//----------------------CONSTRUCTOR-----------------------------------

// Initializes the list and loads existing records from file
StudentRecordList::StudentRecordList() : head(nullptr)
{
	loadRecordsFromFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents.txt"); // Load existing records from file on initialization
}

//-----------------------DESTRTUCTOR-----------------------------------

// Destructor to free allocated memory for linked list nodes
StudentRecordList::~StudentRecordList()
{
	// Traverse the linked list, starting from head, and delete each node
	StudentRecord* current = head;
	while (current != nullptr)
	{
		StudentRecord* next = current->next;
		delete current;
		current = next;
	}
}

//-------------------------setProfessorSubject----------------------------------

// Set the subject associated with the professor
void StudentRecordList::setProfessorSubject(const string& subject)
{
	professorSubject = subject;
}

//---------------------------insertRecord-------------------------------

bool StudentRecordList::insertRecord(int id, const string& subject, float mark, const string& grade)
{
	// Check if the record already exists
	if (recordExists(id, subject))
	{
		ShowMessage("Record already exists. Cannot insert duplicate.");
		return false; // Exit without inserting the record
	}

	// Check if the student is registered
	if (!isStudentRegistered(id))
	{
		ShowMessage("There is no registered student with the given ID");
		return false; // Exit if student is not registered
	}

	// Create a new StudentRecord instance with id, subject, mark and grade
	StudentRecord* newRecord = new StudentRecord(id, subject, mark, grade);

	// Insert the new record at the beginning of the list
	newRecord->next = head;
	head = newRecord;

	// Append/Insert new record to the end of the file
	ofstream outFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents.txt", ios::app);
	if (!outFile)   //if the .txt couldn´t be openned
	{
		ShowMessage("Error: Unable to open file recordStudents.txt for appending.");
		delete newRecord; // deletes the record in the linked list   (Clean up allocated memory)
		return false;  //goes out of the insertRecord function
	}

	// Save the full grade string to the file
	outFile << id << "," << subject << "," << mark << "," << grade << "\n";
	outFile.close();

	// If all operations succeed, show success message   and goes out of the insertRecord function
	ShowMessage("Record inserted successfully!");

	return true; // Successfully inserted the record
}

//--------------------------isStudentRegistered----------------------------------

bool StudentRecordList::isStudentRegistered(int id)
{
	ifstream inFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\registeredStudents.txt");
	if (!inFile)
	{
		cerr << "Error1: Unable to open file registeredStudents.txt for reading." << endl;
		return false; // Return false if file cannot be opened
	}

	string line;
	bool found = false;
	while (getline(inFile, line))
	{
		// Tokenize the line to extract fields
		istringstream iss(line);
        string name, username, password, idStr;

        // Read fields from the line
		if (getline(iss, name, ',') &&
			getline(iss, username, ',') &&
			getline(iss, password, ',') &&
			getline(iss, idStr, ','))
			{

			// Convert idStr to integer idFromFile
			int idFromFile = stoi(idStr);

            // Check if idFromFile matches the id we are looking for
			if (idFromFile == id)
			{
				found = true;
				break; // Found the ID in registered students list, no need to continue searching
			}
		}
	}

	inFile.close();

	return found; // Return whether ID was found in registered students list
}

//---------------------recordExists-----------------------------------

/*
The record is search in both the linked list and the txt file, because when
we close the program, the linked list is removed from memory, but the records
are still existing in the txt file; which we use as our "database" system
*/

bool StudentRecordList::recordExists(int id, const string& subject)
{
	// Check if a record with the same ID and subject already exists in the linked list
	StudentRecord* current = head;
	while (current != nullptr)
	{
		if (current->id == id && current->subject == subject)
		{
			return true; // Found a matching record in memory
		}
		current = current->next;
	}

	// Check if a record with the same ID and subject already exists in the file
	ifstream inFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents.txt");
	if (!inFile)
	{
		cerr << "Error2: Unable to open file recordStudents.txt for reading." << endl;
		return false; // Assume record doesn't exist if file cannot be opened
	}

	string line;
	while (getline(inFile, line))
	{
		istringstream iss(line);
		string idStr, subjectFromFile;

		// Read ID and subject from the file
		if (getline(iss, idStr, ',') &&
			getline(iss, subjectFromFile, ','))
		{

				int idFromFile = stoi(idStr);

				// Check if the current record in the file matches the search criteria
				if (idFromFile == id && subjectFromFile == subject)
				{
					inFile.close();
					return true; // Found a matching record in the file
				}
		}
	}

	inFile.close();
	return false; // No matching record found in memory or file
}

//-----------------------searchRecord----------------------------------

StudentRecord* StudentRecordList::searchRecord(int id, const string& subject)
{
	// Open file to search for a record with given ID and subject
	ifstream inFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents.txt");
	if (!inFile)
	{
		cerr << "Error3: Unable to open file recordStudents.txt for reading." << endl;
		return nullptr;
	}

	string line;
	while (getline(inFile, line))
	{
		istringstream iss(line);
		string idStr, subjectFromFile, markStr, grade;

		// Read each field from the line
		if (getline(iss, idStr, ',') &&
			getline(iss, subjectFromFile, ',') &&
			getline(iss, markStr, ',') &&
			getline(iss, grade, ','))
		{

				// Convert string to respective types
				int idFromFile = stoi(idStr);
				float mark = stof(markStr);

				// Check if the current record matches the search criteria
				if (idFromFile == id && subjectFromFile == subject)
				{
					// Create and return a StudentRecord instance
					return new StudentRecord(id, subjectFromFile, mark, grade);
				}
		}
	}

	inFile.close();
	return nullptr; // If no record found, return nullptr
}

//------------------------modifyMark-----------------------------------

/*
The record is search in both the linked list and the txt file, because when
we close the program, the linked list is removed from memory, but the records
are still existing in the txt file; which we use as our "database" system
*/

bool StudentRecordList::modifyMark(int id, const string& subject, float newMark)
{
	// Check if the student is registered
	if (!isStudentRegistered(id))
	{
		ShowMessage("Error: The student is not registered. Cannot modify a grade for an unregistered ID.");
        return false; // Exit if the student is not registered
	}

	// Search for the record in the linked list (memory)
	StudentRecord* current = head;
	bool recordFound = false;

	// Traverse the linked list to find the record to update in memory
	while (current != nullptr)
	{
		if (current->id == id && current->subject == subject)
		{
            // Update the mark in memory
			current->mark = newMark;
		if (newMark >= 0 && newMark <= 59)
		{
			current->grade = "D";
		}
		else if (newMark >= 60 && newMark <= 65)
		{
			current->grade = "C";
		}
		else if (newMark >= 66 && newMark <= 70)
		{
			current->grade = "C+";
		}
		else if (newMark >= 71 && newMark <= 76)
		{
			current->grade = "B";
		}
		else if (newMark >= 77 && newMark <= 84)
		{
			current->grade = "B+";
		}
		else if (newMark >= 85 && newMark <= 91)
		{
			current->grade = "A";
		}
		else if (newMark >= 92 && newMark <= 100)
		{
			current->grade = "A+";
		}
			recordFound = true;
            break; // Exit loop once the record is found and updated
        }
        current = current->next; // Move to the next node in the linked list
	}

	// If the record was not found in memory, it still can be in the txt file
	// so we search here
    if (!recordFound)
	{
		// Attempt to modify the record in the file

		// Open the input file stream to read from recordStudents.txt
		ifstream inFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents.txt");
		if (!inFile)
        {
			ShowMessage("Error: Unable to open file recordStudents.txt for reading.");
            return false; // Exit if the file cannot be opened
        }

		// Open the output file stream to write to a temporary file
		ofstream outFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents_tmp.txt");
		if (!outFile)
		{
			ShowMessage("Error: Unable to open temporary file recordStudents_tmp.txt for writing.");
			inFile.close(); // Close input file stream before returning
			return false; // Exit if the temporary file cannot be opened
        }

        string line;
        bool recordUpdated = false;

        // Read each line from the input file stream
		while (getline(inFile, line))
		{
            // Parse the line into components: idStr, subjectFromFile, markStr, grade
            istringstream iss(line);
			string idStr, subjectFromFile, markStr, grade;

			if (getline(iss, idStr, ',') &&
				getline(iss, subjectFromFile, ',') &&
				getline(iss, markStr, ',') &&
				getline(iss, grade, ','))
			{
				// Convert idStr and markStr to integers and float respectively
				int idFromFile = stoi(idStr);   // Convert string to integer
				float markFromFile = stof(markStr); // Convert string to float

				// Check if the current line matches the id and subject parameters
				if (idFromFile == id && subjectFromFile == subject)
				{
                    // Update the grade based on the new mark
                    string newGrade;
                    if (newMark >= 0 && newMark <= 59)
                    {
                        newGrade = "D";
                    }
                    else if (newMark >= 60 && newMark <= 65)
                    {
                        newGrade = "C";
                    }
                    else if (newMark >= 66 && newMark <= 70)
                    {
                        newGrade = "C+";
                    }
                    else if (newMark >= 71 && newMark <= 76)
                    {
                        newGrade = "B";
                    }
                    else if (newMark >= 77 && newMark <= 84)
                    {
                        newGrade = "B+";
                    }
                    else if (newMark >= 85 && newMark <= 91)
                    {
                        newGrade = "A";
                    }
                    else if (newMark >= 92 && newMark <= 100)
                    {
						newGrade = "A+";
					}
					// Update the mark and grade in the temporary file
					outFile << id << "," << subject << "," << newMark << "," << newGrade << "\n";
					recordUpdated = true; // Variable indicating that the record was updated
				}
				else
                {
					// Write the unchanged record to the temporary file
                    outFile << idFromFile << "," << subjectFromFile << "," << markFromFile << "," << grade << "\n";
				}
			}
		}

        // Close both input and output file streams
		inFile.close();
        outFile.close();

        // If the record was updated in the file
        if (recordUpdated)
		{
			// Remove the original file
			if (remove("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents.txt") != 0)
			{
				ShowMessage("Error: Unable to delete original file recordStudents.txt.");
				return false; // Exit if original file cannot be deleted
            }

			// Rename the temporary file to the original file name
			if (rename("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents_tmp.txt", "C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents.txt") != 0)
			{
				ShowMessage("Error: Unable to rename temporary file recordStudents_tmp.txt.");
				return false; // Exit if temporary file cannot be renamed
			}

			ShowMessage("Record modified successfully in file!"); // Success message
		}
		else
		{
			ShowMessage("Record not found in file!"); // Error message if record was not found in the file
			remove("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents_tmp.txt"); // Remove temporary file
			// ShowMessage("TEMP REMOVED");        // DEBUG MESSAGE
		}

		// Reload records from file to synchronize memory with file data
		loadRecordsFromFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents.txt");

		return recordUpdated; // Return whether the record was successfully updated in the file
    }

    // If the record was found and updated in memory, rewrite the file with updated data

	// Open the output file stream to write to recordStudents.txt
	ofstream outFile("C:\\Users\\Jazlaptop\\Downloads\\DS_PROJECT\\DS_I flo (1)\\DS_I flo\\DS_flo\\Win32\\Debug\\recordStudents.txt");
	if (!outFile)
	{
		ShowMessage("Error: Unable to open file recordStudents.txt for writing.");
		return false; // Exit if the file cannot be opened
	}

    current = head;

	// Write each record from memory to the output file stream
	while (current != nullptr)
	{
		outFile << current->id << "," << current->subject << "," << current->mark << "," << current->grade << "\n";
		current = current->next; // Move to the next node in the linked list
	}

	outFile.close(); // Close the output file stream

	ShowMessage("Record modified successfully in memory!"); // Success message

	return true; // Return true indicating successful modification
}

//--------------------loadRecordsFromFile---------------------------------

/*
Reads student records from a specified text file and loads them into a linked list.
*/

void StudentRecordList::loadRecordsFromFile(const string& filename)
{
    // Open the input file stream
	ifstream inFile(filename);

	// Check if the file stream is open
	if (!inFile)
	{
		ShowMessage("Error4: Unable to open file recordStudents.txt for reading.");
		return;
	}

	string line;
	// Read each line from the file
	while (getline(inFile, line))

	{
		// Create a string stream from the read line
		istringstream iss(line);
		string idStr, subject, markStr, grade;

		// Parse the line by commas into individual components
		if (getline(iss, idStr, ',') &&
			getline(iss, subject, ',') &&
			getline(iss, markStr, ',') &&
			getline(iss, grade, ','))
		{

			// Convert idStr to an integer
			int id = stoi(idStr);
			// Convert markStr to a float
			float mark = stof(markStr);

			// Create a new StudentRecord with the parsed data
			StudentRecord* newRecord = new StudentRecord(id, subject, mark, grade);

			// Insert the new record at the beginning of the linked list
			newRecord->next = head;
			head = newRecord;
		}
	}

	// Close the file after processing all lines
	inFile.close();
}
