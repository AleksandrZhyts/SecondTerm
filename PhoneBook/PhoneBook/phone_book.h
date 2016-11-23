#pragma once

namespace Phone_book
{

	typedef unsigned int uint;
		
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
		uint size;
	
	public:
			
		phone_book(int n = 0);

		phone_book(const phone_book& ph);

		void add_record();
		
		void add_record(char* name, char* h_ph, char* m_ph, char* w_ph, char* ad_inf);
				
		int search_book(char *name);
	
		void del_record(char* fio);
		
		void show_record(uint i);
		
		friend std::istream& operator >> (std::istream& is, phone_book& ph)
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

		friend std::ostream& operator << (std::ostream& os, phone_book& ph)
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
		
		~phone_book();
	};
}

