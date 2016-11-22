#include "stdafx.h"
#include "phone_book.h"

namespace Phone_book
{
	phone_book::phone_book()
	{
		size = 0;
		ph_book = NULL;
	}

	phone_book::phone_book(int n)
	{
		if (n)
		{
			size = n;
			ph_book = new record[n];
		}
		else phone_book();
	}

	phone_book::phone_book(const phone_book& ph)
	{
		size = ph.size;
		ph_book = new record[size];
		for (ui i(0); i < size; i++)
		{
			ph_book[i] = ph.ph_book[i];
		}
	}

	void phone_book::add_record()
	{
		record *ph = new record[size + 1];

		for (ui i(0); i < size; i++)
		{
			ph[i] = ph_book[i];
		}

		char temp[100];

		printf("\n******* %d - record**********\n", size);

		std::cout << "Enter FIO : ";
		gets_s(temp, 99);
		ph[size].fio = (char*)malloc(strlen(temp) + 1);
		strcpy_s(ph[size].fio, strlen(temp) + 1, temp);

		std::cout << "Enter home phone : ";
		gets_s(temp, 99);
		ph[size].h_phone = (char*)malloc(strlen(temp) + 1);
		strcpy_s(ph[size].h_phone, strlen(temp) + 1, temp);

		std::cout << "Enter home phone : ";
		gets_s(temp, 99);
		ph[size].m_phone = (char*)malloc(strlen(temp) + 1);
		strcpy_s(ph[size].m_phone, strlen(temp) + 1, temp);

		std::cout << "Enter work phone : ";
		gets_s(temp, 99);
		ph[size].w_phone = (char*)malloc(strlen(temp) + 1);
		strcpy_s(ph[size].w_phone, strlen(temp) + 1, temp);

		std::cout << "Enter additional information : ";
		gets_s(temp, 99);
		ph[size].ad_information = (char*)malloc(strlen(temp) + 1);
		strcpy_s(ph[size].ad_information, strlen(temp) + 1, temp);

		ph_book = new record[++size];
		for (ui i(0); i < size; i++)
		{
			ph_book[i] = ph[i];
		}
		delete ph;
	}

	void phone_book::add_record(char* name, char* h_ph, char* m_ph, char* w_ph, char* ad_inf)
	{
		record *ph = new record[size + 1];

		for (ui i(0); i < size; i++)
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
		for (ui i(0); i < size; i++)
		{
			ph_book[i] = ph[i];
		}
		delete ph;
	}

	int phone_book::search_book(char *name)
	{
		bool flag = false;
		ui i = 0;

		while ((!flag) && (i < size)) {
			if (_stricmp(name, ph_book[i].fio) == 0) flag = true;
			else i++;
		}
		if (flag) return i;
		else return -1;
	}

	void phone_book::del_record(char* fio)
	{
		int  index = search_book(fio);

		if (index == -1) std::cout << "\nThis record absent in phonebook already\n";
		else
		{
			printf("\n %d record was delete\n", index + 1);

			record *ph = new record[size - 1];
			ui i = 0,
				j = 0;
			while (i < size)
			{
				ph[j++] = ph_book[i++];
				if (i == index) i++;
			}

			ph_book = new record[--size];
			for (ui i(0); i < size; i++)
			{
				ph_book[i] = ph[i];
			}
			delete ph;
		}
	}

	void phone_book::show_record(ui i)
	{
		printf("\n %d record: \n", i + 1);
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

	phone_book::~phone_book()
	{
		for (ui i(0); i < size; i++)
		{
			free(ph_book[i].fio);
			free(ph_book[i].h_phone);
			free(ph_book[i].m_phone);
			free(ph_book[i].w_phone);
			free(ph_book[i].ad_information);
		}
		delete ph_book;
	}	
}