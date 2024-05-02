#include "Artifact.h"

using namespace std;

void Artifact::defaultValues() {
	m_shape = 0;
	m_costBase = AREA_BASED;
	m_shapeName = VOID;
	m_costPerUnit = 0;
	m_cost = 0;
	m_artifactName[0] = '\0';
}

Artifact::Artifact() {
	defaultValues();
}

void Artifact::calculateCost() {
	float area = m_shape->GetArea();
	float perimeter = m_shape->GetPerimeter();
	m_cost = ((m_costBase == AREA_BASED) ? area : perimeter) * m_costPerUnit;
}

Artifact::Artifact(char* name, Shape* shape, enum CostBase costBase, enum ShapeName shapeName) {
	defaultValues();
	m_shape = shape;
	m_shapeName = shapeName;
	SetArtifactName(name);
	SetCostBase(costBase);
}

void Artifact::SetArtifactName(char* name) {
	int i = 0;
	while (*(name + i) != '\0' && i < ARTIFACT_NAME - 1) {
		m_artifactName[i] = *(name + i);
		i++;
	}
	m_artifactName[i] = '\0';
}

void Artifact::SetCostBase(CostBase costBase) {
	m_costBase = costBase;
	calculateCost();
}

void Artifact::SetCostPerUnit(float costPerUnit) {
	m_costPerUnit = costPerUnit;
	calculateCost();
}

string Artifact::GetObjectName() const {
	string name = m_artifactName;
	return name;
}

float Artifact::GetCostPerUnit() const {
	return m_costPerUnit;
}

float Artifact::GetCost() const {
	return m_cost;
}

enum CostBase Artifact::GetCostBase() const {
	return m_costBase;
}

float Artifact::GetArea() const {
	return m_shape->GetArea();
}

float Artifact::GetPerimeter() const {
	return m_shape->GetPerimeter();
}

enum ShapeName Artifact::GetShapeName() const {
	return m_shapeName;
}

const Shape* const Artifact::GetShapePointer() const {
	return m_shape;
}

void Artifact::SetShapePointer(Shape* shape) {
	m_shape = shape;
}