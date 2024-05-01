#pragma once
#include "Student_Data.h"
#include <vector>



class Database {

private:
	vector <Student*> m_students;

public:
	void AddStudent(char* firstname, char* lastname);
	void EnterAllMarksOfASubject(Subject subject);
	void UpdateMarksOfAStudent(int rollno, Subject subject, float marks);
	void DeleteStudent(int rollno);
	void InsertStudent(int rollno, char* firstname, char* lastname);
	void UpdateName(int rollno, char* firstname, char* lastname);
	vector <int> TopperRollNos();			// can pass a vector as parameter and values can be addedd to it. so it does not make a copy
	vector <int> SubjectTopperRollNos(Subject subject);
	int StudentCount() const;
	void LoadData(const char* file);
	void SaveData(const char* file);
	Student GetStudent(int rollno) const; //going to create copy on stack

};