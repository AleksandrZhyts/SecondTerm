/*
������� ����� Overcoat (������� ������)
����������� ������������� ���������:
1. �������� �� ��������� ����� ������ (�������� ==);
2. �������� ������������ ������ ������� � ������
(�������� =);
3. ��������� �� ���� ���� ������ ������ ���� (��������>).
*/
#include "stdafx.h"
#include "Overcoat.h"

int main()
{
	Overcoat ov1(170.5, raincoat), ov2, ov3(580, fur_coat), ov4;
	ov2.setClouth(raincoat);
	ov2.setPrice(168);
	ov4 = ov3;
	std::cout << ov4 
			  << std::endl;
	std::cout << ov2 
		      << std::endl;
	if (ov1 == ov2)
		if (ov1 > ov2) 
			std::cout << ov1 
			          << " is more expensive than " 
			          << ov2 
			          << std::endl;
		else 
			std::cout << ov2 
			          << " is more expensive than " 
			          << ov1 
			          << std::endl;
	else 
		std::cout << "These overcoats have diferent type\n";

	return 0;
}

