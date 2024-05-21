//Subtraction operation for complex number
#include "Complex.h"

Complex Complex::operator - (Complex& other) {
	Complex curr;
	curr.m_real = m_real - other.m_real;
	curr.m_img = m_img - other.m_img;
	return curr;
}

//subtracting real from complex no.
Complex Complex::operator - (float a) {
	Complex curr;
	curr.m_real = m_real - a;
	curr.m_img = m_img;
	return curr;
}

Complex operator - (float a, Complex& c) {
	return Complex(a, 0) - c;
}