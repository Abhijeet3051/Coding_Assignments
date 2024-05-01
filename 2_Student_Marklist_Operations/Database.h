#pragma once
#include<vector>
#include"Student_Data.h"

class Database
{
private:
	std::vector <Student_Data*> m_students;
public:
	void AddStudent(char* firstname, char* lastname);
	void EnterAllMarksOfASubject(Subject subject);
	void UpdateMarksOfAStudent(int rollno, Subject subject, float marks);
	void DeleteStudent(int rollno);
	void InsertStudent(int rollno, char* firstname, char* lastname);
	void UpdateName(int rollno, char* firstname, char* lastname);
	std::vector <int> TopperRollNos();
	std::vector <int> SubjectTopperRollNos(Subject subject);
	int StudentCount();
	void LoadData(const char* file);
	void SaveData(const char* file);
	Student_Data GetStudent(int rollno);

};