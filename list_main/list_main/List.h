#pragma once

struct Element
{
	char data;
	Element * Next;
};

class List
{
public:
	List();
	
	List(const List &);

	~List();
	
	void Add(char);

	void Del();

	void List::Del(int);
	
	void DelAll();
	
	void Print();
	
	int GetCount();

	List& operator = (const List&);
	
	List operator + (const List&);

	List operator * (const List&);

private:
	Element * Head;
	Element * Tail;
	int Count;
};
