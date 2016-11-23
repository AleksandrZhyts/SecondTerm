#include "stdafx.h"
#include "phone_book.h"

using namespace std;
using namespace Phone_book;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	phone_book  ph(1);
	cin >> ph;
	
	//ph.add_record();
	
	ph.add_record("Иванов Иван Иванович", "25-74-26", "678-32-55", "28-63-97", "научный сотрудник");
	ph.add_record("Obama Vladimir Vladimirovich", "31-74-26", "+107(154)678-32-55", "28-63-97", "president");
	
	system("cls");
	
	cout << ph 
		 << endl;
	
	system("pause");
	system("cls");

	// ***Find record use FIO***
	
	int index = ph.search_book("иванов Иван Иванович");
	if (index == -1) printf("\nThis record absent in base \n");
	else 
	{
		cout << "\n record was find\n";
		ph.show_record(index);
	}
	
	system("pause");
	system("cls");

	ph.del_record("Obama Vladimir Vladimirovich");
	
	system("pause");
	system("cls");

	cout << ph
		 << endl;

	_getch();
	return 0;
}

