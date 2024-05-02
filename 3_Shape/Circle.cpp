#include "Circle.h"

const float pi = 3.142;

Circle::Circle() {
	SetDimensions(0);
	CalculateArea();
	CalculatePerimeter();
}

Circle::Circle(float radius) {
	SetDimensions(radius);
	CalculateArea();
	CalculatePerimeter();
}

Circle:: ~Circle() {
	//delete this;
}

void Circle::SetDimensions(float radius) {
	m_radius = radius;
}

void Circle::CalculateArea() {
	m_area = pi * m_radius * m_radius;
}

void Circle::CalculatePerimeter() {
	m_perimeter = 2 * pi * m_radius;
}