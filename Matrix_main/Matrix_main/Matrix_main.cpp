#include "stdafx.h"
#include "Matrix.h"

int main()
{
	Matrix <double> m1(3,3), m2(3,3), m3(3,3);
	m1.init_User();
	m2.init();
	
	cout << "\nm1:\n" << m1;
	cout << "\nm2:\n" << m2;
	
	cout << "m2 / m1 : \n" << m2 / m1;
	
	cout << "m2 * m1 : \n" << m2 * m1;
	
	cout << "m1 + m2 : \n" << m1 + m2;
	
	m3 = m1;
	cout << "m3 - m2 : \n" << m3 - m2;
	
	cout << "Max in m3 : \n" << m3.Max() << endl;
	cout << "Min in m3 : \n" << m3.Min() << endl;

	return 0;
}

