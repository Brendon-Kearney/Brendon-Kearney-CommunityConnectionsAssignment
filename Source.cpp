#include "Students.h"
// By: Brendon Kearney
// client code

// add the showCourse() function here 
void ClassRoll::showCourse()const
{
    cout << "Course name: " << getCourseName() << endl;
    cout << "Number of students enrolled: " << getNoStudents() << endl;
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

    cout << "\n\ncalling your show course function:\n";
    //add the code to call your showCourse() function here for student.data 
    comp333.showCourse();

    cout << "\n\n\nEmpty object examples from default.data file" << endl << endl;
    ClassRoll noclass("default.data", "No Class");   //empty file 
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

    cout << "\n\ncalling your show course function:\n";
    //add the code to call your showCourse() function for bestclass 
    bestClass.showCourse();

    system("type sample.dat");


    system("pause");
}