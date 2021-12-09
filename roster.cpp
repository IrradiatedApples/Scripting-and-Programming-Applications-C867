#include "roster.h"

//Default Constructor
Roster::Roster() {
	for (int i = 0; i < 5; ++i) {
		classRosterArray[i] = nullptr;
	}

	return;
}

//Constructor that parses and added studentData
Roster::Roster(const string studentData[], int numStudents) {
	for (int i = 0; i < 5; ++i) {
		classRosterArray[i] = nullptr;
	}

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	DegreeProgram degreeProgram;

	for (int i = 0; i < numStudents; ++i) {
		stringstream s_OneStudentData(studentData[i]);
		string oneStudentData[9] = { "X" };

		for (int i = 0; i < 9; ++i) {
			string data;
			getline(s_OneStudentData, data, ',');
			oneStudentData[i] = data;
		}

		studentID = oneStudentData[0];
		firstName = oneStudentData[1];
		lastName = oneStudentData[2];
		emailAddress = oneStudentData[3];

		//Convert string numers to ints
		age = stoi(oneStudentData[4]);
		daysInCourse1 = stoi(oneStudentData[5]);
		daysInCourse2 = stoi(oneStudentData[6]);
		daysInCourse3 = stoi(oneStudentData[7]);

		if (oneStudentData[8] == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}
		else if (oneStudentData[8] == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
		}
		else {
			degreeProgram = DegreeProgram::SOFTWARE;
		}

		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	}

	return;
}

//Copy Constructor
Roster::Roster(const Roster& origRoster) {
	this->classRosterArray[0] = origRoster.classRosterArray[0];
	this->classRosterArray[1] = origRoster.classRosterArray[1];
	this->classRosterArray[2] = origRoster.classRosterArray[2];
	this->classRosterArray[3] = origRoster.classRosterArray[3];
	this->classRosterArray[4] = origRoster.classRosterArray[4];

	return;
}

//Destructor
Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}

	return;
}

//Copy Assignment Operator
Roster& Roster::operator=(const Roster& copyRoster) {
	if (this != &copyRoster) {
		this->classRosterArray[0] = copyRoster.classRosterArray[0];
		this->classRosterArray[1] = copyRoster.classRosterArray[1];
		this->classRosterArray[2] = copyRoster.classRosterArray[2];
		this->classRosterArray[3] = copyRoster.classRosterArray[3];
		this->classRosterArray[4] = copyRoster.classRosterArray[4];
	}

	return *this;
}

//Getter, studentID
string Roster::getStudentID(int listNum) const{
	return classRosterArray[listNum]->GetStudentID();
}

//add new student to classRoster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int numDaysToComplete[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student student(studentID, firstName, lastName, emailAddress, age, numDaysToComplete, degreeProgram);
	Student* newStudent = new Student;
	*newStudent = student;

	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = newStudent;
			return;
		}
	}

	cout << "ERROR: Class Roster is Full" << endl;

	return;
}

//remove student with given studentID from class roster
void Roster::remove(string studentID) {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			return;
		}
	}

	cout << "The student with ID: " << studentID << " was not found." << endl;

	return;
}

//print all student info
void Roster::printAll() {
	cout << "Displaying all students:" << endl;
	for (int i = 0; i < 5 && classRosterArray != nullptr; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;

	return;
}

//print average days to complete a course for student
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			const int* daysPtr;
			int averageDays;

			daysPtr = classRosterArray[i]->GetNumDaysToComplete();
			averageDays = (daysPtr[0] + daysPtr[1] + daysPtr[2]) / 3;

			cout << "Student ID: " << studentID << ", averages ";
			cout << averageDays;
			cout << " in a course." << endl;
			return;
		}
	}

	cout << "ERROR: Student Not Found" << endl;

	return;
}

//print all invalid emails and errors
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			string emailAddress = classRosterArray[i]->GetEmailAddress();
			int atCount = count(emailAddress.begin(), emailAddress.end(), '@');
			if (atCount != 1) {
				cout << emailAddress;
				cout << " - missing an @ symbol" << endl;
				continue;
			}

			int periodCount = count(emailAddress.begin(), emailAddress.end(), '.');
			if (periodCount < 1) {
				cout << emailAddress;
				cout << " - missing a period" << endl;
				continue;
			}

			int spaceCount = count(emailAddress.begin(), emailAddress.end(), ' ');
			if (spaceCount != 0) {
				cout << emailAddress;
				cout << " - no spaces allowed" << endl;
				continue;
			}
		}
	}
	cout << endl;

	return;
}

//print all students in given Degree Program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Showing students in degree program: ";

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

	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
				classRosterArray[i]->print();
			}
		}
	}

	cout << endl;

	return;
}