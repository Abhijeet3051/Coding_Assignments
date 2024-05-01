#include<iostream>
#include <conio.h>
#include "UI.h"

using namespace std;

void main() {

	bool exit = false;

	Database database;
	database.LoadData("StudentDatabase.bin");
	UI ui;

	while (!exit) {

		int action;

		system("CLS");
		ui.ShowData(database);

		cout << endl << "Choose an action:"
			<< endl << "1. add a student"
			<< endl << "2. enter everyone's marks of a subject"
			<< endl << "3. update marks"
			<< endl << "4. delete a student"
			<< endl << "5. insert a student"
			<< endl << "6. update a student name"
			<< endl << "7. View Data of a student"
			<< endl << "8. display topper"
			<< endl << "9. Display Subjectwise Topper"
			<< endl << "10. Save and Exit"
			<< endl;

		cout << endl << "Action No.: ";
		cin >> action;

		switch (action) {
		case 1:

		{
			ui.AppendStudent(database);
			break;
		}
		case 2:
		{
			ui.EnterAllMarksOfASubject(database);
			break;
		}
		case 3:
		{
			ui.UpdateMarks(database);
			break;
		}
		case 4:
		{
			ui.DeleteStudent(database);
			break;
		}
		case 5:
		{
			ui.InsertStudent(database);
			break;
		}
		case 6:
		{
			ui.UpdateAStudentName(database);
			break;
		}
		case 7:
		{
			ui.ViewStudentData(database);
			_getch();
			break;
		}
		case 8:
		{
			ui.DisplayToppers(database);
			_getch();
			break;
		}
		case 9:
		{
			ui.DisplaySubjectToppers(database);
			_getch();
			break;
		}
		case 10:
		{
			database.SaveData("StudentDatabase.bin");
			exit = true;
			break;
		}
		default:
			break;
		}
	}

}

