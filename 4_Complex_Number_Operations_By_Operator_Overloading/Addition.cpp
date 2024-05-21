#include "Complex.h"

Complex Complex:: operator + (Complex &other) {
	Complex temp;
	temp.m_real = m_real + other.m_real;
	temp.m_img = m_img + other.m_img;
	return temp;
}

//adding real to complex no.
Complex Complex:: operator + (float a) {
	Complex curr;
	curr.m_real = m_real + a;
	curr.m_img = m_img;
	return curr;
}

//adding real no. to complex
Complex operator + (float a, Complex &c) {
	//return c + Complex(a, 0);
	return Complex(a, 0) + c;
}