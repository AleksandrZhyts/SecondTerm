#pragma once

class Complex
{
	double real;
	double imaginary;

public:
	Complex();
	
	Complex(double, double);
	
	Complex(const Complex&);
	
	void operator=(const Complex&);
	
	Complex operator+(const Complex&);
	
	Complex operator-(const Complex&);
	
	Complex operator/(const Complex&);
	
	Complex operator*(const Complex&);
	
	friend std::ostream& operator<<(std::ostream&, Complex&);
	
	friend std::istream& operator<<(std::istream&, Complex&);
	
	~Complex();
};

