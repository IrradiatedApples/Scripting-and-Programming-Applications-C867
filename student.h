#ifndef STUDENT_H
#define STUDENT_H

//Student class holds all information for
//ONE student including:
//studentID
//First Name
//Last Name
//email Address
//age
//Number of Days to Complete 3 courses
//   -Stored in an array
//Degree Program

#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	
	int age;
	int numDaysToComplete[3];

	DegreeProgram degreeProgram;

public:
	//Constructors
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysToComplete[], DegreeProgram degreepProgram);
	Student(const Student& origStudent);

	//Destructor
	~Student();
	
	//Copy Assignment Operator
	Student& operator=(const Student& copyStudent);

	//Print Student Info
	void print();

	//Getters
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmailAddress() const;

	int GetAge() const;
	
	const int* GetNumDaysToComplete() const;

	DegreeProgram GetDegreeProgram() const;

	//Setters
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);

	void SetAge(int age);
	
	void SetNumDaysToComplete(int numDaysToComplete[]);

	void SetDegreeProgram(DegreeProgram degreeProgram);
};

#endif