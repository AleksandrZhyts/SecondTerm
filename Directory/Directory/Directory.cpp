#include "stdafx.h"
#include "_directory.h"

using namespace std;

void RussianMessage(char *message)
{
	char rmessage[256];
	CharToOemA(message, rmessage);
	std::cout << rmessage;
}

int RussianMenu()
{
	RussianMessage("\n������� 1 ��� ������ �� ��������\n");
	RussianMessage("������� 2 ��� ������ �� ���������\n");
	RussianMessage("������� 3 ��� ������ �� ������ ��������\n");
	RussianMessage("������� 4 ��� ������ �� ���� ������������\n");
	RussianMessage("������� 5 ��� ������ ���� �������\n");
	RussianMessage("������� 6 ��� ���������� ������ � ����\n");
	RussianMessage("������� 7 ��� ������\n");

	int choice;
	cin >> choice;
	return choice;
}

int main()
{
	_directory d;

	do {
		switch (RussianMenu())
		{
		case 1: //����� �� ��������
			d.search_record(1);
			break;
		case 2: //����� �� ���������
			d.search_record(2);
			break;
		case 3: //����� �� ��������
			d.search_record(3);
			break;
		case 4: //����� �� ���� ������������
			d.search_record(4);
			break;
		case 5: //����� ���� �������
			d.ShowFromFile();
			break;
		case 6: //���������� ������
			d.put();
			d.add();
			break;
		case 7: //�������� � �������������
			RussianMessage("�� ��������\n");
			return 0;
		default:
			RussianMessage("�������� ����\n");
		}
	} while (1);
	
	
	return 0;
}


