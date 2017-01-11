#pragma once
#include "stdafx.h"

class equals
{
public:
	equals() { std::cout << "\nConstructor equals\n"; };
	
	virtual void roots() = 0;

	virtual ~equals() = 0;

};

equals::~equals() { std::cout << "\nDestructor equals\n"; };

class line_equals :public equals
{
public:	
	line_equals(float a, float b) 
	{
		_a = a;
		_b = b;
		std::cout << "\nConstructor line\n";
	}

	virtual void roots ()
	{
		if (_a)
			std::cout << "\nRoot of the equation  "
			<< _a
			<< "*x + "
			<< _b
			<< " = 0"
			<< " is "
			<< ((-_b / _a) ? -_b / _a : 0)
			<< std::endl;
		else
			std::cout << "\nThis equation doesn't have root\n";
	}

	~line_equals()
	{
		std::cout << "\nDestructor line\n";
	}
private:
	float _a;
	float _b;
};

class quadratic_equals :  public equals
{
public:
	quadratic_equals(float a, float b, float c) 
	{
		_a = a;
		_b = b;
		_c = c;
		std::cout << "\nConstructor quadratic\n";
	}

	virtual void roots()
	{
		if (!_a  && _b)
		{
			std::cout << "\nroot  =  "
					  << (-_c / _b ? -_c / _b : 0)
					  << std::endl;
			return;
		}
		
		float det = _b*_b - 4 * _a*_c;
		
		if (det < 0 || !_a && !_b)	std::cout << "\nThis equation doesn't have root\n";
		else
			if (det > 0) std::cout << "\nroot1 = "
								   << (-_b - sqrt((int)det)) / (2 * _a)
								   << "\nroot2 = "
								   << (-_b + sqrt((int)det)) / (2 * _a)
						           << std::endl;
			else std::cout << "\nroot1 = root2 = "
						   << -_b / (2 * _a)
						   << std::endl;	
	}

	~quadratic_equals()
	{
		std::cout<<"\nDestructor quadratic\n";
	}
private:
	float _a;
	float _b;
	float _c;
};
