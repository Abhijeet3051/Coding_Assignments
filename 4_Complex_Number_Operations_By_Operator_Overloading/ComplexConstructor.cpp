#include "Complex.h"

//default constructor
Complex::Complex() {
	m_real = 0;
	m_img = 0;
}

//parameterised constructor
Complex::Complex(float real, float img) {
	m_real = real;
	m_img = img;
}