#pragma once
#include "ArtifactDatabase.h"
#include "Rectangle.h"
#include "Circle.h"
#define AREA_UNIT "sq. ft."
#define PERIMETER_UNIT "ft."
#define UNIT_WIDTH 11
#define NAME_WIDTH ARTIFACT_NAME+3
#define COSTPERUNIT_WIDTH 30
#define FLOAT_WIDTH 6
#define COST_WIDTH 15
#define CHAR_COUNT NAME_WIDTH +2 +COSTPERUNIT_WIDTH +2 +COST_WIDTH +1

class UI {
private:
	void createARectangle(Shape*& shape);
	void createACircle(Shape*& shape);

public:
	void PrintHeading();
	void AddSeperator(int count, char c);
	void PrintTableSeperator();
	void PrintAnArtifact(const Artifact& artifact);
	void PrintTotalCost(ArtifactDatabase& artifactDatabase);
	void PrintDatabase(ArtifactDatabase& artifactDatabase);

	void EnterAnArtifact(ArtifactDatabase& artifactDatabase);
	void DeleteAnArtifact(ArtifactDatabase& artifactDatabase);


};