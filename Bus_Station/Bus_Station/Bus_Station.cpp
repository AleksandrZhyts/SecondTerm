#include "stdafx.h"
#include "Station.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Station st(1200, 1800, 2400, 2400, 3000, 1200, 60, 30, 90, 100, 120, 120, 120,
			   120, 120, 120, 60, 30, 30, 30, 90, 90, 120, 600, second);

	int _time = 7,
		N_people = 25;

	st.find_goodtime(_time, N_people);

	return 0;
}

