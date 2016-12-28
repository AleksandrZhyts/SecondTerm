#pragma once

enum Department {manager, accounting, retail, supply, stock};

class queue_printer
{
	
	int* Wait_in;
	int* Pri;

	int* Wait_out;
	double* time_print;
	
	int MaxQueueLength;
	int QueueLength;
	int min;

public:
	queue_printer(int m);
	
	//���������� ��������� � �������
	void Add(int d);
	
	//������ ���������
	void Extract();
	
	bool IsEmpty();
	
	bool IsFull();
	
	void reset();

	int GetCount();
	
	void Show();
	
	~queue_printer();
};

