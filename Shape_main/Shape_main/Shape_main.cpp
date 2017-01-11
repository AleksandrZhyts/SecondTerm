#include "stdafx.h"
#include "shape.h"

int main()
{
	shape *shapes[4] = { new square(1, 5, 3.3f),
						 new rectangle(2, 4, 3.5f, 5),
						 new circle(5 ,5, 3.4f),
						 new ellipse(2, 5, 3, 6.4f) };

	
	shape *shapes_copy[4];
	
	for (int i = 0; i < 4; i++)
		shapes_copy[i] = shapes[i];
	
	for (int i = 0; i < 4; i++)
	{
		shapes_copy[i]->Show();
		shapes_copy[i]->Save();
		shapes_copy[i]->Show();
	}
	
	for (int i = 0; i < 4; i++)
		shapes_copy[i]->~shape();
	
	return 0;
}

