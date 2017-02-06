/*�������
��������� ������ �������� ����� ���������� �� ���������� ������:
1. �������� �����;
2. ��������;
3. �������;
4. �����;
5. ��� ������������.
����������� ��������� �����������:
1. ����� �� ��������;
2. ����� �� ���������;
3. ����� �� ������ ��������;
4. ����� �� ���� ������������;
5. ����� ���� ������� � ����������.
��� ����������, ������ ���������� � �����, ������
���� ����������� ����������� ���������� ����� ������.*/

#pragma once

void RussianMessage(char *message);

class _directory
{
public:
	
	_directory();
	
	_directory(char*, char*, char*, char*, char*, char*);

	void put();

	void search_record(int);

	void add();
	
	void ShowFromFile();
	
	~_directory();
private:
	std::fstream f;
	char *company;
	char *owner;
	char *phone;
	char *address;
	char *occupation;
};

