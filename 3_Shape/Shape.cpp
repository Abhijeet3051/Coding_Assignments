#include "Shape.h"

void Shape::CalculateArea() {
	m_area = 0;
}

void Shape::CalculatePerimeter(){
	m_perimeter = 0;
}

float Shape::GetArea() const{
	return m_area;
}

float Shape::GetPerimeter() const{
	return m_perimeter;
}