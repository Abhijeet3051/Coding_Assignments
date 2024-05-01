#include <iostream>
#include<iomanip>
#include "UI.h"

using namespace std;

void UI::AddSeperator(int count) const {
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << "-";
	}
}

void UI::PrintHeadingElement(const char* title, int width) const {
	char seperator = ' ';
	cout << left << setw(width) << setfill(seperator) << title << "|";
}

void UI::PrintSeperator(int characters) const {
	cout << endl;
	for (int i = 0; i < characters; i++) {
		cout << "-";
	}
}

void UI::PrintStudent(Database database, int rollno) const {
	Student student = database.GetStudent(rollno);
	char seperator = ' ';
	string name = student.GetFirstName() + " " + student.GetLastName();
	cout << endl << "|"
		<< left << setw(ROLLNO_WIDTH) << setfill(seperator) << student.GetRollNo() << "|"
		<< left << setw(NAME_WIDTH) << setfill(seperator) << name << "|"
		<< left << setw(PHYSICS_WIDTH) << setfill(seperator) << student.GetMarks(physics) << "|"
		<< left << setw(CHEMISTRY_WIDTH) << setfill(seperator) << student.GetMarks(chemistry) << "|"
		<< left << setw(MATHS_WIDTH) << setfill(seperator) << student.GetMarks(maths) << "|"
		<< left << setw(BIOLOGY_WIDTH) << setfill(seperator) << student.GetMarks(biology) << "|"
		<< left << setw(ENGLISH_WIDTH) << setfill(seperator) << student.GetMarks(english) << "|"
		<< left << setw(PERCENTAGE_WIDTH) << setfill(seperator) << student.GetPercentage() << "|"
		<< left << setw(GRADE_WIDTH) << setfill(seperator) << student.GetGrade() << "|";
	AddSeperator(1 + ROLLNO_WIDTH + 1 + NAME_WIDTH + 1 + PHYSICS_WIDTH + 1 + CHEMISTRY_WIDTH + 1 + MATHS_WIDTH + 1 + BIOLOGY_WIDTH + 1 + ENGLISH_WIDTH + 1 + PERCENTAGE_WIDTH + 1 + GRADE_WIDTH);

}

void  UI::PrintTopColumn() const {
	cout << endl << "|";
	PrintHeadingElement("Roll No", ROLLNO_WIDTH);
	PrintHeadingElement("Name", NAME_WIDTH);
	PrintHeadingElement("Physics", PHYSICS_WIDTH);
	PrintHeadingElement("Chemistry", CHEMISTRY_WIDTH);
	PrintHeadingElement("Maths", MATHS_WIDTH);
	PrintHeadingElement("Biology", BIOLOGY_WIDTH);
	PrintHeadingElement("English", ENGLISH_WIDTH);
	PrintHeadingElement("%", PERCENTAGE_WIDTH);
	PrintHeadingElement("Grade", GRADE_WIDTH);
	AddSeperator(ROLLNO_WIDTH + 1 + NAME_WIDTH + 1 + PHYSICS_WIDTH + 1 + CHEMISTRY_WIDTH + 1 + MATHS_WIDTH + 1 + BIOLOGY_WIDTH + 1 + ENGLISH_WIDTH + 1 + PERCENTAGE_WIDTH + 1 + GRADE_WIDTH);
	AddSeperator(ROLLNO_WIDTH + 1 + NAME_WIDTH + 1 + PHYSICS_WIDTH + 1 + CHEMISTRY_WIDTH + 1 + MATHS_WIDTH + 1 + BIOLOGY_WIDTH + 1 + ENGLISH_WIDTH + 1 + PERCENTAGE_WIDTH + 1 + GRADE_WIDTH);
}

void UI::ShowData(Database database) const {
	PrintTopColumn();
	int count = database.StudentCount();
	for (int i = 1; i <= count; i++) {
		PrintStudent(database, i);
	}
	cout << endl;
}

void UI::AppendStudent(Database& database) const {
	string firstname, lastname;
	cout << "First Name: ";
	cin >> firstname;
	cout << "Last Name: ";
	cin >> lastname;
	database.AddStudent(&firstname[0], &lastname[0]);
}

Subject UI::returnSubject() const {
	int subjectCode;
	cout << endl << "1.Physics 2.Chemistry 3.Maths 4.Biology 5.English\n0 for exit\nEnter Subject code: ";
	cin >> subjectCode;

	bool loop = true;
	while (loop) {
		switch (subjectCode) {
		case 1:
			return physics;
			break;
		case 2:
			return chemistry;
			break;
		case 3:
			return maths;
			break;
		case 4:
			return biology;
			break;
		case 5:
			return english;
			break;
		case 0:
			cout << "Exiting......";
			loop = false;
			break;
		default:
			cout << "Exiting with invalid input. DO it again.....";
			break;
		}
	}
}

void UI::EnterAllMarksOfASubject(Database& database) const {
	Subject subject = returnSubject();
	database.EnterAllMarksOfASubject(subject);
}

void UI::UpdateMarks(Database& database) const {
	int rollno;
	float marks;
	Subject subject;

	cout << endl;
	cout << "Enter Roll No.: ";
	cin >> rollno;
	PrintTopColumn();
	PrintStudent(database, rollno);

	subject = returnSubject();

	cout << "Enter Marks: ";
	cin >> marks;
	database.UpdateMarksOfAStudent(rollno, subject, marks);
}

void UI::DeleteStudent(Database& database) const {
	int rollno;
	cout << endl << "Enter Roll no of student to delete: ";
	cin >> rollno;
	database.DeleteStudent(rollno);
}

void UI::InsertStudent(Database& database) const {
	int rollno;
	cout << endl << "Enter Roll no to insert a new student at: ";
	cin >> rollno;
	string firstname, lastname;
	cout << "First Name: ";
	cin >> firstname;
	cout << "Last Name: ";
	cin >> lastname;
	database.InsertStudent(rollno, &firstname[0], &lastname[0]);
}

void UI::UpdateAStudentName(Database& database) const {

	int rollno;
	cout << endl << "Enter Roll no to of a student to edit: ";
	cin >> rollno;
	string firstname, lastname;
	cout << "First Name: ";
	cin >> firstname;
	cout << "Last Name: ";
	cin >> lastname;
	database.UpdateName(rollno, &firstname[0], &lastname[0]);
}

void UI::ViewStudentData(Database& database) const {
	int rollno;
	cout << endl << "Enter Roll no of a student: ";
	cin >> rollno;
	PrintTopColumn();
	PrintStudent(database, rollno);
	cout << endl;
}

void UI::DisplayToppers(Database& database) const {
	vector <int> rollno = database.TopperRollNos();
	int count = rollno.size();
	PrintTopColumn();
	for (int i = 0; i < count; i++) {
		PrintStudent(database, rollno[i]);
	}
}

void UI::DisplaySubjectToppers(Database& database) const {
	Subject subject = returnSubject();
	vector <int> rollno = database.SubjectTopperRollNos(subject);
	int count = rollno.size();
	PrintTopColumn();
	for (int i = 0; i < count; i++) {
		PrintStudent(database, rollno[i]);
	}
}