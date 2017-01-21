#include "stdafx.h"
#include "_directory.h"

using namespace std;

void RussianMessage(char *message)
{
	char rmessage[256];
	CharToOemA(message, rmessage);
	std::cout << rmessage;
}

int RussianMenu()
{
	RussianMessage("\nВведите 1 для поиска по названию\n");
	RussianMessage("Введите 2 для поиска по владельцу\n");
	RussianMessage("Введите 3 для поиска по номеру телефона\n");
	RussianMessage("Введите 4 для поиска по роду деятельности\n");
	RussianMessage("Введите 5 для показа всех записей\n");
	RussianMessage("Введите 6 для добавления записи в файл\n");
	RussianMessage("Введите 7 для выхода\n");

	int choice;
	cin >> choice;
	return choice;
}

int main()
{
	_directory d;

	do {
		switch (RussianMenu())
		{
		case 1: //Поиск по названию
			d.search_record(1);
			break;
		case 2: //Поиск по владельцу
			d.search_record(2);
			break;
		case 3: //Поиск по телефону
			d.search_record(3);
			break;
		case 4: //Поиск по роду деятельности
			d.search_record(4);
			break;
		case 5: //Показ всех записей
			d.ShowFromFile();
			break;
		case 6: //Добавление записи
			d.put();
			d.add();
			break;
		case 7: //Прощание с пользователем
			RussianMessage("До Свидания\n");
			return 0;
		default:
			RussianMessage("Неверный Ввод\n");
		}
	} while (1);
	
	
	return 0;
}


