// more changed
// Changes were made here for COMP220

ClassRoll::ClassRoll(string fileName, string actualCourse, int maximum)
{
    // assigning the course name
    courseName = actualCourse;

    ifstream fin(fileName);
    // checks if the file is not open
    if (!fin.is_open())
    {
        cout << "error opening student.data file ";
        system("pause");
        exit(-1);
    }

    // reading the file
    int index = 0;
    for (; index < maximum; index++)
    {
        // reaing the file elements
        getline(fin, students[index].studentName);
        if (fin.eof())
        {
            break;
        }
        fin >> students[index].assignmentTotal;
        fin >> students[index].testTotal;
        fin >> students[index].letterGrade;

        fin.ignore(80, '\n');
    }

    fin.close();

    // declaring the actual number of students
    noStudents = index;
}

// outputting the file / info
void ClassRoll::writeStudents(ostream& fileName) const
{
    fileName << left << setw(15) << "Student Name";
    fileName << right << setw(15) << "Assign Total";
    fileName << right << setw(15) << "Total Test";
    fileName << right << setw(15) << "Grade" << endl << endl;

    for (int ctr = 0; ctr < noStudents; ctr++)
    {
        if (fileName.eof())
        {
            break;
        }

        fileName << left << setw(15) << students[ctr].studentName;
        fileName << right << setw(15) << students[ctr].assignmentTotal;
        fileName << right << setw(15) << students[ctr].testTotal;
        fileName << right << setw(15) << students[ctr].letterGrade << endl;
    }

    // total number of enrolled students
    fileName << endl;
    fileName << "Number of Students: " << noStudents;
    fileName << endl << endl;
}

// search through the file based on the name string, returning the name position
int ClassRoll::searchStudent(string chosenName) const
{
    int index = 0;
    int result = 0;
    bool truefalse = true;
    for (; index < SIZE; index++)
    {
        if (students[index].studentName == chosenName)
        {
            truefalse = false;
            result = index;
        }
    }

    if (truefalse == true)
    {
        index = noStudents;
    }
    else
    {
        index = result;
    }

    return (index);
}

// search for the grade and display it
void ClassRoll::showGrade(string gradedStudent) const
{
    int index = searchStudent(gradedStudent);
    if (!(index == noStudents))
    {
        cout << gradedStudent << " Grade is: " << students[index].letterGrade << endl;
    }
    else
    {
        cout << "error: unable to find student ";
    }
}

// allow devs to change the grade
void ClassRoll::changeGrade(string realName, char changingGrade)
{
    changingGrade = toupper(changingGrade);
    bool searching;
    int index = searchStudent(realName);
    if (!(index == noStudents))
    {
        searching = false;
    }
    else
    {
        cout << "error: unable to find student ";
    }

    // validating the chosen grade
    switch (changingGrade)
    {
    case 'A':
        searching = true;
        break;
    case 'B':
        searching = true;
        break;
    case 'C':
        searching = true;
        break;
    case 'D':
        searching = true;
        break;
    case 'F':
        searching = true;
        break;

        // if wrong letter was provided
    default:
        searching = false;
        cout << "unable to change grade for the provided letter " << changingGrade << endl;
        break;
    }

    // reassigning grade
    if (searching == true)
    {
        cout << "grade successfully changed " << endl;
        students[index].letterGrade = changingGrade;
    }
}