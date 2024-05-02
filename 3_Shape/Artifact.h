#pragma once
#ifndef Shape_h
#define Shape_h
#include "Shape.h"
#include <string>
#endif

#define ARTIFACT_NAME 11

enum CostBase { AREA_BASED, PERIMETER_BASED };

using namespace std;

class Artifact {
private:
	Shape* m_shape;
	enum CostBase m_costBase;
	enum ShapeName m_shapeName;
	float m_costPerUnit;
	float m_cost;
	char m_artifactName[ARTIFACT_NAME];
	void defaultValues();
	void calculateCost();
public:
	Artifact();
	Artifact(char* objectName, Shape* shape, enum CostBase costBase, enum ShapeName shapeName);

	void SetArtifactName(char* name);
	void SetCostBase(enum CostBase costBase);
	void SetCostPerUnit(float costPerUnit);
	void SetShapePointer(Shape* shape);

	string GetObjectName() const;
	float GetCostPerUnit() const;
	float GetCost() const;
	float GetArea() const;
	float GetPerimeter() const;
	enum CostBase GetCostBase() const;
	enum ShapeName GetShapeName() const;
	const Shape* const GetShapePointer() const;
};
