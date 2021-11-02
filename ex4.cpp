#include "ClassRoll.h"
// Name: Joulyano Mzaber
// Purpose: Let the professirs maintaine the grades and information on each student enrolled
// Client File

// add the showCourse() function here
void showCourse(ClassRoll school)
{
	cout << "Course name: " << school.getCourseName()
		<< "  Students enrolled: " << school.getNoStudents() << endl;
}

int main()
{
	cout << "ClassRoll object examples for student.data file:" << endl << endl;
	ClassRoll comp333("student.data", "OOP C++", 3);
	cout << "Number of students in COMP 333 = " << comp333.getNoStudents() << endl;
	cout << "printing all students in student.data to the screenscreen:\n\n";
	comp333.writeStudents(cout);
	cout << "\nLooking up student T. Jones:\n";
	comp333.showGrade("T. Jones"); //should be in student.data, if not add it
	cout << "\nChange grade for T. Jones to a B\n\n";
	comp333.changeGrade("T. Jones", 'B');
	cout << "show T. Jones grade changed \n";
	comp333.showGrade("T. Jones");


	cout << "\nChange grade for T. Jones to a M\n\n";
	comp333.changeGrade("T. Jones", 'M');


	cout << "show non existant student\n";
	comp333.showGrade("Colin");
	cout << "printing all students in student.data again\n\n";
	comp333.writeStudents(cout);


	cout << "\n\ncalling your show course function:";
	//add the code to call your showCourse() function here for student.data
	showCourse(comp333);


	cout << "\n\n\nEmpty object examples from default.data file" << endl << endl;
	ClassRoll noclass("default.data", "No Class"); //empty file
	cout << "Number of students = " << noclass.getNoStudents() << endl << endl;


	cout << "\n\nbestClass object examples" << endl << endl;
	ClassRoll bestClass("fullclass.data", "poker");
	bestClass.writeStudents(cout);
	cout << "Number of students in " << bestClass.getCourseName()
		<< ": " << bestClass.getNoStudents() << endl << endl;
	bestClass.writeStudents(cout);
	bestClass.showGrade("Superman");
	cout << "write to a file \n";
	ofstream fout("sample.dat");
	if (!fout.is_open())
	{
		cout << "error opening saple.dat file " << endl;
		system("pause");
		exit(1);
	}
	bestClass.writeStudents(fout);
	cout << "\n\ncalling your show course function:";

	cout << "\n\ncalling your show course function:";
	//add the code to call your showCourse() function for bestclass
	showCourse(bestClass);

	system("type sample.dat");
	system("pause");
}


/*

ClassRoll object examples for student.data file:

Number of students in COMP 333 = 3
printing all students in student.data to the screenscreen:

Student Name      Assign Total     Total Test          Grade

J. Doe                      50            290              A
P. Smith                    45            190              D
T. Jones                    50            100              F

Number of Students: 3


Looking up student T. Jones:
T. Jones Grade is: F

Change grade for T. Jones to a B

grade successfully changed
show T. Jones grade changed
T. Jones Grade is: B

Change grade for T. Jones to a M

unable to change grade for the provided letter M
show non existant student
error: unable to find student printing all students in student.data again

Student Name      Assign Total     Total Test          Grade

J. Doe                      50            290              A
P. Smith                    45            190              D
T. Jones                    50            100              B

Number of Students: 3



calling your show course function:Course name: OOP C++  Students enrolled: 3



Empty object examples from default.data file

Number of students = 0



bestClass object examples

Student Name      Assign Total     Total Test          Grade


Number of Students: 0

Number of students in poker: 0

Student Name      Assign Total     Total Test          Grade


Number of Students: 0

error: unable to find student write to a file


calling your show course function:

calling your show course function:Course name: poker  Students enrolled: 0
Student Name      Assign Total     Total Test          Grade


Number of Students: 0

Press any key to continue . . .

*/