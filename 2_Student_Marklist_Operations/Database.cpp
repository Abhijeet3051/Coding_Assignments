#include <iostream>
#include <fstream>
#include "Database.h"

void Database::AddStudent(char* firstName, char* lastName) {
	int rollNo = m_students.size() + 2;

	m_students.push_back(new Student_Data(rollNo, firstName, lastName));
}

void Database::EnterAllMarksOfASubject(Subject subject) {
	int count = m_students.size();
	for (int i = 0; i < count; i++) {
		if (m_students[i]->GetMarks(subject) == -1) {
			while (i < count) {
				float marks;
				std::cout << std::endl << m_students[i]->GetFirstName() << " " << m_students[i]->GetLastName() << " : ";
				std::cin >> marks;
				if (marks == -1) {
					std::cout << "Exiting....";
					return;
				}
				if (marks < 0 || marks>100) {
					std::cout << std::endl << "Invalid Input. Please enter again";
					continue;
				}
				m_students[i]->SetMarks(marks, subject);
				i++;
			}
			break;
		}
	}
	std::cout << std::endl << "All Marks are already entered" << std::endl;
}

void Database::UpdateMarksOfAStudent(int rollno, Subject subject, float marks) {
	m_students[rollno - 1]->SetMarks(marks, subject);
}

void Database::DeleteStudent(int rollno) {

	delete m_students[rollno - 1];
	m_students.erase(m_students.begin() + rollno - 1);
	int count = m_students.size();

	for (int i = rollno - 1; i < count; i++) {
		m_students[i]->setRollNo(i + 1);
		//m_students[i-1] = m_students[i];
	}
}

void Database::InsertStudent(int rollno, char* firstname, char* lastname) {
	m_students.insert(m_students.begin() + rollno - 1, new Student_Data(rollno, firstname, lastname));

	int count = m_students.size();

	for (int i = rollno; i < count; i++) {
		m_students[i]->setRollNo(i + 1);
	}
}

void Database::UpdateName(int rollno, char* firstname, char* lastname) {
	m_students[rollno - 1]->SetFirstName(firstname);
	m_students[rollno - 1]->SetLastName(lastname);
}

std::vector <int> Database::TopperRollNos() {
	std::vector <int> topperRollNo;
	int topperMarks = -1;
	int count = m_students.size();
	for (int i = 0; i < count; i++) {
		if (m_students[i]->GetPercentage() == topperMarks) {
			topperRollNo.push_back(i + 1);
		}
		else if (m_students[i]->GetPercentage() > topperMarks) {
			topperRollNo.clear();
			topperRollNo.push_back(i + 1);
			topperMarks = m_students[i]->GetPercentage();
		}
	}
	return topperRollNo;
}
std::vector <int> Database::SubjectTopperRollNos(Subject subject) {
	std::vector <int> SubjecttopperRollNo;
	int SubjecttopperMarks = -1;
	int count = m_students.size();
	for (int i = 0; i < count; i++) {
		if (m_students[i]->GetMarks(subject) == SubjecttopperMarks) {
			SubjecttopperRollNo.push_back(i + 1);
		}
		else if (m_students[i]->GetMarks(subject) > SubjecttopperMarks) {
			SubjecttopperRollNo.clear();
			SubjecttopperRollNo.push_back(i + 1);
			SubjecttopperMarks = m_students[i]->GetMarks(subject);
		}
	}
	return SubjecttopperRollNo;
}

int Database::StudentCount() {
	return m_students.size();
}

void Database::LoadData(const char* file) {

	std::ifstream reader(file, std::ios::ate);
	int count = (int)reader.tellg() / sizeof(Student_Data);
	reader.seekg(0, std::ios::beg);
	if (reader.is_open()) {
		for (int i = 0; i < count; i++) {
			m_students.push_back(new Student_Data);
			reader.read((char*)m_students[i], sizeof(Student_Data));
		}
		reader.close();
	}
}

void Database::SaveData(const char* file) {
	std::ofstream writer(file, std::ios::binary);
	int count = m_students.size();
	for (int i = 0; i < count; i++) {
		writer.write((char*)m_students[i], sizeof(Student_Data));
	}
	writer.close();
}

Student_Data Database::GetStudent(int rollno) {
	return *m_students[rollno - 1];
}