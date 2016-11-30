#include "stdafx.h"
#include "_house.h"


_house::_house()
{
	number_flats = 0;
	number_floors = 0;
	address = NULL;
	house = new Flat[number_flats];   //NULL
}

_house::_house(const _house& h)
{
	number_floors = h.number_floors;
	
	address = new char[strlen(h.address) + 1];
	strcpy_s(address, strlen(h.address) + 1, h.address);

	number_flats = h.number_flats;

	house = new Flat[h.number_flats];

	for (unsigned int i(0); i < number_flats; i++)
	{
		house[i] = h.house[i];  
	}
}

unsigned int _house::getNumber_flats()
{
	return number_flats;
}

_house::~_house()
{
	delete[] address;
	address = NULL;

	delete[] house;
	house = NULL;

	//std::cout << "Destructor house" << std::endl;
}
