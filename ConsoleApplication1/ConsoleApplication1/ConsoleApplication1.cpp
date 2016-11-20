#include "stdafx.h"

using namespace std;

typedef unsigned int ui;

class fract
{
private:
	int numerator;
	ui denominator;
	int GSD(int a, int b) const
	{
		if (a < 0)
			a *= -1;
		while (b)
		{
			a %= b;
			swap(a, b);
		}
		return a;
	}

	int LCM(int a, int b) const
	{
		return a*b / GSD(a, b);
	}

	void Sokrashenie()
	{
		int nod = GSD(numerator, denominator);
		numerator /= nod;
		denominator /= nod;
	}
public:
	fract() : numerator(0), denominator(1) {};

	fract(int x, int y)
	{
		if (y)
		{
			numerator = x;
			denominator = y;
			Sokrashenie();
		}
		else
		{
			cout << "Error! Denominator shouldn't equal 0 .";
			fract();
		}
	}

	fract(const fract& fr)
	{
		numerator = fr.numerator;
		denominator = fr.denominator;
	}

	double Result()
	{
		return (double)numerator / (double)denominator;
	}

	fract operator+(fract& d1) const
	{
		fract result;
		if (denominator == d1.denominator)
		{
			result.denominator = denominator;
			result.numerator = numerator + d1.numerator;
			result.Sokrashenie();
			return result;
		}
		int lcm = LCM(denominator, d1.denominator);
		int x = lcm / denominator;
		int y = lcm / d1.denominator;
		result.denominator = lcm;
		result.numerator = numerator*x + d1.numerator*y;
		result.Sokrashenie();
		return result;
	}

	fract operator*(fract& d1) const
	{
		return fract(numerator*d1.numerator, denominator*d1.denominator);
	}

	fract operator-(fract& d1) const
	{
		return fract(numerator, denominator) + fract(-d1.numerator, d1.denominator);
	}

	fract operator/(fract& d1) const
	{
		return fract(numerator*d1.denominator, denominator*d1.numerator);
	}

	friend std::ostream& operator<<(std::ostream& os, fract& d1)
	{
		return os << d1.numerator << "\/" << d1.denominator;
	}

	~fract() {};
};

int _tmain(int argc, _TCHAR* argv[])
{
	fract d1(10, 30);
	fract d2(3, 5);

	cout << "\t\t***Fraction***\n";
	cout << "d1: " << d1 << endl;
	cout << "d2: " << d2 << endl << endl;

	cout << "d1+d2 =  " << d1 + d2 << endl;
	cout << "d1-d2 =  " << d1 - d2 << endl;
	cout << "d1*d2 =  " << d1 * d2 << endl;
	cout << "d1/d2 =  " << d1 / d2 << endl;

	_getch();
	return 0;
}

