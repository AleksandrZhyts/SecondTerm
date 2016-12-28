#include "stdafx.h"
#include "queue_printer.h"

int main()
{
	srand((unsigned int) time(0));
	
	queue_printer QUP(15);
	
	//���������� ����� ���������
	for (int i = 0; i < 5; i++)
	{
		QUP.Add(rand() % 5);
	}
	
	QUP.Show();

	std::cout << "Printing : \n";
	for (int i = 0; i < 5; i++)
	{
		QUP.Extract();
	}
	
	return 0;
}

