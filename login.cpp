#include<iostream> // Include the input/output stream library
#include <limits> // Include the limits library for numeric_limits
#include <cstdlib>  // Include the cstdlib library for the system() function
#include <ctime> // Include the ctime library for time functions

using namespace std; // Use the standard namespace

// Define a structure for a user
struct user{
    string password; // Password field
    string username; // Username field
};

// Define a structure for a node in the user list
struct node{
    user User; // User field
    node* next; // Pointer to the next node
    node* prev; // Pointer to the previous node
};

// Class to represent a single class schedule
class ClassSchedule {
public:
    string subject;    // Subject of the class
    int dayOfWeek;     // Day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
    int startHour;     // Start hour of the class
    int startMinute;   // Start minute of the class
    int endHour;       // End hour of the class
    int endMinute;     // End minute of the class
    string classroom;  // Classroom where the class is held

    // Default constructor
    ClassSchedule() = default;

    // Constructor to initialize all properties
    ClassSchedule(string subj, int day, int sh, int sm, int eh, int em, string room)
        : subject(subj), dayOfWeek(day), startHour(sh), startMinute(sm), endHour(eh), endMinute(em), classroom(room) {}
};

// Class to manage multiple class schedules
class Schedule {
private:
    ClassSchedule* schedule;  // Dynamic array to store ClassSchedule objects
    int size;                 // Size of the dynamic array
    int classCount = 0;       // Number of classes added to the schedule

    // Get the current day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
    int getCurrentDayOfWeek() {
        time_t t = time(0);
        tm* now = localtime(&t);
        return now->tm_wday;
    }

    // Get the current hour
    int getCurrentHour() {
        time_t t = time(0);
        tm* now = localtime(&t);
        return now->tm_hour;
    }

    // Get the current minute
    int getCurrentMinute() {
        time_t t = time(0);
        tm* now = localtime(&t);
        return now->tm_min;
    }

public:
    // Constructor to initialize the dynamic array
    Schedule(int s) : size(s) {
        schedule = new ClassSchedule[size];
    }

    // Destructor to deallocate the dynamic array
    ~Schedule() {
        delete[] schedule;
    }

    // Add a class to the schedule
    void addClass(string subject, int dayOfWeek, int startHour, int startMinute, int endHour, int endMinute, string classroom) {
        if (classCount < size) {
            schedule[classCount++] = ClassSchedule(subject, dayOfWeek, startHour, startMinute, endHour, endMinute, classroom);
        } else {
            cout << "Cannot add more classes. Schedule is full." << endl;
        }
    }

    // Find and display the next or ongoing class
    void findNextClass() {
        int currentDay = getCurrentDayOfWeek();
        int currentHour = getCurrentHour();
        int currentMinute = getCurrentMinute();
        int currentTimeInMinutes = currentHour * 60 + currentMinute;
        bool found = false;

        // Iterate through each class in the schedule
        for (int i = 0; i < classCount; i++) {
            if (schedule[i].dayOfWeek == currentDay) {
                int classStartTimeInMinutes = schedule[i].startHour * 60 + schedule[i].startMinute;
                int classEndTimeInMinutes = schedule[i].endHour * 60 + schedule[i].endMinute;
                int timeDifference = classStartTimeInMinutes - currentTimeInMinutes;

                // Check if the class is currently ongoing
                if (currentTimeInMinutes >= classStartTimeInMinutes && currentTimeInMinutes < classEndTimeInMinutes) {
                    cout << "Your " << schedule[i].subject << " class is currently ongoing in " << schedule[i].classroom << "\n";
                    found = true;
                    break;
                }
                // Check if the class starts within the next hour
                else if (timeDifference > 0 && timeDifference <= 60) {
                    cout << "Your " << schedule[i].subject << " class starts in " << timeDifference << " minutes in " << schedule[i].classroom << "\n";
                    found = true;
                    break;
                }
            }
        }

        // If no class is found
        if (!found) {
            cout << "No upcoming or ongoing classes today :)\n";
        }
    }
};

