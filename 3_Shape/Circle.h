#pragma once
#include"Shape.h"

class Circle : public Shape {

private:
	float m_radius;

public:
	Circle();
	Circle(float radius);
	~Circle();
	void SetDimensions(float radius);
	void CalculateArea();
	void CalculatePerimeter();
};
