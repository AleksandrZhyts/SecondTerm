/*Задание 2.
Написать программу «Автоматизированная информационная система ЖД вокзала». Система содержит: сведения
об отправлении поездов дальнего следования. Для каждого
поезда указываем: номер, время отправления, станцию назначения. Обеспечить:
•	 Ввод данных в систему;
•	 Вывод информации о всех поездах;
•	 Вывод информации о запрашиваемом поезде;
Использовать контейнерный класс vector.*/
#include "stdafx.h"

using namespace std;

template <class T1, class T2, class T3>
struct source
{
	T1 data1;
	T2 data2;
	T3 data3;

	template <class T1, class T2, class T3>
	friend ostream& operator<<(ostream& os, const source<T1, T2, T3>& s)
	{
		return os << s.data1 << " : " << s.data2 << " : " << s.data3 << endl;
	}
};

void input_data(vector<source<int, string, string>>& dict_real_station)
{
	source <int, string, string> s;
	cout << "\nEnter number train : ";
	cin >> s.data1;
	cin.get();
	cout << "\nEnter departure time : ";
	getline(cin, s.data2);
	cout << "\nEnter station of destination : ";
	getline(cin, s.data3);
	dict_real_station.push_back(s);
}

void show_information(vector<source<int, string, string>>& dict_real_station)
{
	vector<source<int, string, string>>::iterator it = dict_real_station.begin();
	for (; it != dict_real_station.end(); it++)
	{
		cout << *it << endl;
	}
}

int search_train(int key, vector<source<int, string, string>>& dict_real_station)
{
	int count = -1;
	vector<source<int, string, string>>::iterator it = dict_real_station.begin();
	for (; it != dict_real_station.end(); it++)
	{
		++count;
		if (key == it->data1) return count;
	}
	return -1;
}

int main()
{
	vector<source<int, string, string>> dict_real_station;
	dict_real_station.reserve(50);
	
	cout << "Please, select preffer number...\n";
	char ch;
	do {
		cout << "\n1 - Input data\n";
		cout << "2 - Show information\n";
		cout << "3 - Search train\n";
		cout << "0 - Exit\n\n";
		cin >> ch;
		cin.get();

		switch (ch)
		{
		case '1':
			input_data(dict_real_station);
			break;
		case '2':
			show_information(dict_real_station);
			break;
		case '3':
			int number_train;
			cout << "\nEnter number train : ";
			cin >> number_train;
			cin.get();
			
			int index = search_train(number_train, dict_real_station);
			
			if (index != -1) cout << dict_real_station.at(index);
			else cout << "\nTrain with this number is not\n";
			break;
		}
	} while (ch != '0');

	return 0;
}


