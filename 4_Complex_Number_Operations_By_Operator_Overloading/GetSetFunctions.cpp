#include "Complex.h"

float Complex::GetReal() const{
	return m_real;
}

float Complex::GetImg()const {
	return m_img;
}

void Complex::SetReal(float a) {
	m_real = a;
}

void Complex::SetImg(float a) {
	m_img = a;
}