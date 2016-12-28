#include "stdafx.h"
#include "Station.h"

Station::Station()
{
	_station = first;
	arr_time_people[24] = {1};
	arr_time_bus[24] = {1};
}

Station::Station(int t0, int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8, int t9, int t10, int t11, int t12,
		         int t13, int t14, int t15, int t16, int t17, int t18, int t19, int t20, int t21, int t22, int t23, type_station station)
{
	_station = station;
	
	int *ptr = &t0;
	
	for (int i(0); i < 24; i++)
	{
		arr_time_people[i] = *(ptr++);
		arr_time_bus[i] = (arr_time_people[i] * (rand() % 15) / 60) % 120;   //15 - max число мест в маршрутке;	
																			//%120 - вз€то произвольно дл€ ночного времени
	}
	
	ptr = NULL;
}

void Station::find_goodtime(int hour, int N_people)
{
	int all_people = 0,
		transported_people = 0,
		waiting_people = 0,
		time_minibus = arr_time_bus[hour],
		average_time_waiting = 0;

	all_people = 60 * 60 / arr_time_people[hour];

	transported_people = (rand() % 15) * 60 / time_minibus;

	waiting_people = all_people - transported_people;

	while (waiting_people < 0 || waiting_people > N_people)
	{
		if (waiting_people < 0) time_minibus += 1;
		if (waiting_people > N_people) time_minibus -= 1;

		transported_people = (rand() % 15) * 60 / time_minibus;
		waiting_people = all_people - transported_people;
	}

	average_time_waiting = (N_people / (rand() % 15) + 1) * time_minibus / 2;

	std::cout << "—реднее врем€ ожидани€ на остановке с "
			  << hour
			  << " до "
		      << hour + 1
		      << " составл€ет : "
		      << average_time_waiting % 120
		      << " минут\n\n";
		     
	std::cout << "ƒостаточный интервал времени м/у маршрутками : "
			  << time_minibus % 120
		      << " минут\n\n";
}

void Station::setTime_bus(int hour, int time)
{
	arr_time_bus[hour] = time;
}

int Station::getTime_bus(int hour)
{
	return arr_time_bus[hour];
}

void Station::setTime_people(int hour, int time)
{
	arr_time_people[hour] = time;
}

int Station::getTime_people(int hour)
{
	return arr_time_people[hour];
}

Station::~Station(){}
