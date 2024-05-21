#include "Complex.h"

//multiplying two complex no.
Complex Complex::operator * (Complex& other) {
	Complex curr;
	curr.m_real = m_real * other.m_real - m_img * other.m_img;
	curr.m_img = m_img * other.m_real + other.m_img * m_real;
	return curr;
}

//multiply complex by real
Complex Complex::operator * (float a) {
	Complex curr;
	curr.m_real = a * m_real;
	curr.m_img = a * m_img;
	return curr;
}

Complex operator*(float a, Complex& c) {
	return c * a;
}