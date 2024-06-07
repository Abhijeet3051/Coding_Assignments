#include <iostream>
#include "Complex.h"

using namespace std;

istream& operator >>(istream& in, Complex& c) {
	float real, img;
	cout << "Real part: ";
	in >> real;
	cout << "Imaginary part: ";
	in >> img;
	c.SetReal(real);
	c.SetImg(img);
	return in;
}

ostream& operator <<(ostream& out, const Complex& c) {
	if (c.GetImg() >= 0) {
		out << c.GetReal() << "+" << c.GetImg() << "i";
	}
	else {
		out << c.GetReal() << c.GetImg() << "i";
	}
	return out;
}