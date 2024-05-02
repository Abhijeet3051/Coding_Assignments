#include "ArtifactDatabase.h"
#include "Circle.h"
#include "Rectangle.h"
#include <fstream>

using namespace std;

float ArtifactDatabase::m_totalCost = 0;

void ArtifactDatabase::AddAnArtifact(Artifact* artifact)
{
	m_artifacts.push_back(artifact);
	m_totalCost += artifact->GetCost();
}


void ArtifactDatabase::DeleteAnArtifact(int index)
{
	m_totalCost -= m_artifacts[index]->GetCost();
	delete m_artifacts[index];
	m_artifacts.erase(m_artifacts.begin() + index);
}

void ArtifactDatabase::SaveData(const char* fileName)
{
	enum ShapeName shapeName;
	ofstream writer(fileName);
	int dataSize = m_artifacts.size();
	for (int i = 0; i < dataSize; i++)
	{
		writer.write((char*)m_artifacts[i], sizeof(Artifact));
		shapeName = m_artifacts[i]->GetShapeName();
		switch (shapeName)
		{
		case CIRCLE:
			writer.write((char*)m_artifacts[i]->GetShapePointer(), sizeof(Circle));
			break;
		case RECTANGLE:
			writer.write((char*)m_artifacts[i]->GetShapePointer(), sizeof(Rectangle));
			break;
		default:
			break;
		}
	}
}

void ArtifactDatabase::LoadData(const char* fileName)
{
	enum ShapeName shapeName;
	ifstream reader(fileName);
	int i = 0;
	Shape* shape;
	m_artifacts.push_back(new Artifact);
	reader.read((char*)m_artifacts[i], sizeof(Artifact));
	while (reader.is_open() && !reader.eof())
	{

		shapeName = m_artifacts[i]->GetShapeName();
		switch (shapeName)
		{
		case CIRCLE:
			shape = new Circle;
			reader.read((char*)shape, sizeof(Circle));
			m_artifacts[i]->SetShapePointer(shape);
			break;
		case RECTANGLE:
			shape = new Rectangle;
			reader.read((char*)shape, sizeof(Rectangle));
			m_artifacts[i]->SetShapePointer(shape);
			break;

		default:

			break;
		}

		i++;

		m_artifacts.push_back(new Artifact);
		reader.read((char*)m_artifacts[i], sizeof(Artifact));
	}
	m_artifacts.erase(m_artifacts.begin() + i);
}

float ArtifactDatabase::GetTotalCost()
{
	return m_totalCost;
}


Artifact ArtifactDatabase::GetArtifact(int index)
{
	return *m_artifacts[index];
}


void ArtifactDatabase::SetAnArtifactCost(int index, float costPerUnit)
{
	m_totalCost -= m_artifacts[index]->GetCost();
	m_artifacts[index]->SetCostPerUnit(costPerUnit);
	m_totalCost += m_artifacts[index]->GetCost();
}

void ArtifactDatabase::SetLastArtifactCost(float costPerUnit)
{
	int index = m_artifacts.size() - 1;
	SetAnArtifactCost(index, costPerUnit);
}

int ArtifactDatabase::size() {
	return m_artifacts.size();
}


