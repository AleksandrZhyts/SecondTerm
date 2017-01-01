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

	//печать от указанного узла
	void Print(Elem * Node);
	
	//поиск от указанного узла
	Elem * Search(Elem * Node, char * key);
	
	//min от указанного узла
	Elem * Min(Elem * Node);
	
	//max от указанного узла
	Elem * Max(Elem * Node);
	
	//следующий для указанного узла
	Elem * Next(Elem * Node);
	
	//предыдущий для указанного узла
	Elem * Previous(Elem * Node);
	
	//вставка узла
	void Insert(Elem * z, char*);
	
	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(Elem * z = 0);
	
	//получить корень
	Elem * GetRoot();

private:
	Elem* root;
	
	void Print_to_File(char* name, char* _shtraf);
};
