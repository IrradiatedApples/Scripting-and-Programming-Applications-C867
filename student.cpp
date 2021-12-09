#include "student.h"

//Default Constructor
Student::Student() {
	this->studentID = "INITIALIZE";
	this->firstName = "INITIALIZE";
	this->lastName = "INITIALIZE";
	this->emailAddress = "INITIALIZE";

	this->age = -1;

	this->numDaysToComplete[0] = -1;
	this->numDaysToComplete[1] = -1;
	this->numDaysToComplete[2] = -1;

	this->degreeProgram = DegreeProgram::SOFTWARE;

	return;
}

//Constructor using all of a students info
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysToComplete[], DegreeProgram degreeProgram) {
	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmailAddress(emailAddress);

	SetAge(age);
	SetNumDaysToComplete(numDaysToComplete);

	SetDegreeProgram(degreeProgram);

	return;
}

//Copy Constructor
Student::Student(const Student& origStudent) {
	this->studentID = origStudent.studentID;
	this->firstName = origStudent.firstName;
	this->lastName = origStudent.lastName;
	this->emailAddress = origStudent.emailAddress;

	this->age = origStudent.age;
	this->numDaysToComplete[0] = origStudent.numDaysToComplete[0];
	this->numDaysToComplete[1] = origStudent.numDaysToComplete[1];
	this->numDaysToComplete[2] = origStudent.numDaysToComplete[2];

	this->degreeProgram = origStudent.degreeProgram;

	return;
}

//Destructor
//Not needed but included for completeness and Rule of Three
Student::~Student() {
	//cout << "Removing Student " << studentID << ", " << firstName << " " << lastName << endl;
}

//Copy Assignment Operator
Student& Student::operator=(const Student& copyStudent) {
	if (this != &copyStudent) {
		this->studentID = copyStudent.studentID;
		this->firstName = copyStudent.firstName;
		this->lastName = copyStudent.lastName;
		this->emailAddress = copyStudent.emailAddress;

		this->age = copyStudent.age;

		this->numDaysToComplete[0] = copyStudent.numDaysToComplete[0];
		this->numDaysToComplete[1] = copyStudent.numDaysToComplete[1];
		this->numDaysToComplete[2] = copyStudent.numDaysToComplete[2];

		this->degreeProgram = copyStudent.degreeProgram;
	}

	return *this;
}

//Print all of student info, tab delaminated
void Student::print() {
	cout << studentID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Email Address: " << emailAddress << "\t";
	cout << "Age: " << age << "\t";

	cout << "Days To Complete: { ";
	cout << numDaysToComplete[0] << ", ";
	cout << numDaysToComplete[1] << ", ";
	cout << numDaysToComplete[2] << " }\t";

	cout << "Degree Program: ";

	switch (degreeProgram)
	{
	case DegreeProgram::SECURITY:
		cout << "SECURITY";
		break;
	
	case DegreeProgram::NETWORK:
		cout << "NETWORK";
		break;
	
	case DegreeProgram::SOFTWARE:
		cout << "SOFTWARE";
		break;
	
	default:
		cout << "ART DEGREE";
		break;
	}

	cout << endl;

	return;
}

//Getters
string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

const int* Student::GetNumDaysToComplete() const{
	return &numDaysToComplete[0];
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
}


//Setters
void Student::SetStudentID(string studentID) {
	this->studentID = studentID;

	return;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;

	return;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;

	return;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;

	return;
}

void Student::SetAge(int age) {
	this->age = age;

	return;
}

void Student::SetNumDaysToComplete(int numDaysToComplete[]){
	this->numDaysToComplete[0] = numDaysToComplete[0];
	this->numDaysToComplete[1] = numDaysToComplete[1];
	this->numDaysToComplete[2] = numDaysToComplete[2];

	return;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;

	return;
}