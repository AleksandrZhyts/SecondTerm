#pragma once
#include "Flat.h"

class _house
{
	unsigned int number_flats;
	unsigned int number_floors;
	char* address;

public:
	Flat *house;
	
	_house(unsigned int, unsigned int);

	_house(const _house&);

	unsigned int getNumber_flats();

	friend std::istream& operator>>(std::istream&, _house&);

	friend std::ostream& operator<<(std::ostream&, _house&);
	
	~_house();
};