// Define a class for a user list
class userList{
private:
    node* head; // Pointer to the head of the list
    node* tail; // Pointer to the tail of the list
public:
    userList();    // Constructor declaration
    void registerUser(string&, string&); // Function to register a new user
    bool validateUser(string&, string&); // Function to validate a user
    bool isEmpty(); // Function to check if the list is empty
};

// Constructor for the userList class
userList::userList()
{
    head = NULL; // Initialize head pointer to NULL
    tail = NULL; // Initialize tail pointer to NULL
}

// Function to register a new user
void userList::registerUser(string& _username, string& _password)
{
	node* current = head;
    while (current != NULL) {
        if (current->User.username == _username) {
            cout << "Username '" << _username << "' is already taken. Please try again"<<endl;
            cout << "Username: ";
            cin >> _username; // Prompt the user to enter a different username
            cout << "Password: ";
            cin >> _password;
            current = head; // Reset the pointer to the head of the list to check the new username
        } else {
            current = current->next; // Move to the next node
        }
    }
	
    node* newNode = new node;    // Create a new node 'newUser'
    newNode->User.username = _username;    // Assign _username to the User 'username' field
    newNode->User.password = _password;    // Assign _password to the User 'password' field
    newNode->prev = NULL;    // Set the prev pointer to point to nothing
    newNode->next = NULL;    // Set the next pointer to point to nothing
    if(head==NULL)
    {
        head = tail = newNode; // If the list is empty, set head and tail to the new node
    }
    else{
        tail->next = newNode;    // Add the newNode after the current tail
        newNode->prev = tail;    // Update the newNode prev pointer to point to the current tail
        tail = newNode;    // Update the tail to be the newNode
    }
}

// Function to validate a user
bool userList::validateUser(string& _username, string& _password) 
{
    if (isEmpty()) 
    {
        cout<<"No users registered. Please register first."<<endl; // If the list is empty, display a message
        return false;
    }

    node* current = head;
    while (current != NULL) 
    {
        if (current->User.username == _username) 
        {
            if (current->User.password == _password) 
            {
                return true; // If username and password match, return true
            } else 
            {
                cout<<"Invalid password. Please try again."<<endl<<endl; // If password is incorrect, display a message
                return false;
            }
        }
        current = current->next; // Move to the next node
    }
    cout<<"Username not found. Please try again."<<endl<<endl; // If username is not found, display a message
    return false;
}

// Function to check if the list is empty
bool userList::isEmpty() 
{
    return head == NULL; // Return true if head pointer is NULL, indicating an empty list
}

// Function to get integer input from the user
bool getIntInput(int& input, int menuContext) 
{
    while (true) 
    {
        if (cin >> input) 
        {
            // Check if the input is within the range of options for principal menu 
            if (menuContext == 0 && (input < 1 || input > 2)) {
                cout << "Invalid choice. Please select 1 or 2." << endl;
                // Prompt the user again
                cout << "Enter your choice: ";
                continue;
            }
            
            // Check if the input is within the range of options for sub menu 
            if (menuContext == 1 && (input < 1 || input > 3)) {
                cout << "Invalid choice. Please select 1, 2 or 3." << endl;
                // Prompt the user again
                cout << "Enter your choice: ";
                continue;
            }
            
            
            // Check if the input is within the range of options for student menu 
            if (menuContext == 2 && (input < 1 || input > 4)) {
                cout << "Invalid choice. Please select 1, 2, 3 or 4." << endl;
                // Prompt the user again
                cout << "Enter your choice: ";
                continue;
            }
    
            // Input was within the range of options
            return true;
        } 
        else 
        {
            // Clear the error flag
            cin.clear();
            // Discard the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Display a message for invalid input based on menu context
            if (menuContext == 0) {
                cout << "Invalid choice. Please select 1 or 2." << endl;
            } else if(menuContext == 1) {
               cout << "Invalid choice. Please select 1, 2 or 3" << endl;
            }
            else if(menuContext == 2) {
            	cout << "Invalid choice. Please select 1, 2, 3 or 4" << endl;
			}
            // Prompt the user again
            cout << "Enter your choice: ";
            // Return false to indicate invalid input
            system("PAUSE"); // Pause to allow the user to see the message
            return false;
        }
    }
}

