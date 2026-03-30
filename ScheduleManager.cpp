#include "ScheduleManager.h" // Include the header file for the ScheduleManager class
#include <ctime> // Include the ctime library for getting the current time
#include <iostream> // Include the iostream library for input/output operations
#include <iomanip> // Include the iomanip library for setting output formatting
#include <sstream> // Include the sstream library for string stream operations
#include "classesSubmenu.h" // Include the header file for classesSubmenu class

// Default constructor for ClassSchedule --> Represents individual class details
ClassSchedule::ClassSchedule() {}

// Constructor to initialize all properties of ClassSchedule
ClassSchedule::ClassSchedule(string subj, int day, int sh, int sm, int eh, int em, string room)
{
	subject = subj;
	dayOfWeek = day;
	startHour = sh;
	startMinute = sm;
	endHour = eh;
	endMinute = em;
	classroom = room;
}

// Constructor for Schedule (Manages a collection of ClassSchedule objects)
Schedule::Schedule(int maxCap) : maxCapacity(maxCap), count(0)   // initializes the schedule with a specified maximum capacity and sets the count to zero
{
	schedule = new ClassSchedule[maxCapacity]; // Initialize the dynamic array with the maximum capacity
}

// Destructor for Schedule to free allocated memory
Schedule::~Schedule()
{
	delete[] schedule; // Delete the dynamic array
}

// Function to add a class to the schedule
void Schedule::addClass(const string& subject, int dayOfWeek, int startHour, int startMinute, int endHour, int endMinute, const string& classroom) {
	if (count == maxCapacity)    //checking if the schedule has reached its maximum capacity
	{
		// If the array has reached its maximum capacity, do not add more classes
		cout << "Schedule is full. Cannot add more classes." << endl;
		return;  //goes out of the function
	}
	schedule[count++] = ClassSchedule(subject, dayOfWeek, startHour, startMinute, endHour, endMinute, classroom); // Add the new class and increment the count
}

// Function to get the current day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
int Schedule::getCurrentDayOfWeek()
{
	time_t t = time(0); 	   // Get the current time
	tm* now = localtime(&t); // Convert to local time
	return now->tm_wday; // Return the day of the week
}

// Function to get the current hour
int Schedule::getCurrentHour()
{
	time_t t = time(0); // Get the current time
	tm* now = localtime(&t); // Convert to local time
	return now->tm_hour; // Return the current hour
}

// Function to get the current minute
int Schedule::getCurrentMinute()
{
	time_t t = time(0); // Get the current time
	tm* now = localtime(&t); // Convert to local time
	return now->tm_min; // Return the current minute
}


// Function to find and display the next or ongoing class based on the current time
void Schedule::findNextClass(T_classesSubmenu* submenu)
{
	int currentDay = getCurrentDayOfWeek(); // Get the current day of the week
	int currentHour = getCurrentHour(); // Get the current hour
	int currentMinute = getCurrentMinute(); // Get the current minute
	int currentTimeInMinutes = currentHour * 60 + currentMinute; // Calculate the current time in minutes
	bool found = false; // Flag to indicate if a class is found

	for (int i = 0; i < count; ++i)   // Iterate through each class schedule in the array
	{
		const auto& classSchedule = schedule[i];  // Get the current class schedule from the array

		if (classSchedule.dayOfWeek == currentDay) // Check if the class is on the current day
		{
			int classStartTimeInMinutes = classSchedule.startHour * 60 + classSchedule.startMinute; // Calculate the start time of the class in minutes
			int classEndTimeInMinutes = classSchedule.endHour * 60 + classSchedule.endMinute; // Calculate the end time of the class in minutes
			int timeDifference = classStartTimeInMinutes - currentTimeInMinutes; //  calculates the difference in minutes between the current time and the start time of the class

			if (currentTimeInMinutes >= classStartTimeInMinutes && currentTimeInMinutes < classEndTimeInMinutes)
			{
				// If the class is ongoing right now --> startTime of the class <currentTime < endTime of the class
				ostringstream formattedTime;
				formattedTime << "Your " << classSchedule.subject << " class is currently ongoing \n\n"
							  <<"Hour: "<< setw(2) << setfill('0') << classSchedule.startHour << ":" //setw(2) << setfill('0'): Set the width to 2 and fill with '0' if the number is less than 2 digits
							  << setw(2) << setfill('0') << classSchedule.startMinute << " to "
							  << setw(2) << setfill('0') << classSchedule.endHour << ":"
							  << setw(2) << setfill('0') << classSchedule.endMinute << " \n\n"
							  <<"Classroom: "<< classSchedule.classroom;
				submenu->classesLabel->Text = formattedTime.str().c_str(); //  Convert the formatted string to a C-style string   and
																			//Set the text of the classesLabel in the submenu to the formatted message
				found = true;
				break;   //exits the loop
			}
			else if (currentTimeInMinutes < classStartTimeInMinutes) // if the class starts on the current day, format the message to show in hours
			{
				ostringstream formattedTime;
				if (timeDifference > 60)   // If the class starts in more than an hour
				{
					int hours = timeDifference / 60;  // Calculate the number of hours until the class starts
					int minutes = timeDifference % 60;  // Calculate the remaining minutes after accounting for hours
					formattedTime << "Your " << classSchedule.subject << " class starts in "
								  << hours << " hour" << (hours > 1 ? "s " : " ") << minutes << " minute \n\n" << (minutes != 1 ? "s " : " ") //(minutes != 1 ? "s " : " ")
																													//to determine whether the word "hour" should be pluralized to "hours"
								  <<"Hour: "<< setw(2) << setfill('0') << classSchedule.startHour << ":"
								  << setw(2) << setfill('0') << classSchedule.startMinute << " to "
								  << setw(2) << setfill('0') << classSchedule.endHour << ":"
								  << setw(2) << setfill('0') << classSchedule.endMinute << " \n\n"
								  <<"Classroom: "<< classSchedule.classroom;
				}
				else    //if the class starts in less than an hour --> it shows the hour in minutes
				{
					formattedTime << "Your " << classSchedule.subject << " class starts in "
								  << timeDifference << " minutes \n\n"
								  <<"Hour: "<< setw(2) << setfill('0') << classSchedule.startHour << ":"
								  << setw(2) << setfill('0') << classSchedule.startMinute << " to "
								  << setw(2) << setfill('0') << classSchedule.endHour << ":"
								  << setw(2) << setfill('0') << classSchedule.endMinute << " \n\n"
								  <<"Classroom: "<< classSchedule.classroom;
				}
				submenu->classesLabel->Text = formattedTime.str().c_str(); // Display the message for upcoming class
				found = true;
				break;
			}
		}
	}

	if (!found)  //if the class is not found
	{
		submenu->classesLabel->Text = "No upcoming or ongoing classes today :)"; // Display message if no class is found
	}
}



