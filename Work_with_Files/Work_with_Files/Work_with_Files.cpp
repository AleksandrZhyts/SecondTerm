#include "stdafx.h"
#include "W_F.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char answer[20];

	//�������� ���������� �� ����
	if (_access("d:\\ZhicDz5.txt", 0) == -1)
	{
		cout << "\n������ �������� ���� ��� �������� �����\n";
		return 0;
	}
	
	//�������� �� ������������� �����
	if (_access("d:\\ZhicDz5_copy.txt", 0) == 0)
	{
		cout << "\n����� ���� ��� ���������� ������������ ���(1 - �� / 2 - ���) ? \n";
		cin.getline(answer, 20);
		if (!strcmp(answer, "2"))
		{
			cout << "\n�������� ��������\n";
			return 0;
		}
		else if (strcmp(answer, "1")) {
			cout << "\n������������ ����\n";
			return 0;
		}
		if (_access("d:\\ZhicDz5_copy.txt", 02) == -1)
		{
			cout << "\n��� ������� � ������.\n";
			return 0;
		}
	}
	//����������� �����
	if (!CopyFile("d:\\ZhicDz5.txt", "d:\\ZhicDz5_copy.txt"))
	{
		cout << "\n������ ��� ������ � ������\n";
	}

	return 0;
}