#include "ScheduleProfessor.h" // Include header file for ScheduleProfessor
#include "professorClass.h" // Include header file for professorClass
#include <ctime> // Include header file for time-related functions
#include <iostream> // Include header file for input-output stream
#include <iomanip> // Include header file for input-output manipulators like setw and setfill
#include <sstream> // Include header file for string stream
#include <algorithm> // Include header file for algorithms like transform

using namespace std; // Use the standard namespace

// Constructor for ClassSchedule
ClassScheduleP::ClassScheduleP(string subj, int day, int sh, int sm, int eh, int em, string room)
{
	subject = subj; // Initialize subject
	dayOfWeek = day; // Initialize day of the week
	startHour = sh; // Initialize start hour
	startMinute = sm; // Initialize start minute
	endHour = eh; // Initialize end hour
	endMinute = em; // Initialize end minute
	classroom = room; // Initialize classroom
}

// Constructor for Schedule
ScheduleP::ScheduleP() {}

// Function to add a class to the schedule
void ScheduleP::addClass(const string& subject, int dayOfWeek, int startHour, int startMinute, int endHour, int endMinute, const string& classroom)
{
	// Create a new ClassSchedule object and add it to the vector
	scheduleP.push_back(ClassScheduleP(subject, dayOfWeek, startHour, startMinute, endHour, endMinute, classroom));
}

// Function to load professor-specific classes into the schedule
void ScheduleP::loadProfessorClasses()
{
	// Adding classes on Monday
	addClass("Engineering Materials", 1, 8, 0, 10, 0, "A2");
	addClass("Introduction to Industrial Engineering - Practice", 1, 10, 30, 12, 30, "A2");
	addClass("Data Structures - Practice", 1, 13, 30, 15, 30, "PC LAB");
	addClass("Chinese III", 1, 16, 0, 18, 0, "A2");

	// Adding classes on Tuesday
	addClass("Engineering Materials", 2, 8, 0, 10, 0, "A3");
	addClass("Digital Logic Design - Practice", 2, 10, 30, 12, 30, "Electronics Lab");
	addClass("Data Structures - Theory", 2, 13, 30, 17, 00, "A3");


	// Adding classes on Wednesday
	addClass("English III", 3, 8, 0, 10, 0, "A1");
	addClass("Object Oriented Programming - Theory", 3, 10, 30, 14, 30, "PC LAB");
    addClass("Introduction to Industrial Engineering - Theory", 3, 14, 30, 18, 0, "A1");

	// Adding classes on Thursday
	addClass("Digital Logic Design - Practice", 4, 8, 0, 10, 0, "Electronics Lab");
	addClass("Digital Logic Design - Theory", 4, 10, 30, 14, 30, "Electronics Lab");

	// Adding classes on Friday
	addClass("English III", 5, 8, 0, 10, 0, "A1");
	addClass("Chinese III", 5, 10, 30, 12, 30, "A5");
	addClass("Object Oriented Programming - Practice", 5, 13, 30, 21, 30, "PC LAB");

}

// Function to convert a string to lowercase
string toLowerCase(const string& str)
{
	string lowerStr = str; // Copy the input string
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower); // Convert each character to lowercase
	return lowerStr; // Return the lowercase string
}

