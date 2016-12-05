#include "stdafx.h"
#include "Overcoat.h"

Overcoat::Overcoat():price(0.0),clouth(coat) {}

Overcoat::Overcoat(double p, ov_coat cl) : price(p), clouth(cl) {}

Overcoat::Overcoat(const Overcoat& ov)
{
	price = ov.price;
	clouth = ov.clouth;
}

void Overcoat::operator=(const Overcoat& ov)
{
	price = ov.price;
	clouth = ov.clouth;
}

bool Overcoat::operator==(const Overcoat& ov)
{
	return (clouth == ov.clouth);
}

bool Overcoat::operator>(const Overcoat& ov)
{
	return (price > ov.price);
}

void Overcoat::setPrice(double p)
{
	price = p;
}

void Overcoat::setClouth(ov_coat ov_c)
{
	clouth = ov_c;
}

double Overcoat::getPrice()
{
	return price;
}

std::ostream& operator<<(std::ostream& os, Overcoat& cl)
{
	switch (cl.clouth)
	{
		case 0 : os << "coat: ";
			break; 
		case 1 : os << "fur coat: ";
			break;
		case 2 : os << "sheepskin coat: ";
			break;
		case 3 : os << "raincoat: ";
			break;
		case 4 : os << "windbreaker: ";
			break;	
	}
	os << cl.price << " rubles";
	return os;
}

Overcoat::~Overcoat() {}