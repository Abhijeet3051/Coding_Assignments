//#include "Complex.h"
#include "ComplexInOut.h"

//using namespace std;

int main() {
	Complex c1, c2;
	float a;
	Complex add, sub, mult, div, int_add, int_sub, int_mult, int_div;
	cout << endl << "Enter first complex no. c1: " << endl;
	cin >> c1;
	cout << endl << "Enter second complex no. c2: " << endl;
	cin >> c2;
	cout << endl << "Enter float a: " << endl;
	cin >> a;

	cout << endl << "c1= " << c1 << " and c2= " << c2 << " and a= " << a << endl;
	cout << endl;

	//modulus
	cout << "|" << c1 << "| = " << c1.modulus() << endl << "|" << c2 << "| = " << c2.modulus() << endl;
	cout << endl;

	//conjugate
	cout << "Conjugate of " << c1 << " = " << c1.conjugate() << endl << "Conjugate of " << c2 << " = " << c2.conjugate() << endl;
	cout << endl;

	//addition
	add = c1 + c2;
	cout << "c1 + c2 = " << add << endl;

	//subtraction
	sub = c1 - c2;
	cout << "c1 - c2 = " << sub << endl;

	//multiplication
	mult = c1 * c2;
	cout << "c1 * c2 = " << mult << endl;

	//division
	div = c1 / c2;
	cout << "c1 / c2 = " << div << endl;

	//addition with a real no.
	cout << "c1 + a = " << c1 + a << endl;
	cout << "a + c1 = " << a + c1 << endl;
	cout << endl;

	//subtraction with real no.
	cout << "c1 - a = " << c1 - a << endl;
	cout << "a - c1 = " << a - c1 << endl;
	cout << endl;

	//multiplication with real no.
	cout << "c1 * a = " << c1 * a << endl;
	cout << "a * c1 = " << a * c1 << endl;
	cout << endl;

	//division with a real no.
	cout << "c1 / a = " << c1 / a << endl;
	cout << "a / c1 = " << a / c1 << endl;
	cout << endl;

	return 0;
}
