#pragma once

namespace Phone_book
{

	typedef unsigned int ui;
		
	class phone_book
	{
		struct record {
			char *fio;
			char *h_phone;
			char *m_phone;
			char *w_phone;
			char *ad_information;
		};
		record *ph_book;
		ui size;
	
	public:
		phone_book();
		
		phone_book(int n);

		phone_book(const phone_book& ph);

		void add_record();
		
		void add_record(char* name, char* h_ph, char* m_ph, char* w_ph, char* ad_inf);
				
		int search_book(char *name);
	
		void del_record(char* fio);
		
		void show_record(ui i);
		
		friend std::istream& operator >> (std::istream& is, phone_book& ph)
		{
			char temp[100];
			for (ui i(0); i < ph.size; i++)
			{
				printf("\n******* %d - record**********\n", i + 1);
				std::cout << "Enter FIO : ";
				gets_s(temp, 99);
				ph.ph_book[i].fio = (char*)malloc(strlen(temp) + 1);
				strcpy_s(ph.ph_book[i].fio, strlen(temp) + 1, temp);

				std::cout << "Enter home phone : ";
				gets_s(temp, 99);
				ph.ph_book[i].h_phone = (char*)malloc(strlen(temp) + 1);
				strcpy_s(ph.ph_book[i].h_phone, strlen(temp) + 1, temp);

				std::cout << "Enter mobile phone : ";
				gets_s(temp, 99);
				ph.ph_book[i].m_phone = (char*)malloc(strlen(temp) + 1);
				strcpy_s(ph.ph_book[i].m_phone, strlen(temp) + 1, temp);

				std::cout << "Enter work phone : ";
				gets_s(temp, 99);
				ph.ph_book[i].w_phone = (char*)malloc(strlen(temp) + 1);
				strcpy_s(ph.ph_book[i].w_phone, strlen(temp) + 1, temp);

				std::cout << "Enter additional information : ";
				gets_s(temp, 99);
				ph.ph_book[i].ad_information = (char*)malloc(strlen(temp) + 1);
				strcpy_s(ph.ph_book[i].ad_information, strlen(temp) + 1, temp);
			}
			return is;
		}

		friend std::ostream& operator << (std::ostream& os, phone_book& ph)
		{
			for (ui i = 0; i < ph.size; i++)
			{
				printf("\n******* %d - record**********\n", i + 1);

				os << "FIO : " << ph.ph_book[i].fio << std::endl;
				os << "Home phone : " << ph.ph_book[i].h_phone << std::endl;
				os << "Mobile phone : " << ph.ph_book[i].m_phone << std::endl;
				os << "Work phone : " << ph.ph_book[i].w_phone << std::endl;
				os << "Additional information : " << ph.ph_book[i].ad_information << std::endl;
			}
			
			return os;
		}
		
		~phone_book();
	};
}

