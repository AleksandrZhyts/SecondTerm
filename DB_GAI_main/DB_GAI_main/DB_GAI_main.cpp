#include "stdafx.h"
#include "DB_GAI.h"

using namespace std;

int const CARS = 9;
int const SHTRAFS = 9;

DB_GAI gai;

void reid(char kvitanciya[SHTRAFS][100], char car[CARS][8], int count_police_oficer)
{
	int index;
	
	Elem * temp;
	for (int i(0); i < count_police_oficer; i++)
	{
		temp = new Elem();
		
		index = rand() % CARS;

		strcpy_s(temp->car.number, strlen(car[index]) + 1, car[index]);
		
		gai.Insert(temp, kvitanciya[rand() % SHTRAFS]);
	}
}

int main()
{
	setlocale(LC_ALL, ".1251");
	
	srand((unsigned int)time(0));
	
	char base_shtraf[SHTRAFS][100] =
	{
		"Статья 18.9. Нарушение правил пользования Т.С.",
		"Статья 18.12. Нарушение правил эксплуатации Т.С.",
		"Статья 18.13. Превышение скорости движения Т.С.",
		"Статья 18.14. Невыполнение требований сигналов регулирования дорожного движения",
		"Статья 18.16. Управление Т.С. лицом, находящимся в состоянии опьянения",
		"Статья 18.21. Невыполнение требования об остановке Т.С.",
		"Статья 18.14. Нарушение правил маневрирования либо проезда перекрестков",
		"Статья 18.20. Эксплуатация или допуск к участию в дорожном движении Т.С. без страховки ",
		"Статья 18.21. Невыполнение требования об остановке Т.С."
	};

	char base_car_num[CARS][8] =
	{
		"AA10155",
		"AA15247",
		"AB77247",
		"AB00017",
		"BA33337",
		"BA55247",
		"CA11247",
		"CA45247",
		"CC00247"
	};

	reid(base_shtraf, base_car_num, 10);
	
	//Полная распечатка базы данных
	gai.Print(gai.GetRoot());
	
	//Распечатка данных по заданному номеру;
	int ind = rand() % CARS;
	cout << base_car_num[ind] << endl;
	gai.Print_to_Screen(base_car_num[ind]);
	
	//Распечатка данных по диапазону номеров
	int from = rand() % CARS;
	int to = from + rand() % (CARS - from);
	for (int i(from); i < to; i++)
	{
		cout << base_car_num[i] << endl;
		gai.Print_to_Screen(base_car_num[i]);
	}

	return 0;
}


