#include "stdafx.h"
#include "W_F.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char answer[20];

	//Проверка Существует ли файл
	if (_access("d:\\ZhicDz5.txt", 0) == -1)
	{
		cout << "\nУказан неверный путь или название файла\n";
		return 0;
	}
	
	//Проверка на существование файла
	if (_access("d:\\ZhicDz5_copy.txt", 0) == 0)
	{
		cout << "\nТакой Файл уже существует перезаписать его(1 - Да / 2 - Нет) ? \n";
		cin.getline(answer, 20);
		if (!strcmp(answer, "2"))
		{
			cout << "\nОперация отменена\n";
			return 0;
		}
		else if (strcmp(answer, "1")) {
			cout << "\nНеправильный ввод\n";
			return 0;
		}
		if (_access("d:\\ZhicDz5_copy.txt", 02) == -1)
		{
			cout << "\nНет доступа к записи.\n";
			return 0;
		}
	}
	//Копирование файла
	if (!CopyFile("d:\\ZhicDz5.txt", "d:\\ZhicDz5_copy.txt"))
	{
		cout << "\nОшибка при работе с файлом\n";
	}

	return 0;
}