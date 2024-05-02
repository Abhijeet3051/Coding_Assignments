
#include<iostream>
#include "UI.h"
#include <string>
#include <iomanip>
using namespace std;

void UI::createARectangle(Shape*& shape) {
	float length, width;
	cout << "Enter Length: ";
	cin >> length;
	cout << "Enter Width: ";
	cin >> width;
	shape = new Rectangle(length, width);
}

void UI::createACircle(Shape*& shape) {
	float radius;
	cout << "Enter Radius: ";
	cin >> radius;
	shape = new Circle(radius);
}

void UI::PrintHeading() {
	char seperator = ' ';
	cout << left << setw(NAME_WIDTH) << setfill(seperator) << "| Object Name"
		<< left << setw(2 * UNIT_WIDTH + FLOAT_WIDTH) << setfill(seperator) << "| Area/Perimeter"
		<< left << setw(COSTPERUNIT_WIDTH) << setfill(seperator) << "| Cost per unit"
		<< left << setw(COST_WIDTH) << setfill(seperator) << "| Cost"
		<< endl;
	PrintTableSeperator();
}


void UI::AddSeperator(int count, char c) {
	for (int i = 0; i < count; i++) {
		cout << c;
	}
}

void UI::PrintTableSeperator() {
	cout << "|";
	AddSeperator(NAME_WIDTH - 1, '-');
	cout << "|";
	AddSeperator(2 * UNIT_WIDTH + FLOAT_WIDTH - 1, '-');
	cout << "|";
	AddSeperator(COSTPERUNIT_WIDTH - 1, '-');
	cout << "|";
	AddSeperator(COST_WIDTH - 1, '-');
}

void UI::PrintAnArtifact(Artifact& artifact) {
	char seperator = ' ';
	cout << "| " << left << setw(NAME_WIDTH - 2) << setfill(seperator) << artifact.GetObjectName();

	if (artifact.GetCostBase() == AREA_BASED) {
		cout << "| " << left << setw(UNIT_WIDTH) << setfill(seperator) << "Area = "
			<< left << setw(FLOAT_WIDTH) << setfill(seperator) << artifact.GetArea()
			<< left << setw(UNIT_WIDTH - 2) << setfill(seperator) << AREA_UNIT;
		cout << "| " << left << setw(COSTPERUNIT_WIDTH - 2) << setfill(seperator) << artifact.GetCostPerUnit();
	}
	else if (artifact.GetCostBase() == PERIMETER_BASED) {
		cout << "| " << left << setw(UNIT_WIDTH) << setfill(seperator) << "Perimeter = "
			<< left << setw(FLOAT_WIDTH) << setfill(seperator) << artifact.GetPerimeter()
			<< left << setw(UNIT_WIDTH - 2) << setfill(seperator) << PERIMETER_UNIT;
		cout << "| " << left << setw(COSTPERUNIT_WIDTH - 2) << setfill(seperator) << artifact.GetCostPerUnit();
	}
	else {
		cout << "| " << left << setw(FLOAT_WIDTH) << setfill(seperator) << artifact.GetCostPerUnit();
	}
	cout << "| " << left << setw(COST_WIDTH - 2) << setfill(seperator) << artifact.GetCost();
}

void UI::PrintTotalCost(ArtifactDatabase& artifactDatabase) {
	cout << "Total Cost = " << artifactDatabase.GetTotalCost();
}

void UI::PrintDatabase(ArtifactDatabase& artifactDatabase) {
	cout << endl;
	PrintHeading();
	cout << endl;
	int count = artifactDatabase.size();
	for (int i = 0; i < count; i++) {
		PrintAnArtifact(artifactDatabase.GetArtifact(i));
		cout << endl;
		PrintTableSeperator();
		cout << endl;
	}
	PrintTotalCost(artifactDatabase);
}

void UI::EnterAnArtifact(ArtifactDatabase& artifactDatabase) {
	string artifactName;
	enum ShapeName shapeName;
	int shapeCode, costBase;
	float costPerUnit;
	Shape* shape;

	cout << endl << "Enter Artifact Name: ";
	cin >> artifactName;

	cout << endl << "Select the shape of object:" << endl
		<< RECTANGLE << ". Rectangle\t"
		<< CIRCLE << ". Circle\t"
		<< endl;
	cin >> shapeCode;
	switch (shapeCode) {
	case RECTANGLE:
		createARectangle(shape);
		shapeName = RECTANGLE;
		break;
	case CIRCLE:
		createACircle(shape);
		shapeName = CIRCLE;
		break;
	default:
		cout << endl << "Invalid Input";
		return;
	}

	cout << endl << "Enter Cost base:"
		<< AREA_BASED << ". Area\t"
		<< PERIMETER_BASED << ". Perimeter\t"
		<< endl;
	cin >> costBase;
	switch (costBase) {
	case AREA_BASED:
		artifactDatabase.AddAnArtifact(new Artifact(&artifactName[0], shape, AREA_BASED, shapeName));
		break;
	case PERIMETER_BASED:
		artifactDatabase.AddAnArtifact(new Artifact(&artifactName[0], shape, PERIMETER_BASED, shapeName));
		break;
	default:
		cout << endl << "Invalid Input";
		delete shape;
		return;
	}

	cout << "Enter cost ";
	if (costBase == AREA_BASED) cout << "per " << AREA_UNIT << " : ";
	else if (costBase == PERIMETER_BASED) cout << "per " << PERIMETER_UNIT << " : ";
	cin >> costPerUnit;
	artifactDatabase.SetLastArtifactCost(costPerUnit);
}

void UI::DeleteAnArtifact(ArtifactDatabase& artifactDatabase) {
	int index;

	cout << endl << "Enter index of the Artifact to delete: ";
	cin >> index;
	if (index >= artifactDatabase.size()) {
		cout << endl << "Invalid Input";
		return;
	}
	artifactDatabase.DeleteAnArtifact(index);
}