// Function to display the Principal menu
void displayPrincipalMenu() 
{
    cout<< "\t------------------------------------"<<endl;
    cout<< "\t|    WELCOME TO THE UPTP SYSTEM    |"<<endl;
    cout<< "\t------------------------------------"<<endl<<endl;    
    cout<< "\t------------------------------------"<<endl;
    cout<< "\t|         SELECT YOUR ROLE         |"<<endl;
    cout<< "\t------------------------------------"<<endl<<endl;
    cout<<"1. Professor"<<endl;
    cout<<"2. Student"<<endl;
    cout<<"Enter your choice: ";
}

// Function to display the submenu for user actions
void displaySubMenu1() 
{
    cout<<"1. Register a new user"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter your choice: ";
}

// Function to display the student menu
void displayStudentMenu() 
{
    cout<<"\t------------------------------------"<<endl;
    cout<<"\t|          STUDENT MENU            |"<<endl;
    cout<<"\t------------------------------------"<<endl;
    cout << endl << "1. Classes" << endl;
    cout << "2. Grades" << endl;
    cout << "3. TA's Office Hours" << endl;
    cout << "4. Logout" << endl;
    cout << "Enter your choice: ";
}

void studentSchedule(userList& list, string& username) 
{
	system("CLS"); // Clear the console
    cout << "Welcome " << username << "!" << endl;
    
    int maxSize = 100;  // Maximum number of classes that can be added to the schedule
    Schedule manager(maxSize);  // Create a Schedule object
    
 	// Adding classes on Monday
    manager.addClass("Engineering Materials", 1, 8, 0, 10, 0,"A2");     
    manager.addClass("Introduction To Industrial Engineering", 1, 10, 30, 12, 30,"A2"); 
    manager.addClass("Data Structures - Practice", 1, 13, 30, 15, 30,"PC LAB");  
    manager.addClass("Chinese III", 1, 16, 00, 18, 00,"A2"); 


    // Adding classes on Tuesday
    manager.addClass("Engineering Materials", 2, 8, 0, 10, 0,"A3"); 
    manager.addClass("Digital Logic Design - Practice",2,10 ,30 ,12 ,30 ,"Electronics Lab"); 
	manager.addClass("Data Structures - Theory",2,13 ,30 ,17 ,00 ,"A3"); 

    // Adding classes on Wednesday
   	manager.addClass("English III",3,8, 0, 10, 0,"A1"); 
   	manager.addClass("Object Oriented Programming - Theory",3 ,10 ,30 ,14 ,30,"PC LAB"); 
   	manager.addClass("Introduction to Industrial Engineering",3, 14,30 ,18,0,"A1"); 

	// Adding classes on Thursday
	manager.addClass("Digital Logic Design - Practice",4,8, 0, 10, 0,"Electronics Lab"); 
   	manager.addClass("Digital Logic Design - Theory",4 ,10 ,30 ,14 ,30,"Electronics Lab"); 
  
	// Adding classes on Friday
    manager.addClass("English III", 5, 8, 0, 10, 0,"A1");      
    manager.addClass("Chinese III", 5, 10, 30, 12, 30,"A5");   
    manager.addClass("Object Oriented Programming - Practice", 5, 13, 30, 15, 30,"PC LAB"); 

    manager.findNextClass();  // Find and print information about the next or ongoing class

	system("PAUSE"); // Pause to allow user to see the message
   
	system("CLS");
	cout<<"\t------------------------------------"<<endl;
    cout<<"\t|         STUDENT MENU           	|"<<endl;
    cout<<"\t------------------------------------"<<endl<<endl;
}

