#pragma once
#include"student.h"
#include<vector>
#include<fstream>
using namespace std;

class Division
{
private:
	vector<Student>students;
public:
	void addStudent(string fname, string lname);
	void deleteStudent(int rollNumber);
	void addMarks(int rollNumber, int choice, int mark);
	int findTopper();
	ofstream& write(ofstream& out, vector<Student>& students);
	int countLine(string filename);
	void readFile(string filename);
	vector<Student> getVec()
	{
		return students;
	}
};
