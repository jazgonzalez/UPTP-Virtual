#ifndef SCHEDULEMANAGER_H
#define SCHEDULEMANAGER_H

#include <string>
using namespace std;

// Forward declaration of T_classesSubmenu
class T_classesSubmenu;

//class "ClassSchedule" representing individual class details
class ClassSchedule
{
public:
	string subject;
	int dayOfWeek;
	int startHour;
	int startMinute;
	int endHour;
	int endMinute;
	string classroom;

	ClassSchedule(); // Default constructor
	ClassSchedule(string, int, int, int, int, int, string); // Parameterized constructor
};

//class "Schedule" manages an array of "ClassSchedule objects", which represent the complete schedule of the week
class Schedule
{
public:
	Schedule(int maxCap); //constructor to initialize the Schedule with a max number of classes that can be added
	~Schedule(); // destructor to manage memory by deleting the dynamically allocated array
	void addClass(const string& subject, int dayOfWeek, int startHour, int startMinute, int endHour, int endMinute, const string& classroom);  // method to add new classes to the schedule
	void findNextClass(T_classesSubmenu* submenu); // method to identify and display the next or ongoing class based on the current time

private:
	int count;
	const int maxCapacity;
	ClassSchedule* schedule;
	//methods to get the current day, hour, and minute from the computer hour
	int getCurrentDayOfWeek();
	int getCurrentHour();
	int getCurrentMinute();
};

#endif // SCHEDULEMANAGER_H




