#pragma once

struct Element
{
	char* data;
	Element * Next;
};

class List
{
public:
	List();

	List(const List &);

	~List();

	void Add(char*);

	void Del();

	void List::Del(int);

	void DelAll();

	void Print_to_File(char*);

	void Print_to_Screen(char*);

	int GetCount();

private:
	Element * Head;
	Element * Tail;
	int Count;
};

