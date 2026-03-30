#ifndef StudentRecordListH
#define StudentRecordListH

#include <string>         // For using std::string
#include <fstream>        // For file I/O operations
#include <sstream>        // For string stream operations
#include <iostream>       // For basic I/O operations
#include <FMX.Dialogs.hpp> // For ShowMessage function in C++ Builder

using namespace std;

// Structure to hold student record information
struct StudentRecord
{
	int id;                // Student ID
	string subject;        // Subject name
	int mark;              // Mark obtained
	string grade;          // Grade awarded
	StudentRecord* next;   // Pointer to the next record in the list

	// Constructor to initialize a new student record
	StudentRecord(int id, const string& subject, float mark, const string& grade)
		: id(id), subject(subject), mark(mark), grade(grade), next(nullptr) {}
};

// Class to manage a linked list of student records
class StudentRecordList
{
	private:
		StudentRecord* head;        // Pointer to the head of the linked list
		string professorSubject;    // Subject associated with the professor

	public:
		// Constructor: Initializes the list and loads existing records from file
		StudentRecordList();

		// Destructor: Frees allocated memory for linked list nodes
		~StudentRecordList();

		// Getter for the head of the list
		StudentRecord* getHead() const { return head; }

		// Setter for the professor's subject
		void setProfessorSubject(const string& subject);

		// Inserts a new record into the list and file
		bool insertRecord(int id, const string& subject, float mark, const string& grade);

		// Checks if a student is registered
		bool isStudentRegistered(int id);

		// Checks if a record exists in the list or file
		bool recordExists(int id, const string& subject);

		// Searches for a record in the file
		StudentRecord* searchRecord(int id, const string& subject);

		// Modifies the mark of an existing record
		bool modifyMark(int id, const string& subject, float newMark);

		// Saves all records to a file
		//void saveRecordsToFile(const string& filename);

		// Loads all records from a file
		void loadRecordsFromFile(const string& filename);
};

#endif

