#pragma once
#include "Flat.h"

class _house
{
	unsigned int number_flats;
	unsigned int number_floors;
	char* address;

public:
	Flat *house;
	
	_house();

	_house(const _house&);

	unsigned int getNumber_flats();

	friend std::istream& operator >> (std::istream& is, _house& h)
	{
		std::cout << "Enter number of flats : ";
		is >> h.number_flats;
		is.get();

		h.house = new Flat[h.number_flats];

		for (unsigned int i(0); i < h.number_flats; i++)
		{
			std::cout << "Enter " << i + 1 << " flats" << std::endl;
			is >> h.house[i];
		}

		std::cout << "Enter number of floors : ";
		is >> h.number_floors;
		is.get();

		std::cout << "Enter address : ";
		h.address = new char[100];
		is.getline(h.address, 99);

		return is;
	}

	friend std::ostream& operator << (std::ostream& os, _house& h)
	{
		std::cout << "****************************" << std::endl;  
		os << "There are " << h.number_flats << " flats in the house\n";

		for (unsigned int i(0); i <  h.number_flats; i++)
		{
			os << h.house[i];
			std::cout << "****************************" << std::endl; 
		}

		os << "Numbers of floors : " << h.number_floors << std::endl;;

		os << "Address : " << h.address << std::endl;

		return os;
	}

	~_house();
};

