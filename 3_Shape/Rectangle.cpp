#include"Rectangle.h"

Rectangle::Rectangle() {
	m_length = 0;
	m_width = 0;
}

Rectangle::~Rectangle() {
	//delete this;
}

Rectangle::Rectangle(float length , float width) {
	SetDimensions(length , width);
	CalculateArea();
	CalculatePerimeter();
}

void Rectangle::SetDimensions(float length, float width) {
	m_length = length;
	m_width = width;
}

void Rectangle::CalculateArea() {
	m_area = m_length * m_width;
}
void Rectangle::CalculatePerimeter() {
	m_perimeter = 2 * (m_length + m_width);
}