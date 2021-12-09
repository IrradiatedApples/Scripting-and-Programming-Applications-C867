#include "roster.h"

int main()
{
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Arthur,Amende,aamende@wgu.edu,34,15,20,25,SOFTWARE" };

	//Student Data for Arthur Amende (me)
	string studentID = "A5";
	string firstName = "Arthur";
	string lastName = "Amende";
	string emailAddress = "aamende@wgu.edu";
	int age = 34;
	int daysInCourse1 = 15;
	int daysInCourse2 = 20;
	int daysInCourse3 = 25;
	DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;

	//Print class information
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #002180137" << endl;
	cout << "Arthur J. Amende" << endl << endl;

	//Roster constructor can parse all of studentData
	//The final student, Arthur Amende (me), is added
	//sperate to demonstarte the add fuction in main.
	Roster classRoster(studentData, 4);
	classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	
	//Print all studnet info
	classRoster.printAll();

	//Find and print invalid emails along with why 
	//they are invalid.
	classRoster.printInvalidEmails();

	//Print the average days in course for each student.
	for (int i = 0; i < 5; ++i) {
		string studentID = classRoster.getStudentID(i);
		classRoster.printAverageDaysInCourse(studentID);
	}
	cout << endl;

	//Print all studnets in DegreeProgram Software.
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	//Remove student A3 from classRoster and print
	//all students. Note student A3 has been removed.
	cout << "Removing A3:" << endl;
	classRoster.remove("A3");
	classRoster.printAll();

	//Attempt to remove student A3 again producing
	//an error.
	cout << "Removing A3 again:" << endl;
	classRoster.remove("A3");

	return 0;
}