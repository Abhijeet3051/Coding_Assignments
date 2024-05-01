#include "Student_Data.h"


void Student_Data::defaultMarks() {
	m_marks[physics] = -1;
	m_marks[chemistry] = -1;
	m_marks[maths] = -1;
	m_marks[biology] = -1;
	m_marks[english] = -1;
	m_percentage = -1;
	m_grade = '-';
}

Student_Data::Student_Data()
{
	defaultMarks();
	m_firstName[0] = '\0';
	m_lastName[0] = '\0';
	setRollNo(0);
}

Student_Data::Student_Data(int rollNo, char* firstName, char* lastName)
{
	defaultMarks();
	int i = 0;
	while (*(firstName + i) != '\0' && i < NAME_SIZE) {
		m_firstName[i] = *(firstName + i);
		i++;
	}
	m_firstName[i] = '\0';
	i = 0;
	while (*(lastName + i) != '\0' && i < NAME_SIZE) {
		m_lastName[i] = *(lastName + i);
		i++;
	}
	m_lastName[i] = '\0';
	i = 0;
	setRollNo(rollNo);
}

void Student_Data::setRollNo(int rollNo) {
	m_rollNo = rollNo;
}

void Student_Data::SetFirstName(char* firstName) {
	for (int i = 0; i < NAME_SIZE
		&& *(i + firstName) != '\0'; i++) {
		m_firstName[i] = *(i + firstName);
	}
}

void Student_Data::SetLastName(char* lastName) {
	for (int i = 0; i < NAME_SIZE && *(i + lastName) != '\0'; i++) {
		m_lastName[i] = *(i + lastName);
	}
}

void Student_Data::SetMarks(float marks, Subject subject) {
	m_marks[subject] = marks;
}

void Student_Data::CalculatePercentage() {
	if ((m_marks[0] != -1) && (m_marks[1] != -1) && (m_marks[2] != -1) && (m_marks[3] != -1) && (m_marks[4] != -1)) {
		m_percentage = (m_marks[0] + m_marks[1] + m_marks[2] + m_marks[3] + m_marks[4]) / 5;
		SetGrade();
	}
}

void Student_Data::SetGrade() {
	if (m_percentage < 40) {
		m_grade = 'X';
	}
	else {
		m_grade = ('A' + 9 - (int)(m_percentage - 1) / 10);
	}
}

int Student_Data::GetRollNo() const {
	return m_rollNo;
}


std::string Student_Data::GetFirstName() const {
	return m_firstName;
}

std::string Student_Data::GetLastName() const {
	return m_lastName;
}

float Student_Data::GetMarks(Subject subject) const {
	return m_marks[subject];
}

float Student_Data::GetPercentage() const {
	return m_percentage;
}

char Student_Data::GetGrade() const {
	return m_grade;
}