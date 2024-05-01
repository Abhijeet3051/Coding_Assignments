#pragma once
#include "Database.h"

#define ROLLNO_WIDTH 7
#define NAME_WIDTH 25
#define PHYSICS_WIDTH 9
#define CHEMISTRY_WIDTH 9
#define MATHS_WIDTH 9
#define BIOLOGY_WIDTH 9
#define ENGLISH_WIDTH 9
#define PERCENTAGE_WIDTH 5
#define GRADE_WIDTH 5

class UI {
private:
	Subject returnSubject() const;

public:
	void AddSeperator(int count) const;
	void ShowData(Database database) const;		//by referemce 
	void PrintHeadingElement(const char* title, int width) const;
	void PrintTopColumn() const;
	void PrintStudent(Database database, int rollno) const; //by ref
	void PrintSeperator(int characters) const;

	void AppendStudent(Database& database) const;
	void EnterAllMarksOfASubject(Database& database) const;
	void UpdateMarks(Database& database) const;
	void DeleteStudent(Database& database) const;
	void InsertStudent(Database& database) const;
	void UpdateAStudentName(Database& database) const;
	void ViewStudentData(Database& database) const;
	void DisplayToppers(Database& databse) const;
	void DisplaySubjectToppers(Database& database) const;
};