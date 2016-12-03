#include "stdafx.h"
#include "Array_reserv_water.h"

Array_reserv_water::Array_reserv_water(unsigned int n = 0)
{
	amount = n;
	arr_water = new Reservoir[n];
	std::cout << "Constructor array \n";
}

Array_reserv_water::Array_reserv_water(const Array_reserv_water& arr)
{
	amount = arr.amount;
	arr_water = new Reservoir[amount];
	for (unsigned int i(0); i < amount; i++)
	{
		arr_water[i] = arr.arr_water[i];
	}
}

Reservoir Array_reserv_water::operator[](unsigned int index)
{
	if (arr_water != NULL && index < amount)
		return arr_water[index];
	if (arr_water == NULL) throw "You can not take the index, string is empty ";
	else throw "Wrong index. More than size string";
}

void Array_reserv_water::add_Reserv(Reservoir& r)
{
	Reservoir *temp = new Reservoir[amount + 1];
	unsigned int s = amount + 1;

	for (unsigned int i(0); i < amount; i++)
	{
		temp[i] = arr_water[i];
	}

	temp[amount] = r;
	
	this->~Array_reserv_water();
	
	amount = s;
	arr_water = temp;
}

int Array_reserv_water::search_reservoir(char *name)
{
	unsigned int i = 0;
	while (i < amount)
	{
		if (_stricmp(name, arr_water[i].getName()) == 0) return i;
		else i++;
	}
	return -1;
}

void Array_reserv_water::del_Reserv(char* _name)
{
	int index = search_reservoir(_name);
	if (index != -1)
	{
		Reservoir *temp = new Reservoir[amount - 1];
		unsigned int s = amount - 1,
				     j = 0;

		for (unsigned int i(0); i < amount; i++)
		{
			if (index == i) ++i;
			temp[j++] = arr_water[i];
		}

		this->~Array_reserv_water();

		amount = s;
		arr_water = temp;
	}
	else std::cout << _name << " absent in our array " << std::endl;
}

std::ostream& operator<<(std::ostream& os, Array_reserv_water& arr)
{
	for (unsigned int i(0); i < arr.amount; i++)
	{
		os << i + 1 << " reservoir :\n";
		os << arr.arr_water[i];
	}
	return os;
}

std::istream& operator >> (std::istream& is, Array_reserv_water& arr)
{
	for (unsigned int i(0); i < arr.amount; i++)
	{
		std::cout << "Enter " << i + 1 << " reservoir :\n";
		is >> arr.arr_water[i];
	}
	return is;
}

Array_reserv_water::~Array_reserv_water()
{
	delete [] arr_water;
	arr_water = NULL;
	std::cout << "Destructor array \n";
}
