#include "stdafx.h"
#include "DB_GAI.h"

using namespace std;

DB_GAI::DB_GAI()
{
	root = NULL;
}

DB_GAI::~DB_GAI()
{
	Del();
}

void DB_GAI::Print_to_File(char* name, char* _shtraf)
{
	/*
	ofstream fout;
	fout.open(name, ios::app);
	fout << _shtraf << endl;
	*/

	FILE * f;

	if (fopen_s(&f, name, "a"))
	{
		perror("Open");
		return;
	}
	fputs(_shtraf, f);
	fputs("\n", f);
	fclose(f);
}

void DB_GAI::Print_to_Screen(char* name)
{
	FILE * f;

	if (fopen_s(&f, name, "r"))  
	{
		cout << "This car doesn't have shtrafs !\n";
		return;
	}

	char s[100] = { 0 };

	while (!feof(f))
	{
		fgets(s, 100, f);
		cout << s << endl;
	}
	std::cout << "\n\n";
	fclose(f);
}

//������ �� ���������� ����
void DB_GAI::Print(Elem * Node)
{
	Elem* Left = Node->left;
	Elem*  Right = Node->right;

	if (Left) Print(Left);
	if (Right) Print(Right);
	
	cout << Node->car.number << endl;
	Print_to_Screen(Node->car.number);
}

//����� �� ���������� ����
Elem* DB_GAI::Search(Elem * Node, char * key)
{
	while (Node != 0 && strcmp(key, Node->car.number) != 0)
	{
		if (strcmp(key, Node->car.number) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	return Node;
}

//min �� ���������� ����
Elem* DB_GAI::Min(Elem * Node)
{
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}

//max �� ���������� ����
Elem* DB_GAI::Max(Elem * Node)
{
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}

//��������� ��� ���������� ����
Elem* DB_GAI::Next(Elem* Node)
{
	Elem * y = 0;
	if (Node != 0)
	{
		//���� ���� ������ �������
		if (Node->right != 0)
			return Min(Node->right);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node ������
		while (y != 0 && Node == y->right)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

//���������� ��� ���������� ����
Elem* DB_GAI::Previous(Elem * Node)
{
	Elem * y = 0;
	if (Node != 0)
	{
		//���� ���� ����� �������
		if (Node->left != 0)
			return Max(Node->left);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node �����
		while (y != 0 && Node == y->left)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

//������� ����
void DB_GAI::Insert(Elem * z, char* _shtraf)
{
	//�������� ���
	Elem * y = NULL;
	Elem * Node = root;
	//����� �����
	while (Node != 0)
	{
		//������� ��������
		y = Node;
		if (strcmp(z->car.number, Node->car.number) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	//��������� ��������
	z->parent = y;
	if (y == 0) 
		root = z;
	else if (strcmp(z->car.number, y->car.number) < 0)
		y->left = z;
	else if (strcmp(z->car.number, y->car.number) > 0)
		y->right = z;
	
	Print_to_File(z->car.number, _shtraf);
}

//�������� ����� ��� ���������� ����,
//0 - �������� ����� ������
void DB_GAI::Del(Elem * z)
{
	//�������� �����
	if (z != 0)
	{
		Elem * Node, *y;
		//�� 2 �������
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
		if (y->left != 0)
			Node = y->left;
		else
			Node = y->right;
		if (Node != 0)
			Node->parent = y->parent;
		//��������� �������� ����?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//����� �� ��������?
			y->parent->left = Node;
		else
			//������ �� ��������?
			y->parent->right = Node;
		if (y != z)
			//����������� ������ ����
			strcpy_s(z->car.number, strlen(y->car.number) + 1, y->car.number);
		delete y;
	}
	else //�������� ����� ������
		while (root != 0)
			Del(root);
}

//�������� ������
Elem* DB_GAI::GetRoot()
{
	return root;  
}
