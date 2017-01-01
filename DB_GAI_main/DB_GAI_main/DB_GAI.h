#pragma once

struct Elem
{
	union {
		char number[8];
		struct {
			char lit[2];
			char num[4];
			char reg[1];
		} num_car;
	} car;

	Elem* left = NULL, *right = NULL, *parent = NULL;
};
	
class DB_GAI
{
public:
	DB_GAI();
	
	~DB_GAI();
	
	void Print_to_Screen(char* name);

	//������ �� ���������� ����
	void Print(Elem * Node);
	
	//����� �� ���������� ����
	Elem * Search(Elem * Node, char * key);
	
	//min �� ���������� ����
	Elem * Min(Elem * Node);
	
	//max �� ���������� ����
	Elem * Max(Elem * Node);
	
	//��������� ��� ���������� ����
	Elem * Next(Elem * Node);
	
	//���������� ��� ���������� ����
	Elem * Previous(Elem * Node);
	
	//������� ����
	void Insert(Elem * z, char*);
	
	//�������� ����� ��� ���������� ����,
	//0 - �������� ����� ������
	void Del(Elem * z = 0);
	
	//�������� ������
	Elem * GetRoot();

private:
	Elem* root;
	
	void Print_to_File(char* name, char* _shtraf);
};
