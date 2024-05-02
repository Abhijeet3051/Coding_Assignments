#pragma once
#include<vector>
#include "Artifact.h"

class ArtifactDatabase {
private:
	std::vector <Artifact*> m_artifacts;
	static float m_totalCost;

public:
	void AddAnArtifact(Artifact* artifact);
	void DeleteAnArtifact(int index);
	void SaveData(const char* fileName);
	void LoadData(const char* fileName);

	float GetTotalCost();
	Artifact GetArtifact(int index);
	void SetAnArtifactCost(int index, float costPerUnit);
	void SetLastArtifactCost(float costPerUnit);
	int size();
};
