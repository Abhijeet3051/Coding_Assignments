#include<iostream>
#include <iostream>
#include "UI.h"
using namespace std;

void main() {
	UI ui;
	ArtifactDatabase database;
	bool entry = true;
	database.LoadData("database.txt");

	while (entry) {
		ui.PrintDatabase(database);
		int action;
		cout << endl << "Choose Your Action: "
			<< endl << "1. Create an artifact "
			<< endl << "2. delete an artifact"
			<< endl << "3. save and exit"
			<< endl;
		cin >> action;
		switch (action) {

		case 1:
			ui.EnterAnArtifact(database);
			break;

		case 2:
			ui.DeleteAnArtifact(database);
			break;

		case 3:
			database.SaveData("database.txt");
			entry = false;
			break;

		default:
			break;

		}
	}

}

