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
		
		friend std::istream& operator >> (std::istream&, phone_book&);
	
		friend std::ostream& operator << (std::ostream&, phone_book&);
				
		~phone_book();
	};
}

