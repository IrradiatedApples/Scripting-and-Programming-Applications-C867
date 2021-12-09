#ifndef ROSTER_H
#define ROSTER_H

//Roster contains a pointer to all Students
//and allows students to be added, removed,
//and print all student info.

#include <sstream>
#include "student.h"

class Roster {
private:
	Student* classRosterArray[5];

public:
	//Constructors
	Roster();
	Roster(const string studentData[], int numStudents);
	Roster(const Roster& origRoster);

	//Destructor
	~Roster();

	//Copy Assignment Operator
	Roster& operator=(const Roster& origRoster);

	//Getters
	string getStudentID(int listNum) const;

	//Functions
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif