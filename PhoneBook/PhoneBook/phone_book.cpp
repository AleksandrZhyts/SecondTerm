#include "stdafx.h"
#include "phone_book.h"

namespace Phone_book
{
	phone_book::phone_book(int n)
	{
		size = n;
		if (n) ph_book = new record[n];
		else ph_book = NULL;
	}

	phone_book::phone_book(const phone_book& ph)
	{
		size = ph.size;
		ph_book = new record[size];
		for (uint i(0); i < size; i++)
		{
			ph_book[i] = ph.ph_book[i];
		}
	}

	void phone_book::add_record()
	{
		record *ph = new record[size + 1];

		for (uint i(0); i < size; i++)
		{
			ph[i] = ph_book[i];
		}

		char temp[100];

		std::cout << "\n******* " << size << " - record**********\n";

		std::cout << "Enter FIO : ";
		std::cin.getline(temp, 99);
		ph[size].fio = (char*)malloc(strlen(temp) + 1);
		strcpy_s(ph[size].fio, strlen(temp) + 1, temp);

		std::cout << "Enter home phone : ";
		std::cin.getline(temp, 99);
		ph[size].h_phone = (char*)malloc(strlen(temp) + 1);
		strcpy_s(ph[size].h_phone, strlen(temp) + 1, temp);

		std::cout << "Enter home phone : ";
		std::cin.getline(temp, 99);
		ph[size].m_phone = (char*)malloc(strlen(temp) + 1);
		strcpy_s(ph[size].m_phone, strlen(temp) + 1, temp);

		std::cout << "Enter work phone : ";
		std::cin.getline(temp, 99);
		ph[size].w_phone = (char*)malloc(strlen(temp) + 1);
		strcpy_s(ph[size].w_phone, strlen(temp) + 1, temp);

		std::cout << "Enter additional information : ";
		std::cin.getline(temp, 99);
		ph[size].ad_information = (char*)malloc(strlen(temp) + 1);
		strcpy_s(ph[size].ad_information, strlen(temp) + 1, temp);

		ph_book = new record[++size];
		for (uint i(0); i < size; i++)
		{
			ph_book[i] = ph[i];
		}
		delete ph;
	}

	void phone_book::add_record(char* name, char* h_ph, char* m_ph, char* w_ph, char* ad_inf)
	{
		record *ph = new record[size + 1];

		for (uint i(0); i < size; i++)
		{
			ph[i] = ph_book[i];
		}

		ph[size].fio = (char*)malloc(strlen(name) + 1);
		strcpy_s(ph[size].fio, strlen(name) + 1, name);

		ph[size].h_phone = (char*)malloc(strlen(h_ph) + 1);
		strcpy_s(ph[size].h_phone, strlen(h_ph) + 1, h_ph);

		ph[size].m_phone = (char*)malloc(strlen(m_ph) + 1);
		strcpy_s(ph[size].m_phone, strlen(m_ph) + 1, m_ph);

		ph[size].w_phone = (char*)malloc(strlen(w_ph) + 1);
		strcpy_s(ph[size].w_phone, strlen(w_ph) + 1, w_ph);

		ph[size].ad_information = (char*)malloc(strlen(ad_inf) + 1);
		strcpy_s(ph[size].ad_information, strlen(ad_inf) + 1, ad_inf);

		ph_book = new record[++size];
		for (uint i(0); i < size; i++)
		{
			ph_book[i] = ph[i];
		}
		delete ph;
	}

	int phone_book::search_book(char *name)
	{
		uint i = 0;
		while (i < size) 
		{  
			if (_stricmp(name, ph_book[i].fio) == 0) return i; 
			else i++;
		}
		return -1;
	}

	void phone_book::del_record(char* fio)
	{
		int  index = search_book(fio);

		if (index == -1) std::cout << "\nThis record absent in phonebook already\n";
		else
		{
			std::cout << "\n" << index + 1 << " record was delete\n";

			record *ph = new record[size - 1];
			uint i = 0,
				j = 0;
			while (i < size)
			{
				ph[j++] = ph_book[i++];
				if (i == index) i++;
			}

			ph_book = new record[--size];
			for (uint i(0); i < size; i++)
			{
				ph_book[i] = ph[i];
			}
			delete ph;
		}
	}

	void phone_book::show_record(uint i)
	{
		std::cout << "\n" << i + 1 << " record\n";
		
		std::cout << "FIO : "
				  << ph_book[i].fio
				  << std::endl;
		std::cout << "Home phone : "
				  << ph_book[i].h_phone
				  << std::endl;
		std::cout << "Mobile phone : "
				  << ph_book[i].m_phone
				  << std::endl;
		std::cout << "Work phone : "
				  << ph_book[i].w_phone
				  << std::endl;
		std::cout << "Additional information : "
				  << ph_book[i].ad_information
				  << std::endl;
	}

	std::istream& operator >> (std::istream& is, phone_book& ph)
	{
		char temp[100];
		for (uint i(0); i < ph.size; i++)
		{
			std::cout << "\n******* " << i + 1 << " - record**********\n";
			std::cout << "Enter FIO : ";
			std::cin.getline(temp, 99);

			ph.ph_book[i].fio = (char*)malloc(strlen(temp) + 1);
			strcpy_s(ph.ph_book[i].fio, strlen(temp) + 1, temp);

			std::cout << "Enter home phone : ";
			std::cin.getline(temp, 99);
			ph.ph_book[i].h_phone = (char*)malloc(strlen(temp) + 1);
			strcpy_s(ph.ph_book[i].h_phone, strlen(temp) + 1, temp);

			std::cout << "Enter mobile phone : ";
			std::cin.getline(temp, 99);
			ph.ph_book[i].m_phone = (char*)malloc(strlen(temp) + 1);
			strcpy_s(ph.ph_book[i].m_phone, strlen(temp) + 1, temp);

			std::cout << "Enter work phone : ";
			std::cin.getline(temp, 99);
			ph.ph_book[i].w_phone = (char*)malloc(strlen(temp) + 1);
			strcpy_s(ph.ph_book[i].w_phone, strlen(temp) + 1, temp);

			std::cout << "Enter additional information : ";
			std::cin.getline(temp, 99);
			ph.ph_book[i].ad_information = (char*)malloc(strlen(temp) + 1);
			strcpy_s(ph.ph_book[i].ad_information, strlen(temp) + 1, temp);
		}
		return is;
	}

	std::ostream& operator << (std::ostream& os, phone_book& ph)
	{
		for (uint i = 0; i < ph.size; i++)
		{
			std::cout << "\n******* " << i + 1 << " - record **********\n";

			os << "FIO : " << ph.ph_book[i].fio << std::endl;
			os << "Home phone : " << ph.ph_book[i].h_phone << std::endl;
			os << "Mobile phone : " << ph.ph_book[i].m_phone << std::endl;
			os << "Work phone : " << ph.ph_book[i].w_phone << std::endl;
			os << "Additional information : " << ph.ph_book[i].ad_information << std::endl;
		}

		return os;
	}

	phone_book::~phone_book()
	{
		for (uint i(0); i < size; i++)
		{
			delete ph_book[i].fio;
			delete ph_book[i].h_phone;
			delete ph_book[i].m_phone;
			delete ph_book[i].w_phone;
			delete ph_book[i].ad_information;
		}
		delete ph_book;
	}	
}