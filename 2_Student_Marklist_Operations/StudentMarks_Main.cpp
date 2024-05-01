#include <iostream>
#include <conio.h>
#include "Database.h"
#include "UI.h"


void main()
{
	bool exit = false;

	Database database;
	database.LoadData("StudentDatabase.txt");
	UI ui;

	while (!exit)
	{
		int action;

		std::cout << std::endl << "Choose an action:"
			<< std::endl << "1. add a student"
			<< std::endl << "2. enter everyone's marks of a subject"
			<< std::endl << "3. update marks"
			<< std::endl << "4. delete a student"
			<< std::endl << "5. insert a student"
			<< std::endl << "6. update a student name"
			<< std::endl << "7. View Data of a student"
			<< std::endl << "8. display topper"
			<< std::endl << "9. Display Subjectwise Topper"
			<< std::endl << "10. Save and Exit"
			<< std::endl;
		std::cout << std::endl << "Action No.: ";
		std::cin >> action;

		switch (action)
		{
		case 1:
			ui.AppendStudent(database);
			break;

		case 2:
			ui.EnterAllMarksOfASubject(database);

		case 3:
			ui.UpdateMarks(database);
			break;

		case 4:
			ui.DeleteStudent(database);
			break;

		case 5:
			ui.InsertStudent(database);
			break;

		case 6:
			ui.UpdateAStudentName(database);
			break;

		case 7:
			ui.ViewStudentData(database);

		case 8:
			ui.DisplayToppers(database);
			//getch();
			break;

		case 9:
			ui.DisplaySubjectToppers(database);
			//getch();
			break;

		case 10:
			database.SaveData("StudentDatabase.txt");
			exit = true;
			break;

		default:
			break;
		}

	}
}