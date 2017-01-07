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

//печать от указанного узла
void DB_GAI::Print(Elem * Node)
{
	Elem* Left = Node->left;
	Elem*  Right = Node->right;

	if (Left) Print(Left);
	if (Right) Print(Right);
	
	cout << Node->car.number << endl;
	Print_to_Screen(Node->car.number);
}

//поиск от указанного узла
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

//min от указанного узла
Elem* DB_GAI::Min(Elem * Node)
{
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}

//max от указанного узла
Elem* DB_GAI::Max(Elem * Node)
{
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}

//следующий для указанного узла
Elem* DB_GAI::Next(Elem* Node)
{
	Elem * y = 0;
	if (Node != 0)
	{
		//если есть правый потомок
		if (Node->right != 0)
			return Min(Node->right);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node справа
		while (y != 0 && Node == y->right)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

//предыдущий для указанного узла
Elem* DB_GAI::Previous(Elem * Node)
{
	Elem * y = 0;
	if (Node != 0)
	{
		//если есть левый потомок
		if (Node->left != 0)
			return Max(Node->left);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node слева
		while (y != 0 && Node == y->left)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

//вставка узла
void DB_GAI::Insert(Elem * z, char* _shtraf)
{
	//потомков нет
	Elem * y = NULL;
	Elem * Node = root;
	//поиск места
	while (Node != 0)
	{
		//будущий родитель
		y = Node;
		if (strcmp(z->car.number, Node->car.number) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	//заполняем родителя
	z->parent = y;
	if (y == 0) 
		root = z;
	else if (strcmp(z->car.number, y->car.number) < 0)
		y->left = z;
	else if (strcmp(z->car.number, y->car.number) > 0)
		y->right = z;
	
	Print_to_File(z->car.number, _shtraf);
}

//удаление ветки для указанного узла,
//0 - удаление всего дерева
void DB_GAI::Del(Elem * z)
{
	//удаление куста
	if (z != 0)
	{
		Elem * Node, *y;
		//не 2 ребенка
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
		//Удаляется корневой узел?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//слева от родителя?
			y->parent->left = Node;
		else
			//справа от родителя?
			y->parent->right = Node;
		if (y != z)
			//Копирование данных узла
			strcpy_s(z->car.number, strlen(y->car.number) + 1, y->car.number);
		delete y;
	}
	else //удаление всего дерева
		while (root != 0)
			Del(root);
}

//получить корень
Elem* DB_GAI::GetRoot()
{
	return root;  
}
