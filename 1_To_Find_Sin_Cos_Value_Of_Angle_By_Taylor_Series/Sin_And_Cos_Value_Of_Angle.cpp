#include <iostream>

const double pi = 3.14159;
//Below is the taylor series formula for Sin and Cos

// Sin X = (sum from n = 0 to infinity) of [ (-1)^n / (2n+1)! * x^(2n+1) ]
//       = x - (X^3)/3! + (X^5)/5! - ....

// Cos X = (sum from n = 0 to infinity) of [ (-1)^n / (2n)! * x^(2n) ]
//       = 1 - (X^2)/2! + (X^4)/4! - ....


//Function for Conversion of any angle to (-180 to +180) range)
double ConversionToRange(double angle)
{
	if (angle < -180)
	{
		while (angle < -180)

		{
			angle += 360;
		}
	}
	else if (angle > 180)
	{
		while (angle > 180)
		{
			angle -= 360;
		}
	}
	return angle;
}

//Fuction for To Find Factorial
int Factorial(int x)
{
	int fact = 1;
	for (int i = 1; i <= x; i++)
	{
		fact *= i;
	}
	return fact;
}


// Function to Find the power of X
double Power(double x, int index)

{
	double prod = 1;
	for (int i = 1; i <= index; i++)

	{
		prod *= x;
	}
	return prod;
}

//function for precision
double precise(double n)
{
	int prec = 4;
	double mult = Power(10, prec);
	int temp = (int)(n * mult * 10);

	if (temp % 10 < 5)
	{
		temp = temp / 10;
		return temp / mult;
	}
	else
	{
		temp = temp / 10 + 1;
		return temp / mult;
	}
}

// function for sine
double sin(double angle)
{
	//call function of conversion of angle 
	angle = ConversionToRange(angle);

	//since convergence of Taylor series is good between -1 to +1 radiance,
	if (angle > 45)
	{
		return cos(angle - 90);
	}

	else if (angle < -45)
	{
		return -1 * cos(angle + 90);
	}

	//converting theta from degrees to radians
	angle = (angle / 180) * pi;
	double sineValue = 0;

	// Sin X = sum from n = 0 to infinity of [ (-1)^n / (2n+1)! * x^(2n+1) ]
	for (int i = 0; i <= 10; i++) {
		sineValue += Power(-1, i) / Factorial(2 * i + 1) * Power(angle, 2 * i + 1);
	}
	return precise(sineValue);
}


// function for Cosine
double cos(double angle)
{
	//call function of conversion of angle 
	angle = ConversionToRange(angle);

	//since convergence of Taylor series is good between -1 to +1 radiance,
	if (angle > 45)
	{
		return -1 * sin(angle - 90);
	}

	else if (angle < -45)
	{
		return sin(angle + 90);
	}

	//converting theta from degrees to radians
	angle = (angle / 180) * pi;
	double cosValue = 0;

	// Cos X = sum from n = 0 to infinity of [ (-1)^n / (2n)! * x^(2n) ]
	for (int i = 0; i <= 10; i++) {
		cosValue += Power(-1, i) / Factorial(2 * i) * Power(angle, 2 * i);
	}
	return precise(cosValue);
}

int main()
{
	double angle = 0;
	std :: cout << "Enter an angle: " << std :: endl;
	std :: cin >> angle;
	std:: cout << std:: endl;
	std:: cout << "Sin " << angle << "= " << sin(angle) << std:: endl;
	std:: cout << "Cos " << angle << "= " << cos(angle) << std:: endl;
	return 0;
}