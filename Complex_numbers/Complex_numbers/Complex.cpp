#include "stdafx.h"
#include "Complex.h"

Complex::Complex() :real(0.0), imaginary(0.0) {}

Complex::Complex(double r, double im) : real(r), imaginary(im) {}

Complex::Complex(const Complex& compl)
{
	real = compl.real;
	imaginary = compl.imaginary;
}

void Complex::operator=(const Complex& compl)
{
	real = compl.real;
	imaginary = compl.imaginary;
}

Complex Complex::operator+(const Complex& compl)
{	
	return Complex(real + compl.real, imaginary + compl.imaginary);
}

Complex Complex::operator-(const Complex& compl)
{
	return Complex(real, imaginary) + Complex(-compl.real, -compl.imaginary);
}

Complex Complex::operator/(const Complex& compl)
{
	double denominator = compl.real*compl.real + compl.imaginary*compl.imaginary;
	
	if (denominator)
	{
		Complex temp;
		temp.real = (real*compl.real + imaginary*compl.imaginary) / denominator;
		temp.imaginary = (imaginary*compl.real - real*compl.imaginary) / denominator;
		return temp;
	}
	else 
	{
		std::cout << "Error! Division by 0 " << std::endl;
		return compl;
	}
}

Complex Complex::operator*(const Complex& compl)
{
	return Complex(real*compl.real - imaginary*compl.imaginary, imaginary*compl.real + real*compl.imaginary);
}

std::ostream& operator<<(std::ostream& os, Complex& compl)
{
	return os << compl.real << " + " << compl.imaginary << "*i" << std::endl;
 }

std::istream& operator<<(std::istream& is, Complex& compl)
{
	std::cout << "\nEnter real part : ";
	is >> compl.real;
	std::cout << "\nEnter imaginary part : ";
	is >> compl.imaginary;
	return is;
}

Complex::~Complex() {}
