#include "stdafx.h"
#include "Reservoir.h"

Reservoir::Reservoir()
{
	name = new char[51];
	type_reservoir = new char [15];
	length = 0.0;
	width = 0.0;
	depth = 0.0;
	//std::cout << "Constructor array \n";
}

Reservoir::Reservoir(char* _name, char* _type, double l, double w, double d)
{
	name = new char[strlen(_name)+1];
	strcpy_s(name, strlen(_name) + 1, _name);
	type_reservoir = new char[strlen(_type) + 1];
	strcpy_s(type_reservoir, strlen(_type) + 1, _type);
	length = l;
	width = w;
	depth = d;
}

Reservoir::Reservoir(const Reservoir& r)
{
	Reservoir r_copy(r.name, r.type_reservoir, r.length, r.width, r.depth);   // так можно ??
}

double Reservoir::water_valume()
{
	return length*width*depth;
}

double Reservoir::water_surface()
{
	return length*width;
}

bool Reservoir::compare_type(const Reservoir& r)  
{
	//Сравнение типов  - море-море или бассейн-пруд правильно ли так или выдавать результатом строку 
	return (_stricmp(type_reservoir, r.type_reservoir) == 0);
}

bool Reservoir::operator<(const Reservoir& r)
{
	//double t2 = r.water_surface();   Как можно вызвать этот метод для r ? Компилятор ругается .
	return ((length * width) < (r.length * r.width));
}

void Reservoir::operator=(const Reservoir& r)
{
	this->~Reservoir();
	
	//Можно ли здесь воспользоваться оператором копирования и как ???
	
	name = new char[strlen(r.name) + 1];
	strcpy_s(name, strlen(r.name) + 1, r.name);
	type_reservoir = new char[strlen(r.type_reservoir) + 1];
	strcpy_s(type_reservoir, strlen(r.type_reservoir) + 1, r.type_reservoir);
	length = r.length;
	width = r.width;
	depth = r.depth;
}

void Reservoir::setName(char* _name)
{
	delete name;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

char* Reservoir::getName()
{
	return name;
}

void Reservoir::setType_reservoir(char* _type)
{
	delete type_reservoir;
	type_reservoir = new char[strlen(_type) + 1];
	strcpy_s(type_reservoir, strlen(_type) + 1, _type);
}

char* Reservoir::getType_reservoir()
{
	return type_reservoir;
}

void Reservoir::setLength(double l)
{
	length = l;
}

double Reservoir::getLength()
{
	return length;
}

void Reservoir::setWidth(double w)
{
	width = w;
}

double Reservoir::getWidth()
{
	return width;
}

void Reservoir::setDepth(double d)
{
	depth = d;
}

double Reservoir::getDepth()
{
	return depth;
}

std::ostream& operator<<(std::ostream& os, Reservoir& r)
{
	os << "Name reservoir: " << r.name << std::endl;
	os << "Type reservoir: " << r.type_reservoir << std::endl;
	os << "length reservoir: " << r.length << std::endl;
	os << "Width reservoir: " << r.width << std::endl;
	os << "Depth reservoir: " << r.depth << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Reservoir& r)
{
	std::cout << "Enter name of reservoir : \n";
	is.getline(r.name, 50);

	std::cout << "Enter type of reservoir : \n";
	is.getline(r.type_reservoir, 14);

	std::cout << "Enter length of reservoir : \n";
	is >> r.length;

	std::cout << "Enter width of reservoir : \n";
	is >> r.width;

	std::cout << "Enter depth of reservoir : \n";
	is >> r.depth;

	is.get();

	return is;
}


Reservoir::~Reservoir()
{
	delete name;
	name = NULL;
	delete type_reservoir;
	type_reservoir = NULL;
	//std::cout << "Destructor reservoir \n";
}
