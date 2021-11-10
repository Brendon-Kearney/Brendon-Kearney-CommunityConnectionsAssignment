#include "Students.h"
// By: Brendon Kearney
// Implementation file
//first addition
//seccond addition

ClassRoll::ClassRoll(string fileName, string nameOfCourse, int initialMaxStudents)
{
    courseName = nameOfCourse;

    if (initialMaxStudents < SIZE && initialMaxStudents > 0)
    {
        maxStudents = initialMaxStudents;
    }
    else
    {
        maxStudents = 25;
    }

    ifstream fin(fileName);
    if (!fin.is_open())
    {
        cout << "error opening "<< fileName <<" file " << endl;
        system("pause");
        exit(-1);
    }

    int length = 0;
    for (; length < maxStudents; length++)
    {
        getline(fin, students[length].studentName);

        if (fin.eof())
            break;

        fin >> students[length].assignmentTotal;
        fin >> students[length].testTotal;
        fin >> students[length].letterGrade;

        fin.ignore(80, '\n');
    }
    noStudents = length;


}

void ClassRoll::writeStudents(ostream& fout)const
{

    fout << left << setw(30) << "Student Name" << setw(20) << right << "Assignment Total" <<
        setw(20) << right << "Test Total" << setw(20) << "Grade" << endl << endl;

    for (int ctr = 0; ctr < noStudents; ctr++)
    {
        fout << left << setw(30) << students[ctr].studentName << right << setw(20) << students[ctr].assignmentTotal <<
            setw(20) << right << students[ctr].testTotal << setw(20) << students[ctr].letterGrade << endl;
    }

    fout << endl << "# of students = " << noStudents << endl;
}

int ClassRoll::searchStudent(string name)const
{
    int retrn = 0;
    for (int ctr = 0; ctr < noStudents; ctr++)
    {
        if (name == students[ctr].studentName) {
            retrn = ctr;
            break;
        }
        else
        {
            retrn = noStudents;
        }
    }
    return(retrn);
}

void ClassRoll::showGrade(string name)const
{
    int studentNum = searchStudent(name);
    if (studentNum != noStudents)
    {
        cout << name << " grade: " << students[studentNum].letterGrade << endl;
    }
    else
    {
        cout << "ERROR student not found" << endl;
    }
}

void ClassRoll::changeGrade(string name, char grade)
{
    int studentNum = searchStudent(name);
    if (toupper(grade) == 'A' || toupper(grade) == 'B' || toupper(grade) == 'C' || toupper(grade) == 'D' || toupper(grade) == 'F')
    {
        students[studentNum].letterGrade = toupper(grade);
    }
    else
    {
        cout << "ERROR grade was not changed!" << endl;
    }
}

