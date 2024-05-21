#pragma once

class Complex
{
private:
	float m_real, m_img;
public:

	//constructor to initialize complex no.
	Complex();
	Complex(float, float);

	//Get and Set Functions
	float GetReal();
	float GetImg();
	void SetReal(float);
	void SetImg(float);

	//Basic Complex Functions
	float modulus();
	Complex conjugate();

	//Mathematical operations between two complex no.
	Complex operator + (Complex&);
	Complex operator - (Complex&);
	Complex operator * (Complex&);
	Complex operator / (Complex&);


	Complex operator + (float);
	Complex operator - (float);
	Complex operator * (float);
	Complex operator / (float);
};

//Mathematical operations between a real no. and a complex no.
Complex operator + (float, Complex&);
Complex operator - (float, Complex&);
Complex operator * (float, Complex&);
Complex operator / (float, Complex&);