#pragma once

enum type_station { first = 1, second, third, forth, fivth, end };

class Station
{
	type_station _station;
	
	// массив среднего времени появления пассажиров на остановки для каждого часа в секундах
	int arr_time_people[24];  
	
	// массив среднего времени появления маршруток для каждого часа
	// будет рассчитываться  исходя из среднего времени появления пассажиров 
	int arr_time_bus[24];    
	
public:
	Station();
	
	Station(int, int, int, int, int, int, int, int, int, int, int, int, int,
			int, int, int, int, int, int, int, int, int, int, int, type_station);
	
	void find_goodtime(int, int);
	
	void setTime_bus(int, int);

	int getTime_bus(int);
	
	void setTime_people(int, int);

	int getTime_people(int);

	~Station();
};

