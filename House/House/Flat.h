#pragma once
#include "Man.h"

class Flat
{
	unsigned int number_roommates;
	char *h_phone;
	unsigned int num_rooms;
	double total_space;
	double living_space;;
	double kitchen_space;
	unsigned int floor;

public:
	Man *roommates;
	
	Flat();
	
	Flat(const Flat&);
	
	void register_Person();
	
	void check_out_Person(char*);
	
	int search_person(char*);
	
	unsigned int getNumber_roommates();

	void operator=(const Flat&);

	friend std::istream& operator >> (std::istream& is, Flat& fl)
	{
		std::cout << "Enter number of roommates : ";
		is >> fl.number_roommates;
		is.get();
		
		fl.roommates = new Man[fl.number_roommates];
		
		for (unsigned int i(0); i < fl.number_roommates; i++)
		{
			std::cout << "Enter " << i + 1 << " members" << std::endl;
			is >> fl.roommates[i];
		}
	
		std::cout << "Enter home phone : ";
		fl.h_phone = new char[13];
		is.getline(fl.h_phone, 12);

		std::cout << "Enter number of rooms : ";
		is >> fl.num_rooms;
		
		std::cout << "Enter total space in the flat : ";
		is >> fl.total_space;

		std::cout << "Enter living space in the flat : ";
		is >> fl.living_space;

		std::cout << "Enter kitchen space in the flat : ";
		is >> fl.kitchen_space;
		
		std::cout << "Enter floor number : ";
		is >> fl.floor;

		return is;
	}

	friend std::ostream& operator << (std::ostream& os, Flat& fl)
	{
		std::cout << "****************************" << std::endl;  
		os << "There are " << fl.number_roommates << " members in the flat\n";
		
		for (unsigned int i(0); i < fl.number_roommates; i++)
		{	
			os << fl.roommates[i];
			std::cout << "****************************" << std::endl; 
		}

		os << "Number of rooms : " << fl.num_rooms << std::endl;;

		os << "Total space : " << fl.total_space << std::endl;

		os << "Living space : " << fl.living_space << std::endl;

		os << "Kitchen space : " << fl.kitchen_space << std::endl;

		os << "Number of floors : " << fl.floor << std::endl;
		
		return os;
	}
	
	~Flat();
};

