/*
#ifndef ScheduleProfessor_H
#define ScheduleProfessor_H

#include <vector>
#include <string>
#include <map>

class ClassScheduleP {
public:
	std::string subject;
    int dayOfWeek;
    int startHour;
    int startMinute;
    int endHour;
	int endMinute;
	std::string classroom;

    // Constructor for ClassSchedule
	ClassScheduleP(std::string subj, int day, int sh, int sm, int eh, int em, std::string room);
};

class ScheduleP {
private:
	std::vector<ClassScheduleP> scheduleP;

public:
	// Constructor for Schedule
	ScheduleP();

	// Function to add a class to the schedule
	void addClass(const std::string& subject, int dayOfWeek, int startHour, int startMinute, int endHour, int endMinute, const std::string& classroom);

	// Function to load professor-specific classes into the schedule
	void loadProfessorClasses();

	// Function to find and display the next or ongoing class based on the professor's name
	System::UnicodeString findNextClass(const std::string& professorName);
};

#endif
*/

#ifndef ScheduleProfessor_H
#define ScheduleProfessor_H

#include <vector>
#include <string>
#include <map>
using namespace std;

class ClassScheduleP
{
public:
	string subject;
	int dayOfWeek;
	int startHour;
	int startMinute;
	int endHour;
	int endMinute;
	string classroom;

	// Constructor for ClassSchedule
	ClassScheduleP(string , int , int , int, int , int ,string );
};

class ScheduleP
{
private:
	vector<ClassScheduleP> scheduleP;

public:
	// Constructor for Schedule
	ScheduleP();

	// Function to add a class to the schedule
	void addClass(const string&, int , int , int , int, int , const string&);

	// Function to load professor-specific classes into the schedule
	void loadProfessorClasses();

	// Function to find and display the next or ongoing class based on the professor's name
	System::UnicodeString findNextClass(const string& );
};

#endif

