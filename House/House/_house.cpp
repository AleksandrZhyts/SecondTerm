#include "stdafx.h"
#include "_house.h"


_house::_house(unsigned int floors = 0, unsigned int flats = 0)
{
	number_flats = floors*flats;
	number_floors = floors;
	house = new Flat[number_flats];
	address = NULL;
	std::cout << "Constructor house" << std::endl;
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

std::istream& operator >> (std::istream& is, _house& h)
{
	for (unsigned int i(0); i < h.number_flats; i++)
	{
		std::cout << "Enter " << i + 1 << " flats" << std::endl;
		is >> h.house[i];
	}

	is.get();
	std::cout << "Enter address : ";
	h.address = new char[100];
	is.getline(h.address, 99);

	return is;
}

std::ostream& operator << (std::ostream& os, _house& h)
{
	std::cout << "****************************" << std::endl;
	os << "There are " << h.number_flats << " flats in the house\n";

	for (unsigned int i(0); i < h.number_flats; i++)
	{
		os << h.house[i];
		std::cout << "****************************" << std::endl;
	}

	os << "Numbers of floors : " << h.number_floors << std::endl;;

	os << "Address : " << h.address << std::endl;

	return os;
}

_house::~_house()
{
	delete[] address;
	address = NULL;

	delete[] house;
	house = NULL;

	std::cout << "Destructor house" << std::endl;
}
