#include "Complex.h"

float Complex::GetReal() {
	return m_real;
}

float Complex::GetImg() {
	return m_img;
}

void Complex::SetReal(float a) {
	m_real = a;
}

void Complex::SetImg(float a) {
	m_img = a;
}