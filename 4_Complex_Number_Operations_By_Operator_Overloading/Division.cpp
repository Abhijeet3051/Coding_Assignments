#include "Complex.h"

//dividing two complex no.
Complex Complex::operator / (Complex& other) {
	Complex curr, complement;
	curr.m_real = (m_real * other.m_real + m_img * other.m_img) / (other.m_real * other.m_real + other.m_img * other.m_img);
	curr.m_img = (m_img * other.m_real - m_real * other.m_img);
	return curr;
}

//division by real
Complex Complex::operator / (float a) {
	Complex curr;
	curr.m_real = m_real / a;
	curr.m_img = m_img / a;
	return curr;
}

Complex operator / (float a, Complex& c) {
	return c.conjugate() / c.modulus() * a;
}