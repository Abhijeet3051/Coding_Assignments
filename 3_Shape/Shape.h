#pragma once

class Shape
{
protected:
	float m_area, m_perimeter;
public:
	void CalculateArea();
	void CalculatePerimeter();
	float GetArea() const;
	float GetPerimeter() const;
};

enum ShapeName {
	VOID,
	RECTANGLE,
	CIRCLE
};