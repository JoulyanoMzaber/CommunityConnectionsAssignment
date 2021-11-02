#include <iostream>
#include <fstream>
#include <string>                   /* preprocessors */
#include <iomanip>
using namespace std;
const int SIZE = 25;
// Name: Joulyano Mzaber
// Specification File

// Structure
struct StudentRec
{
    string studentName;
    int assignmentTotal;
    int testTotal;
    char letterGrade;
};

// Class
class ClassRoll
{
public:
    void showGrade(string /*studentName*/) const; // displays the student's grade
    int getNoStudents() const { return noStudents; } // returns the total number of students
    string getCourseName() const { return courseName; }// returns name of the course
    void changeGrade(string /*studentName*/, char /*letterGrade*/); // allows the user to change the student's grade
    void writeStudents(ostream&) const; // write all students in the array to an output file
    ClassRoll(string /*fileName*/, string /*courseName*/, int = SIZE /*maxStudents*/);

private:
    string courseName;
    int maxStudents; // maximum number of students
    int noStudents; // the actualy number of students
    StudentRec students[SIZE];
    int searchStudent(string /*studentName*/) const; // returns the number of the student in the array
};