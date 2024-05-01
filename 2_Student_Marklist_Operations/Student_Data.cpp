#include "Student_Data.h"

void Student::defaultMarks() {
	m_marks[physics] = -1;
	m_marks[chemistry] = -1;
	m_marks[maths] = -1;
	m_marks[biology] = -1;
	m_marks[english] = -1;
	m_percentage = -1;
	m_grade = '-';
}

Student::Student() {
	defaultMarks();
	m_firstName[0] = '\0';
	m_lastName[0] = '\0';
	SetRollNo(0);
}

Student::Student(int rollNo, char* firstName, char* lastName) {
	defaultMarks();
	int i = 0;
	while (*(firstName + i) != '\0' && i < name_size - 1) {
		m_firstName[i] = *(firstName + i);
		i++;
	}
	m_firstName[i] = '\0';
	i = 0;
	while (*(lastName + i) != '\0' && i < name_size - 1) {
		m_lastName[i] = *(lastName + i);
		i++;
	}
	m_lastName[i] = '\0';
	i = 0;
	SetRollNo(rollNo);

}

void Student::SetRollNo(int rollNo) {
	m_rollNo = rollNo;
}

void Student::SetFirstName(char* firstName) {
	int i;
	for (i = 0; i < name_size - 1 && *(i + firstName) != '\0'; i++) {
		m_firstName[i] = *(i + firstName);
	}
	m_firstName[i] = '\0';
}

void Student::SetLastName(char* lastName) {
	int i;
	for (i = 0; i < name_size - 1 && *(i + lastName) != '\0'; i++) {
		m_lastName[i] = *(i + lastName);
	}
	m_lastName[i] == '\0';
}

void Student::SetMarks(float marks, Subject subject) {
	m_marks[subject] = marks;
}

void Student::CalculatePercentage() {
	if ((m_marks[0] != -1) && (m_marks[1] != -1) && (m_marks[2] != -1) && (m_marks[3] != -1) && (m_marks[4] != -1)) {
		m_percentage = (m_marks[0] + m_marks[1] + m_marks[2] + m_marks[3] + m_marks[4]) / 5;
		SetGrade();
	}
}

void Student::SetGrade() {
	if (m_percentage < 40) {
		m_grade = 'X';
	}
	else {
		m_grade = ('A' + 9 - (int)(m_percentage - 1) / 10);
	}
}

int Student::GetRollNo() const {
	return m_rollNo;
}

string Student::GetFirstName() const {
	string firstName = m_firstName;
	return firstName;
}

string Student::GetLastName() const {
	return m_lastName;
}

float Student::GetMarks(Subject subject) const {
	return m_marks[subject];
}

float Student::GetPercentage() const {
	return m_percentage;
}

char Student::GetGrade() const {
	return m_grade;
}