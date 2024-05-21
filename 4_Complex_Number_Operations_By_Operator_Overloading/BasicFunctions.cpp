#include "Complex.h"

//Modulus of a complex no.
float Complex::modulus() {
	float mod;
	mod = m_real * m_real + m_img * m_img;
	return mod;
}

//Conjugate of a complex no.
Complex Complex::conjugate() {
	Complex curr;
	curr.m_real = m_real;
	curr.m_img = -1 * m_img;
	return curr;
}