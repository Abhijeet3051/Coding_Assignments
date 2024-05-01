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
	Subject returnSubject();

public:
	void AddSeperator(int count);
	void ShowData(Database database);
	void PrintHeadingElement(const char* title, int width);
	void PrintTopColumn();
	void PrintStudent(Database database, int rollno);
	void PrintSeperator(int characters);

	void AppendStudent(Database& database);
	void EnterAllMarksOfASubject(Database& database);
	void UpdateMarks(Database& database);
	void DeleteStudent(Database& database);
	void InsertStudent(Database& database);
	void UpdateAStudentName(Database& database);
	void ViewStudentData(Database& database);
	void DisplayToppers(Database& databse);
	void DisplaySubjectToppers(Database& database);

	//"1. add a student"
	//"2. enter everyone's marks of a subject"
	//"3. update marks"
	//"4. delete a student"
	//"5. insert a student"
	//"6. update a student name"
	//"7. View Data of a student"
	//"8. display topper"
	//"9. Display Subjectwise Topper"
	//"10. Save and Exit"
};
