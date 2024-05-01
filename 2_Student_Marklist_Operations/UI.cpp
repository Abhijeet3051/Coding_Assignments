#include <iostream>
#include<iomanip>
#include "UI.h"

void UI::AddSeperator(int count) {
	std::cout << std::endl;
	for (int i = 0; i < count; i++) {
		std::cout << "-";
	}
}

void UI::PrintHeadingElement(const char* title, int width) {
	char seperator = ' ';
	std::cout << std::left << std::setw(width) << std::setfill(seperator) << title << "|";
}

void UI::PrintSeperator(int characters) {
	std::cout << std::endl;
	for (int i = 0; i < characters; i++) {
		std::cout << "-";
	}
}

void UI::PrintStudent(Database database, int rollno) {
	Student_Data student = database.GetStudent(rollno);
	char seperator = ' ';
	std::string name = student.GetFirstName() + " " + student.GetLastName();
	std::cout << std::endl << "|"
		<< std::left << std::setw(ROLLNO_WIDTH) << std::setfill(seperator) << student.GetRollNo() << "|"
		<< std::left << std::setw(NAME_WIDTH) << std::setfill(seperator) << name << "|"
		<< std::left << std::setw(PHYSICS_WIDTH) << std::setfill(seperator) << student.GetMarks(physics) << "|"
		<< std::left << std::setw(CHEMISTRY_WIDTH) << std::setfill(seperator) << student.GetMarks(chemistry) << "|"
		<< std::left << std::setw(MATHS_WIDTH) << std::setfill(seperator) << student.GetMarks(maths) << "|"
		<< std::left << std::setw(BIOLOGY_WIDTH) << std::setfill(seperator) << student.GetMarks(biology) << "|"
		<< std::left << std::setw(ENGLISH_WIDTH) << std::setfill(seperator) << student.GetMarks(english) << "|"
		<< std::left << std::setw(PERCENTAGE_WIDTH) << std::setfill(seperator) << student.GetPercentage() << "|"
		<< std::left << std::setw(GRADE_WIDTH) << std::setfill(seperator) << student.GetGrade() << "|";
	AddSeperator(1 + ROLLNO_WIDTH + 1 + NAME_WIDTH + 1 + PHYSICS_WIDTH + 1 + CHEMISTRY_WIDTH + 1 + MATHS_WIDTH + 1 + BIOLOGY_WIDTH + 1 + ENGLISH_WIDTH + 1 + PERCENTAGE_WIDTH + 1 + GRADE_WIDTH);

}

void  UI::PrintTopColumn() {
	std::cout << std::endl << "|";
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

void UI::ShowData(Database database) {
	PrintTopColumn();
	int count = database.StudentCount();
	for (int i = 1; i <= count; i++) {
		PrintStudent(database, i);
	}
	std::cout << std::endl;
}

void UI::AppendStudent(Database& database) {
	std::string firstname, lastname;
	std::cout << "First Name: ";
	std::cin >> firstname;
	std::cout << "Last Name: ";
	std::cin >> lastname;
	database.AddStudent(&firstname[0], &lastname[0]);
}

Subject UI::returnSubject() {
	int subjectCode;
	std::cout << std::endl << "1.Physics 2.Chemistry 3.Maths 4.Biology 5.English\n0 for exit\nEnter Subject code: ";
	std::cin >> subjectCode;

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
			std::cout << "Exiting......";
			loop = false;
			break;
		default:
			std::cout << "Exiting with invalid input. DO it again.....";
			break;
		}
	}
}
void UI::EnterAllMarksOfASubject(Database& database) {
	Subject subject = returnSubject();
	database.EnterAllMarksOfASubject(subject);
}

void UI::UpdateMarks(Database& database) {
	int rollno;
	float marks;
	Subject subject;

	std::cout << std::endl;
	std::cout << "Enter Roll No.: ";
	std::cin >> rollno;
	PrintTopColumn();
	PrintStudent(database, rollno);

	subject = returnSubject();

	std::cout << "Enter Marks: ";
	std::cin >> marks;
	database.UpdateMarksOfAStudent(rollno, subject, marks);
}

void UI::DeleteStudent(Database& database) {
	int rollno;
	std::cout << std::endl << "Enter Roll no of student to delete: ";
	std::cin >> rollno;
	database.DeleteStudent(rollno);
}

void UI::InsertStudent(Database& database) {
	int rollno;
	std::cout << std::endl << "Enter Roll no to insert a new student at: ";
	std::cin >> rollno;
	std::string firstname, lastname;
	std::cout << "First Name: ";
	std::cin >> firstname;
	std::cout << "Last Name: ";
	std::cin >> lastname;
	database.InsertStudent(rollno, &firstname[0], &lastname[0]);
}

void UI::UpdateAStudentName(Database& database) {

	int rollno;
	std::cout << std::endl << "Enter Roll no to of a student to edit: ";
	std::cin >> rollno;
	std::string firstname, lastname;
	std::cout << "First Name: ";
	std::cin >> firstname;
	std::cout << "Last Name: ";
	std::cin >> lastname;
	database.UpdateName(rollno, &firstname[0], &lastname[0]);
}

void UI::ViewStudentData(Database& database) {
	int rollno;
	std::cout << std::endl << "Enter Roll no of a student: ";
	std::cin >> rollno;
	PrintTopColumn();
	PrintStudent(database, rollno);
	std::cout << std::endl;
}

void UI::DisplayToppers(Database& database) {
	std::vector <int> rollno = database.TopperRollNos();
	int count = rollno.size();
	PrintTopColumn();
	for (int i = 0; i < count; i++) {
		PrintStudent(database, rollno[i]);
	}
}

void UI::DisplaySubjectToppers(Database& database) {
	Subject subject = returnSubject();
	std::vector <int> rollno = database.SubjectTopperRollNos(subject);
	int count = rollno.size();
	PrintTopColumn();
	for (int i = 0; i < count; i++) {
		PrintStudent(database, rollno[i]);
	}
}