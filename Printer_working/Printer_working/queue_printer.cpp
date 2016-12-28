#include "stdafx.h"
#include "queue_printer.h"

queue_printer::queue_printer(int m)
{
	MaxQueueLength = m;
		
	Wait_in = new int[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	
	Wait_out = new int[MaxQueueLength];
	time_print = new double[MaxQueueLength];

	min = 0;
	QueueLength = 0;
}

//Добавление документа в очередь 
void queue_printer::Add(int d)
{
	if (!IsFull()) 
	{
		Wait_in[QueueLength] = d;
		Pri[QueueLength] = d;
		
		int max_pri = Pri[QueueLength],
			i = 0;

		if (QueueLength == 0)
		{
			Wait_out[0] = Pri[0];
			time_print[0] = 8.00;   //начало рабочего дня 
		}
		else
		{
			while ((i < QueueLength) && (Wait_out[i] <= max_pri)) i++;
			
			if (i == QueueLength) Wait_out[i] = max_pri;
			else
			{
				int temp1 = Wait_out[i];
				Wait_out[i] = max_pri;
				
				for (int j = QueueLength; j > i + 1; j--) Wait_out[j] = Wait_out[j - 1];
				
				Wait_out[i+1] = temp1;
			}
			time_print[QueueLength] = 8.00 + QueueLength*0.01;
		}
		QueueLength++;
	}
}

//Печать документа
void queue_printer::Extract()
{
	switch (Wait_out[min])
	{
	case 0: std::cout << min << " - manager in " << time_print[min++] << std::endl;
		break;
	case 1: std::cout << min << " - accounting in " << time_print[min++] << std::endl;
		break;
	case 2: std::cout << min << " - retail in " << time_print[min++] << std::endl;
		break;
	case 3: std::cout << min << " - supply in " << time_print[min++] << std::endl;
		break;
	case 4: std::cout << min << " - stock in " << time_print[min++] << std::endl;
		break;
	}

}

void queue_printer::reset()
{
	min = 0;
	QueueLength = 0;
}

bool queue_printer::IsEmpty()
{
	return QueueLength == 0;
}

bool queue_printer::IsFull()
{
	return QueueLength == MaxQueueLength;
}

//Количество элементов в очереди
int queue_printer::GetCount()
{
	return QueueLength;
}

//демонстрация очереди
void queue_printer::Show()
{
	std::cout << "Sent : \n";
	
	for (int i = 0; i < QueueLength; i++)
	{
		switch (Pri[i])
		{
		case 0: std::cout << i + 1 << " - manager \n";
			break;
		case 1: std::cout << i + 1 << " - accounting \n";
			break;
		case 2: std::cout << i + 1 << " - retail \n";
			break;
		case 3: std::cout << i + 1 << " - supply \n";
			break;
		case 4: std::cout << i + 1 << " - stock \n";
			break;
		}
	}
	std::cout << "*********************\n";
}

queue_printer::~queue_printer()
{
	delete[] Wait_in;
	delete[] Pri;
	delete[] Wait_out;
	delete[] time_print;
}
