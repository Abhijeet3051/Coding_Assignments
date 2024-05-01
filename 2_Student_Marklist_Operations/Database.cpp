#include <iostream>
#include <fstream>
#include "Database.h"

using namespace std;

void Database::AddStudent(char* firstName, char* lastName) {
	int rollNo = m_students.size() + 1;

	m_students.push_back(new Student(rollNo, firstName, lastName));
}

void Database::EnterAllMarksOfASubject(Subject subject) {		//cin cout shouldnt be heere since ui calss is created . can move it to  ui class
	int count = m_students.size();
	for (int i = 0; i < count; i++) {
		if (m_students[i]->GetMarks(subject) == -1) {
			while (i < count) {
				float marks;
				cout << endl << m_students[i]->GetFirstName() << " " << m_students[i]->GetLastName() << " : ";
				cin >> marks;
				if (marks == -1) {
					cout << "Exiting....";
					return;
				}
				if (marks < 0 || marks>100) {
					cout << endl << "Invalid Input. Please enter again";
					continue;
				}
				m_students[i]->SetMarks(marks, subject);
				i++;
			}
			break;
		}
	}
	cout << endl << "All Marks are already entered" << endl;
}

void Database::UpdateMarksOfAStudent(int rollno, Subject subject, float marks) {
	m_students[rollno - 1]->SetMarks(marks, subject);
}

void Database::DeleteStudent(int rollno) {	//condition to checkk entered roll no is available

	delete m_students[rollno - 1];
	m_students.erase(m_students.begin() + rollno - 1);
	int count = m_students.size();

	for (int i = rollno - 1; i < count; i++) {
		m_students[i]->SetRollNo(i + 1);
		//m_students[i-1] = m_students[i];
	}
}

void Database::InsertStudent(int rollno, char* firstname, char* lastname) {
	m_students.insert(m_students.begin() + rollno - 1, new Student(rollno, firstname, lastname));

	int count = m_students.size();

	for (int i = rollno; i < count; i++) {
		m_students[i]->SetRollNo(i + 1);
	}
}

void Database::UpdateName(int rollno, char* firstname, char* lastname) {
	m_students[rollno - 1]->SetFirstName(firstname);
	m_students[rollno - 1]->SetLastName(lastname);
}

vector <int> Database::TopperRollNos() {
	vector <int> topperRollNo;
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

vector <int> Database::SubjectTopperRollNos(Subject subject) {
	vector <int> SubjecttopperRollNo;
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

int Database::StudentCount() const {
	return m_students.size();
}

void Database::LoadData(const char* file) {

	ifstream reader(file, ios::ate);
	int count = (int)reader.tellg() / sizeof(Student);
	reader.seekg(0, ios::beg);
	if (reader.is_open()) {
		for (int i = 0; i < count; i++) {
			m_students.push_back(new Student);
			reader.read((char*)m_students[i], sizeof(Student));
		}
		reader.close();
	}
}

void Database::SaveData(const char* file) {
	ofstream writer(file, ios::binary);
	int count = m_students.size();
	for (int i = 0; i < count; i++) {
		writer.write((char*)m_students[i], sizeof(Student));
	}
	writer.close();
}

Student Database::GetStudent(int rollno) const {
	return *m_students[rollno - 1];
}