// Function to handle professor actions
void handleProfessorActions(userList& list) 
{
    int choice;
    string username, password;
    while (true) 
    {
        displaySubMenu1();
        if (!getIntInput(choice, 1)) 
        {
            continue;  // Invalid input, prompt again
        }

        if (choice == 1)    // Register user
        {
            cout<<"Create a username: ";
            cin>>username;
            cout<<"Create a password: ";
            cin>>password;
            list.registerUser(username, password);
            cout<<"User registered successfully!"<<endl<<endl;
        } else if (choice == 2)    // Login
        {
            if (list.isEmpty()) 
            {
                cout<<"No users registered. Please register first."<<endl<<endl;;
                continue;
            }
            bool validUser = false;
            do 
            {
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter password: ";
                cin>>password;
                validUser = list.validateUser(username, password);
            } while (!validUser);
           // handleProfessorActions2(list, username);  // Navigate to professor menu
        } else if (choice == 3)    // Exit
        {
            return;
        } 
    }
}


// Function to handle student actions
void handleStudentActions2(userList& list, string& username) 
{
    int choice;
    while (true) 
    {
        system("CLS"); // Clear the screen before displaying the student menu
        displayStudentMenu();
        if (!getIntInput(choice, 2)) 
        {
            continue;  // Invalid input, prompt again
        }

        if (choice == 1) 
        {
        	system("CLS");
            cout<<"Displaying Classes..."<<endl;
            studentSchedule(list, username);  // Navigate to professor menu
            //system("PAUSE"); // Pause to allow user to see the message
        } else if (choice == 2) 
        {
        	system("CLS");
            cout<<"Displaying Grades..."<<endl;
            system("PAUSE"); // Pause to allow user to see the message
        } else if (choice == 3) 
        {
        	system("CLS");
            cout<<"Displaying TA's Office Hours..."<<endl;
            system("PAUSE"); // Pause to allow user to see the message
        } else if (choice == 4) 
        {
            system("CLS");    // Clear the console before going back to the student menu
            cout<<"\t------------------------------------"<<endl;
            cout<<"\t|          STUDENT MENU            |"<<endl;
            cout<<"\t------------------------------------"<<endl<<endl;
            return;  // Exit the student menu and return to the student menu
        } else 
        {
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }
}

// Function to handle students actions
void handleStudentsActions(userList& list) 
{
    int choice;
    string username, password;
    while (true) 
    {
        displaySubMenu1();
        if (!getIntInput(choice, 1)) 
        {
            continue;  // Invalid input, prompt again
        }

        if (choice == 1)    // Register user
        {
            cout<<"Create a username: ";
            cin>>username;
            cout<<"Create a password: ";
            cin>>password;
            list.registerUser(username, password);
            cout<<"User registered successfully!"<<endl<<endl;
        } else if (choice == 2)    // Login
        {
            if (list.isEmpty()) 
            {
                cout<<"No users registered. Please register first."<<endl<<endl;;
                continue;
            }
            bool validUser = false;
            do 
            {
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter password: ";
                cin>>password;
                validUser = list.validateUser(username, password);
            } while (!validUser);
            handleStudentActions2(list, username);  // Navigate to student menu
        } else if (choice == 3)    // Exit
        {
            return;
        } 
    }
}

int main() 
{
    userList list; // Create an instance of the userList class
    int userType;

    while (true) 
    {
        system("CLS"); // Clear the console
        displayPrincipalMenu(); // Display the principal menu
        if (!getIntInput(userType, 0)) 
        {
            continue;  // Invalid input, prompt again
        }
    
        system("CLS"); // Clear the console before displaying submenus
        
        if (userType == 1)    // If it is a professor
        {
            cout<<"\t------------------------------------"<<endl;
            cout<<"\t|         PROFESSOR MENU           |"<<endl;
            cout<<"\t------------------------------------"<<endl<<endl;
            handleProfessorActions(list); // Call the function to handle professor actions
        } else if (userType == 2)    // If it is a student
        {
            cout<<"\t------------------------------------"<<endl;
            cout<<"\t|          STUDENT MENU            |"<<endl;
            cout<<"\t------------------------------------"<<endl<<endl;
            handleStudentsActions(list); // Call the function to handle student actions
        } 
    }
    
    return 0; // Return 0 to indicate successful program execution
}



