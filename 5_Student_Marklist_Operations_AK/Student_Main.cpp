// abhijeet_studentAssignment.cpp : Defines the entry point for the console application.
// In this project we have Done csv file handilng and actual data saved not binary

#include <iostream>
#include<string>
#include"Division.h"
#include"student.h"
#include<conio.h>
#include<iomanip>
using namespace std;

#define ROLLNO_WIDTH 6
#define FNAME_WIDTH 10
#define LNAME_WIDTH 10
#define MARATHI_WIDTH 8
#define HINDI_WIDTH 9
#define ENGLISH_WIDTH 9
#define MATHS_WIDTH 9
#define SCIENCE_WIDTH 9
#define SOCIALSCIENCE_WIDTH 13
#define TOTALMARKS_WIDTH 10
#define GRADE_WIDTH 5

int main()
{
	bool Exit = false;
	int rollNumber;
	string fname, lname;
	char seperator = ' ';
	ofstream outfile;
	Division d;
	vector<Student>vec;
	vec = d.getVec();
	int option;
	d.readFile("studentData.csv");
	while (!Exit)
	{
		system("CLS");
		cout << "RollNo|FirstName |LastName  |Marathi |Hindi    |English  |Maths    |Science  |socialScience|TotalMarks|Grade|" << endl;
		cout << "_____________________________________________________________________________________________________________" << endl;
		vec = d.getVec();
		for (int i = 0; i < vec.size(); i++)
		{
			cout << left << setw(ROLLNO_WIDTH) << setfill(seperator) << vec[i].getRollNumber() << "|";
			cout << left << setw(FNAME_WIDTH) << setfill(seperator) << vec[i].getFName() << "|";
			cout << left << setw(LNAME_WIDTH) << setfill(seperator) << vec[i].getLName() << "|";
			cout << left << setw(MARATHI_WIDTH) << setfill(seperator) << vec[i].getMarathiMarks() << "|";
			cout << left << setw(HINDI_WIDTH) << setfill(seperator) << vec[i].getHindiMarks() << "|";
			cout << left << setw(ENGLISH_WIDTH) << setfill(seperator) << vec[i].getEnglishMarks() << "|";
			cout << left << setw(MATHS_WIDTH) << setfill(seperator) << vec[i].getMathsMarks() << "|";;
			cout << left << setw(SCIENCE_WIDTH) << setfill(seperator) << vec[i].getScienceMarks() << "|";
			cout << left << setw(SOCIALSCIENCE_WIDTH) << setfill(seperator) << vec[i].getSocialScienceMarks() << "|";
			cout << left << setw(TOTALMARKS_WIDTH) << setfill(seperator) << vec[i].totalMarks() << "|";
			cout << left << setw(GRADE_WIDTH) << setfill(seperator) << vec[i].grade() << "|" << endl;
			/*  cout << "_____________________________________________________________________________________________________________"<<endl;*/
		}
		cout << "_____________________________________________________________________________________________________________" << endl;
		cout << "Note:  F stands for Fail, P stands for Pass, N stands for data insufficient" << endl;
		cout << endl;

		cout << "1.For Add Student" << endl;
		cout << endl;
		cout << "2.For Delete Student" << endl;
		cout << endl;
		cout << "3.Add marks" << endl;
		cout << endl;
		cout << "4.GetTopper" << endl;
		cout << endl;
		cout << "5.Exit and save" << endl;
		cout << endl;

		cout << "Enter a option choice" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Enter FirstName" << endl;
			cin >> fname;
			cout << "Enter LastName" << endl;
			cin >> lname;
			d.addStudent(fname, lname);
			vec = d.getVec();
			break;
		case 2:
			cout << "Enter a rollNumber of Student to delete Student" << endl;
			cin >> rollNumber;
			d.deleteStudent(rollNumber);
			vec = d.getVec();
			break;

		case 3:
			int choice, mark, rollNumber, selection;
			int m[6];
			cout << "Enter a rollNumber of Student" << endl;
			cin >> rollNumber;
			cout << "1.Enter single subject marks" << endl;
			cout << "2.Enter all subject marks" << endl;
			cin >> selection;

			switch (selection)
			{
			case 1:
				cout << "Enter  1.For Marathi  2.For Hindi  3.For English  4.For Science  5.For Maths  6.For SocialScience" << endl;
				cin >> choice;
				cout << "Enter Marks" << endl;
				cin >> mark;
				d.addMarks(rollNumber, choice, mark);
				vec = d.getVec();
				break;

			case 2:
				cout << "1.For Marathi  2.For Hindi  3.For English  4.For Science  5.For Maths  6.For SocialScience" << endl;
				for (int i = 0; i < 6; i++)
				{
					cout << "Enter mark" << endl;
					cin >> m[i];
				}

				for (int i = 0; i < 6; i++)
				{
					d.addMarks(rollNumber, i + 1, m[i]);
				}
				break;
			}
			break;

		case 4:
			cout << "RollNumber of Topper Student is: " << endl;
			cout << d.findTopper() << "  ";
			cout << vec[d.findTopper() - 1].getFName() << " " << vec[d.findTopper() - 1].getLName();
			_getch();
			break;

		case 5:
		default:
			for (int i = 0; i < vec.size(); i++)
			{
				d.write(outfile, vec);
			}
			Exit = true;
			break;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file