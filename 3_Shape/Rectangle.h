#pragma once
#include"Shape.h"


class Rectangle : public Shape
{
private:
	float m_length, m_width;

public:
	Rectangle();
	Rectangle(float length, float width);
	~Rectangle();
	void SetDimensions(float length, float width);
	void CalculateArea();
	void CalculatePerimeter();
};