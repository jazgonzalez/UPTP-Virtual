//---------------------------USANDO VECTORES------------------------

//#include <iostream>  // Include the input/output stream library
//#include <vector>    // Include the vector container library
//#include <ctime>     // Include the C time library for time-related functions
//#include <string>    // Include the string library for string manipulation
//
//using namespace std;  // Use the standard namespace to avoid prefixing with std::
//
//class ClassSchedule {  // Define a class to represent a class schedule
//public:
//    string subject;    // Subject of the class
//    int dayOfWeek;     // Day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
//    int startHour;     // Start hour of the class
//    int startMinute;   // Start minute of the class
//    int endHour;       // End hour of the class
//    int endMinute;     // End minute of the class
//    string classroom;  // Classroom where the class is held
//
//    // Constructor to initialize class properties
//    ClassSchedule(string subj, int day, int sh, int sm, int eh, int em, string room) 
//        : subject(subj), dayOfWeek(day), startHour(sh), startMinute(sm), endHour(eh), endMinute(em), classroom(room) {}
//};
//
//class Schedule {  // Define a class to manage class schedules
//private:
//    vector<ClassSchedule> schedule;  // Vector to store ClassSchedule objects
//
//    // Function to get the current day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
//    int getCurrentDayOfWeek() {
//        time_t t = time(0);  // Get current time in seconds since epoch
//        tm* now = localtime(&t);  // Convert time to local time structure
//        return now->tm_wday;  // Return the day of the week (0-6)
//    }
//
//    // Function to get the current hour
//    int getCurrentHour() {
//        time_t t = time(0);  // Get current time in seconds since epoch
//        tm* now = localtime(&t);  // Convert time to local time structure
//        return now->tm_hour;  // Return the current hour (0-23)
//    }
//
//    // Function to get the current minute
//    int getCurrentMinute() {
//        time_t t = time(0);  // Get current time in seconds since epoch
//        tm* now = localtime(&t);  // Convert time to local time structure
//        return now->tm_min;  // Return the current minute (0-59)
//    }
//
//public:
//    // Function to add a class to the schedule
//    void addClass(string subject, int dayOfWeek, int startHour, int startMinute, int endHour, int endMinute, string classroom) {
//        schedule.push_back(ClassSchedule(subject, dayOfWeek, startHour, startMinute, endHour, endMinute, classroom));  // Add class to vector
//    }
//
//    // Function to find the next class or ongoing class
//    void findNextClass() {
//        int currentDay = getCurrentDayOfWeek();  // Get the current day of the week
//        int currentHour = getCurrentHour();      // Get the current hour
//        int currentMinute = getCurrentMinute();  // Get the current minute
//
//        int currentTimeInMinutes = currentHour * 60 + currentMinute;  // Convert current time to total minutes
//        bool found = false;  // Flag to indicate if a class is found
//
//        for (const auto& cls : schedule) {  // Iterate through each class in the schedule
//            if (cls.dayOfWeek == currentDay) {  // Check if the class is scheduled for the current day
//                int classStartTimeInMinutes = cls.startHour * 60 + cls.startMinute;  // Convert class start time to total minutes
//                int classEndTimeInMinutes = cls.endHour * 60 + cls.endMinute;  // Convert class end time to total minutes
//                int timeDifference = classStartTimeInMinutes - currentTimeInMinutes;  // Calculate time difference between current time and class start time
//
//                if (currentTimeInMinutes >= classStartTimeInMinutes && currentTimeInMinutes < classEndTimeInMinutes) {
//                    cout << "Your " << cls.subject << " class is currently ongoing in " << cls.classroom << "\n";  // Print message if class is ongoing
//                    found = true;  // Set found flag to true
//                    break;  // Exit the loop as we have found the current ongoing class
//                } else if (timeDifference >= 0 && timeDifference <= 60) {
//                    cout << "Your " << cls.subject << " class starts in " << timeDifference << " minutes in " << cls.classroom << "\n";  // Print message if class starts within the next hour
//                    found = true;  // Set found flag to true
//                    break;  // Exit the loop as we have found the next class starting within an hour
//                }
//            }
//        }
//
//        if (!found) {
//            cout << "No upcoming or ongoing classes today :)\n";  // Print message if no upcoming or ongoing classes are found
//        }
//    }
//};
//
//int main() {
//    Schedule manager;  // Create a Schedule object

	
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



//------------------MENU DE ESTUDIANTE PARA INDICAR EL AULA
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

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
	ClassSchedule();
    // Constructor to initialize all properties
    ClassSchedule(string , int, int, int , int , int, string);
};
// Default constructor
ClassSchedule::ClassSchedule()
{
	subject="";
	dayOfWeek=0;
	startHour=0;
	startMinute=0;   // Start minute of the class
    endHour=0;       // End hour of the class
    endMinute=0;     // End minute of the class
	classroom="";  // Classroom where the class is held

	
}

// Constructor to initialize all properties
ClassSchedule::ClassSchedule(string subj, int day, int sh, int sm, int eh, int em, string room)
{
	subject=subj; 
	dayOfWeek=day;
	startHour=sh;
	startMinute=sm; 
	endHour=eh; 
	endMinute=em;
	classroom=room;
}
// Class to manage multiple class schedules
class Schedule 
{
	private:
	    ClassSchedule* schedule;  // Dynamic array to store ClassSchedule objects
	    int size;                 // Size of the dynamic array
	    int classCount = 0;       // Number of classes added to the schedule
		// Get the current day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
	    int getCurrentDayOfWeek();
	    // Get the current hour
	    int getCurrentHour();
	    // Get the current minute
	    int getCurrentMinute();
	    // Constructor to initialize the dynamic array