// Function to find and display the next or ongoing class based on the professor's name
System::UnicodeString ScheduleP::findNextClass(const string& professorName)
{
	// Map of professor names to the subjects they teach
    map<string, vector<string>> professorClasses =
    {
        {"zkey", {"Object Oriented Programming - Practice", "Object Oriented Programming - Theory", "Data Structures - Theory", "Data Structures - Practice"}},
        {"barbara", {"Introduction to Industrial Engineering - Practice", "Introduction to Industrial Engineering - Theory"}},
        {"ruan", {"Digital Logic Design - Practice", "Digital Logic Design - Theory"}},
        {"lincy", {"Engineering Materials"}},
        {"liliana", {"English III"}},
		{"lin", {"Chinese III"}}
    };

    // Convert the professorName to lowercase
    string lowerProfessorName = toLowerCase(professorName);
    // Get the subjects taught by the professor
    vector<string> subjects = professorClasses[lowerProfessorName];

	// Get the current day, hour, and minute
    time_t t = time(0); // Get current time
    tm* now = localtime(&t); // Convert to local time
    int currentDay = now->tm_wday; // Get current day of the week
    int currentHour = now->tm_hour; // Get current hour
    int currentMinute = now->tm_min; // Get current minute
    int currentTimeInMinutes = currentHour * 60 + currentMinute; // Calculate current time in minutes
    bool found = false; // Flag to indicate if a class is found

    // Iterate through the schedule to find the class
    for (const auto& classScheduleP : scheduleP)
    {
        for (const auto& subject : subjects)
        {
            if (classScheduleP.subject == subject && classScheduleP.dayOfWeek == currentDay)
            {
				int classStartTimeInMinutes = classScheduleP.startHour * 60 + classScheduleP.startMinute; // Calculate class start time in minutes
                int classEndTimeInMinutes = classScheduleP.endHour * 60 + classScheduleP.endMinute; // Calculate class end time in minutes
                int timeDifference = classStartTimeInMinutes - currentTimeInMinutes; // Calculate time difference in minutes

                // Create streams to format the time
                ostringstream startHourStream, startMinuteStream, endHourStream, endMinuteStream;
                startHourStream << std::setw(2) << std::setfill('0') << classScheduleP.startHour;
                startMinuteStream << std::setw(2) << std::setfill('0') << classScheduleP.startMinute;
				endHourStream << std::setw(2) << std::setfill('0') << classScheduleP.endHour;
                endMinuteStream << std::setw(2) << std::setfill('0') << classScheduleP.endMinute;

                // Check if the class is ongoing
                if (currentTimeInMinutes >= classStartTimeInMinutes && currentTimeInMinutes < classEndTimeInMinutes)
                {
					// Return the ongoing class details
                    return "Your " + System::UnicodeString(classScheduleP.subject.c_str()) +
						   " class is currently ongoing \n\n Hour: " +
						   System::UnicodeString(startHourStream.str().c_str()) + ":" +
						   System::UnicodeString(startMinuteStream.str().c_str()) + " to " +
                           System::UnicodeString(endHourStream.str().c_str()) + ":" +
						   System::UnicodeString(endMinuteStream.str().c_str()) + "\n\n Classroom: " +
                           System::UnicodeString(classScheduleP.classroom.c_str());
				}
                else if (currentTimeInMinutes < classStartTimeInMinutes)
				{
					// If the time difference is more than 60 minutes, print the message in hours and minutes
                    if (timeDifference > 60)
                    {
                        int hours = timeDifference / 60; // Calculate hours
                        int minutes = timeDifference % 60; // Calculate remaining minutes
                        // Return the class details with hours and minutes
                        return "Your " + System::UnicodeString(classScheduleP.subject.c_str()) +
							   " class starts in " + System::UnicodeString(std::to_string(hours).c_str()) +
                               " hours and " + System::UnicodeString(std::to_string(minutes).c_str()) +
							   " minutes \n\n" + System::UnicodeString(startHourStream.str().c_str()) + "Hour: " +
                               System::UnicodeString(startMinuteStream.str().c_str()) + " to " +
                               System::UnicodeString(endHourStream.str().c_str()) + ":" +
							   System::UnicodeString(endMinuteStream.str().c_str()) + " \n\n" + "Classroom: "+
                               System::UnicodeString(classScheduleP.classroom.c_str());
                    }
					else
					{
						// Return the class details with minutes
						return "Your " + System::UnicodeString(classScheduleP.subject.c_str()) +
							   " class starts in " + System::UnicodeString(std::to_string(timeDifference).c_str()) +
							   " minutes \n\n" + System::UnicodeString(startHourStream.str().c_str()) + ":" +
							   System::UnicodeString(startMinuteStream.str().c_str()) + " to " +
							   System::UnicodeString(endHourStream.str().c_str()) + ":" +
							   System::UnicodeString(endMinuteStream.str().c_str()) + " \n\n" +
							   System::UnicodeString(classScheduleP.classroom.c_str());
					}
				}
			}
		}
	}

	// Return message if no upcoming or ongoing classes are found
	return "No upcoming or ongoing classes today :)";
}

