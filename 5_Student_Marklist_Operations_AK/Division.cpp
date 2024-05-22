#include"Division.h"
#include"student.h"
#include"iostream"
#include <sstream>

void Division::addStudent(string fname, string lname)
{
	int rollNumber = students.size() + 1;
	students.push_back(Student(rollNumber, fname, lname));
}

void  Division::deleteStudent(int rollNumber)
{
	students.erase(students.begin() + rollNumber - 1);
	for (int i = 0; i < students.size(); i++)
	{
		students[i].setRollNumber(i + 1);
	}
}

void Division::addMarks(int rollNumber, int choice, int mark)
{
	switch (choice)
	{
	case 1:
		students[rollNumber - 1].setMarathiMarks(mark);
		break;

	case 2:
		students[rollNumber - 1].setHindiMarks(mark);
		break;

	case 3:
		students[rollNumber - 1].setEnglishMarks(mark);
		break;

	case 4:
		students[rollNumber - 1].setScienceMarks(mark);
		break;

	case 5:
		students[rollNumber - 1].setMathsMarks(mark);
		break;

	case 6:
		students[rollNumber - 1].setSocialScienceMarks(mark);
		break;

	default:
		break;
	}
}

int Division::findTopper()
{
	int temp = 0, x = 0;

	for (int j = 0; j < students.size(); j++)
	{
		if (temp < students[j].totalMarks())
		{
			temp = students[j].totalMarks();
			x = j + 1;
		}
	}
	return x;
}

ofstream& Division::write(ofstream& outfile, vector<Student>& students)
{
	outfile.open("studentData.csv", ios::trunc);
	for (int i = 0; i < students.size(); i++)
	{
		outfile << students[i].getRollNumber() << ",";
		outfile << students[i].getFName() << ",";
		outfile << students[i].getLName() << ",";
		outfile << students[i].getMarathiMarks() << ",";
		outfile << students[i].getHindiMarks() << ",";
		outfile << students[i].getEnglishMarks() << ",";
		outfile << students[i].getMathsMarks() << ",";
		outfile << students[i].getScienceMarks() << ",";
		outfile << students[i].getSocialScienceMarks() << endl;
	}
	outfile.close();
	return outfile;
}

int Division::countLine(string filename)
{
	string line;
	int count = 0;
	ifstream mFile(filename);
	while (mFile.peek() != EOF)
	{
		getline(mFile, line);
		count++;
	}
	return count;
}

void Division::readFile(string filename)
{
	vector<string> ticker;
	vector<string> temp_divisions;
	vector<string> temp_standards;
	Division d;
	vector<Student> vec;
	vec = d.getVec();
	string str;
	string val;

	ifstream mFile;
	mFile.open(filename, ios::in | ios::app);

	if (mFile.is_open())
	{
		if (d.countLine(filename) == 0)
		{
			cout << "The file is empty...!" << endl;
		}

		while (mFile.peek() != EOF)
		{
			ticker.clear();
			getline(mFile, str);
			stringstream s(str);

			while (getline(s, val, ','))
			{
				ticker.push_back(val);
			}

			Student s1(stoi(ticker[0]), ticker[1], ticker[2]);
			s1.setMarathiMarks(stoi(ticker[3]));
			s1.setHindiMarks(stoi(ticker[4]));
			s1.setEnglishMarks(stoi(ticker[5]));
			s1.setMathsMarks(stoi(ticker[6]));
			s1.setScienceMarks(stoi(ticker[7]));
			s1.setSocialScienceMarks(stoi(ticker[8]));
			students.push_back(s1);

		}

	}
	mFile.close();
}
