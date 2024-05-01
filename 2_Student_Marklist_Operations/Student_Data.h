#pragma once
#include <string>
#include "Subjects.h"

#define NAME_SIZE 50

class Student_Data
{
private:
	int m_rollNo;
	char m_firstName[NAME_SIZE], m_lastName[NAME_SIZE];
	float m_marks[5];
	float m_percentage;
	char m_grade;
	void defaultMarks();

public:
	Student_Data(); //Constructor
	Student_Data(int rollno, char* firstname, char* lastname); //Parameterized Constructor
	void setRollNo(int rollno);
	void SetFirstName(char* firstName);
	void SetLastName(char* lastName);
	void SetMarks(float marks, Subject subject);
	void CalculatePercentage();
	void SetGrade();

	int GetRollNo() const;
	std::string GetFirstName() const;
	std::string GetLastName() const;
	float GetMarks(Subject subject) const;
	float GetPercentage() const;
	char GetGrade() const;
};
