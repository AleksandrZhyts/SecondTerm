#include "stdafx.h"
#include "Flat.h"

Flat::Flat()
{
	roommates = NULL;
	h_phone = NULL;
	number_roommates = 0;
	num_rooms = 0;
	total_space = 0.0;
	living_space = 0.0;
	kitchen_space = 0.0;
	floor = 0;
	//std::cout << "Constructor Flat" << std::endl;
}

Flat::Flat(const Flat& fl)
{
	num_rooms = fl.num_rooms;
	total_space = fl.total_space;
	living_space = fl.living_space;
	kitchen_space = fl.kitchen_space;
	floor = fl.floor;
	
	h_phone = new char[strlen(fl.h_phone) + 1];
	strcpy_s(h_phone, strlen(fl.h_phone) + 1, fl.h_phone);
	
	number_roommates = fl.number_roommates;
	
	roommates = new Man[fl.number_roommates];
	
	for (unsigned int i(0); i < number_roommates; i++)
	{
		roommates[i] = fl.roommates[i];
	}
}

unsigned int Flat::getNumber_roommates()
{
	return number_roommates;
}

void Flat::register_Person()
{
	Man *temp;
	temp = new Man[number_roommates + 1];
	for (unsigned int i(0); i < number_roommates; i++)
	{
		temp[i] = roommates[i];
	}
	std::cin.get();
	std::cin >> temp[number_roommates];
	
	delete[] roommates;

	roommates = new Man[++number_roommates];
	
	for (unsigned int i(0); i < number_roommates; i++)
	{
		roommates[i] = temp[i];
	}

	delete[] temp;
 }

int Flat::search_person(char *name)
{
	unsigned int i = 0;
	while (i < number_roommates)
	{
		if (_stricmp(name, roommates[i].getFio()) == 0) return i;
		else i++;
	}
	return -1;
}

void Flat::check_out_Person(char* name)
{
	int  index = search_person(name);

	if (index == -1) std::cout << "\nThis person doesn't leave in the flat\n";
	else
	{
		std::cout <<" Person was check out\n";
		
		Man *temp = new Man[number_roommates - 1];
		unsigned int i = 0,
			         j = 0;
		while (i < number_roommates)
		{
			if (i == index) i++;
			temp[j++] = roommates[i++];  	
		}
		
		delete[] roommates;

		roommates = new Man[--number_roommates];
		
		for (unsigned int i(0); i < number_roommates; i++)
		{
			roommates[i] = temp[i];
		}
		delete [] temp;
	}
}

void Flat::operator=(const Flat& fl) 
{
	this->~Flat();

	num_rooms = fl.num_rooms;
	total_space = fl.total_space;
	living_space = fl.living_space;
	kitchen_space = fl.kitchen_space;
	floor = fl.floor;

	h_phone = new char[strlen(fl.h_phone) + 1];
	strcpy_s(h_phone, strlen(fl.h_phone) + 1, fl.h_phone);

	number_roommates = fl.number_roommates;

	roommates = new Man[fl.number_roommates];

	for (unsigned int i(0); i < number_roommates; i++)
	{
		roommates[i] = fl.roommates[i];
	}
}

std::istream& operator >> (std::istream& is, Flat& fl)
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

std::ostream& operator << (std::ostream& os, Flat& fl)
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


Flat::~Flat()
{
	delete[] h_phone;
	h_phone = NULL;
	
	delete[] roommates;
	roommates = NULL;
	
	//std::cout << "Destructor flat" << std::endl;
}
