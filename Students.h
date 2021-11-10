#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;



const int SIZE = 25;

struct StudentRec
{
	string studentName;
	int assignmentTotal;
	int testTotal;
	char letterGrade;
};

class ClassRoll
{
public:
	void showCourse()const; // shows course name and number of students
	void showGrade(string /*name*/) const; // uses students name to find grade
	int getNoStudents() const { return noStudents; }  // gets number of students
	string getCourseName() const { return courseName; } //gets name of course
	void changeGrade(string /*name*/, char /*letterGrade*/); //changes students grade
	void writeStudents(ostream& /*output*/) const; //writes all of the students in the array
	ClassRoll(string /*name of file*/, string /*course name*/, int = 25/*number of students*/);

private:
	string courseName;
	int maxStudents;
	int noStudents;
	StudentRec students[SIZE];
	int searchStudent(string /*name*/) const;
};