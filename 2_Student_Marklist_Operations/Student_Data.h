#pragma once
#include <string>
#include "Subjects.h"
using namespace std;

#define name_size 11


class Student {

private:
	//Attributes
	int m_rollNo;
	char m_firstName[name_size], m_lastName[name_size];		//try using string
	float m_marks[5];
	float m_percentage;
	char m_grade;
	void defaultMarks();

public:
	Student();
	Student(int rollno, char* firstname, char* lastname);
	void SetRollNo(int rollno);
	void SetFirstName(char* firstName);
	void SetLastName(char* lastName);
	void SetMarks(float marks, Subject subject);
	void CalculatePercentage();
	void SetGrade();

	int GetRollNo() const;
	string GetFirstName() const;
	string GetLastName() const;
	float GetMarks(Subject subject) const;
	float GetPercentage() const;
	char GetGrade() const;
};