	public:
	    Schedule(int);
	    // Destructor to deallocate the dynamic array
	    ~Schedule();
	    // Add a class to the schedule
	    void addClass(string , int , int , int , int , int, string );
	    // Find and display the next or ongoing class
	    void findNextClass();
	};
	

	// Constructor to initialize the dynamic array
	Schedule::Schedule(int s) 
	{
		size=s;
	    schedule = new ClassSchedule[size];
	}
	
	// Destructor to deallocate the dynamic array
	Schedule::~Schedule() 
	{
	    delete[] schedule;
	}
	
	// Get the current day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
	int Schedule::getCurrentDayOfWeek()
	{
	    time_t t = time(0);
	    tm* now = localtime(&t);
	    return now->tm_wday;
	}
	
	// Get the current hour
	int Schedule::getCurrentHour() 
	{
	    time_t t = time(0);
	    tm* now = localtime(&t);
	    return now->tm_hour;
	}
	
	// Get the current minute
	int Schedule::getCurrentMinute() 
	{
	    time_t t = time(0);
	    tm* now = localtime(&t);
	    return now->tm_min;
	}
	
	// Add a class to the schedule
	void Schedule::addClass(string subject, int dayOfWeek, int startHour, int startMinute, int endHour, int endMinute, string classroom) 
	{
	    if (classCount < size) 
		{
	        schedule[classCount++] = ClassSchedule(subject, dayOfWeek, startHour, startMinute, endHour, endMinute, classroom);
	    }
		//else 
//		{
//	        cout << "Cannot add more classes. Schedule is full." << endl;
//	    }
	}
	
	// Find and display the next or ongoing class
	void Schedule::findNextClass() {
	    int currentDay = getCurrentDayOfWeek();
	    int currentHour = getCurrentHour();
	    int currentMinute = getCurrentMinute();
	    int currentTimeInMinutes = currentHour * 60 + currentMinute;
	    bool found = false;
	
	    // Iterate through each class in the schedule
	    for (int i = 0; i < classCount; i++) 
		{
	        if (schedule[i].dayOfWeek == currentDay) 
			{
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
	    if (!found) 
		{
	        cout << "No upcoming or ongoing classes for the next hour :)\n";
	    }
	}

int main() {
    int maxSize = 100;  // Maximum number of classes that can be added to the schedule
    Schedule manager(maxSize);  // Create a Schedule object
    
    // Adding classes on Monday
    manager.addClass("Engineering Materials", 1, 8, 0, 10, 0, "A2");     
    manager.addClass("Introduction To Industrial Engineering", 1, 10, 30, 12, 30, "A2"); 
    manager.addClass("Data Structures - Practice", 1, 13, 30, 15, 30, "PC LAB");  
    manager.addClass("Chinese III", 1, 16, 0, 18, 0, "A2"); 

    // Adding classes on Tuesday
    manager.addClass("Engineering Materials", 2, 8, 0, 10, 0, "A3"); 
    manager.addClass("Digital Logic Design - Practice", 2, 10, 30, 12, 30, "Electronics Lab"); 
    manager.addClass("Data Structures - Theory", 2, 13, 30, 17, 0, "A3"); 

    // Adding classes on Wednesday
    manager.addClass("English III", 3, 8, 0, 10, 0, "A1"); 
    manager.addClass("Object Oriented Programming - Theory", 3, 10, 30, 14, 30, "PC LAB"); 
    manager.addClass("Introduction to Industrial Engineering", 3, 14, 30, 18, 0, "A1"); 

    // Adding classes on Thursday
    manager.addClass("Digital Logic Design - Practice", 4, 8, 0, 10, 0, "Electronics Lab"); 
    manager.addClass("Digital Logic Design - Theory", 4, 10, 30, 14, 30, "Electronics Lab"); 

    // Adding classes on Friday
    manager.addClass("English III", 5, 8, 0, 10, 0, "A1");      
    manager.addClass("Chinese III", 5, 10, 30, 12, 30, "A5");   
    manager.addClass("Object Oriented Programming - Practice", 5, 13, 30, 15, 30, "PC LAB"); 

    manager.findNextClass();  // Find and print information about the next or ongoing class

    return 0;  // Return 0 to indicate successful completion
}


//-------------MENU DE Q&A DE PROFESORES
//#include<iostream>
//using namespace std;
//int main()
//{
//	cout<<"Q&A HOURS"<<endl;
//	cout<<"TA Pablo Maldonado"<<endl<<"Monday and Wednesday: 8:30 to 12:30"<<endl;
//	cout<<endl;
//	cout<<"TA  Horacio Sosa"<<endl<<"Tuesday: 14:30 to 15:30"<<endl;
//	cout<<endl;
//	cout<<"TA  Maria Espinola"<<endl<<"Thursday: 14:30 to 15:30"<<endl;
//	cout<<endl;
//	cout<<"TA Cesar Clerx"<<endl<<"Monday and Wednesday 16:30 to 18:00"<<endl;
//	cout<<endl;
//	return 0;
//}


