#include "stdafx.h"
#include "List.h"

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::List(const List & L)
{
	Head = Tail = NULL;
	Count = 0;
	
	Element *temp = L.Head;
	while (temp != 0)
	{
		Add(temp->data);
		temp = temp->Next;
	}
}

List::~List()
{
	DelAll();
}

int List::GetCount()
{
	return Count;
}

void List::Add(char data)
{
	Element * temp = new Element;
	temp->data = data;
	temp->Next = NULL;
	
	if (Head != NULL) 
	{
		Tail->Next = temp;
		Tail = temp;
	}
	else 
	{
		Head = Tail = temp;
	}
	Count++;
}

void List::Del()
{
	Element * temp = Head;
	Head = Head->Next;
	Count--;
	delete temp;
}


void List::Del(int pos)
{
	if (!pos) this->Del();
	else
	{
		Element* temp = Head;

		for (int i(0); i < (pos - 1); i++)
		{
			temp = temp->Next;
		}

		Element* nextval = temp->Next;
		if (nextval->Next)
		{
			Element* nextfromdel = nextval->Next;
			delete nextval;
			temp->Next = nextfromdel;
		}
		else
		{
			delete Tail;
			Tail = temp;
			Tail->Next = NULL;
		}
		Count--;
	}
}

void List::DelAll()
{
	while (Head != 0)
		Del();
	Count = 0;
}

void List::Print()
{
	Element * temp = Head;
	
	while (temp != 0)
	{
		std::cout << temp->data << " ";
		temp = temp->Next;
	}
	std::cout << "\n\n";
}

List& List::operator = (const List & L)
{
	if (this == &L)
		return *this;
	
	this->~List(); 
	
	Element * temp = L.Head;
	
	while (temp != 0)
	{
		Add(temp->data);
		temp = temp->Next;
	}
	return *this;
}

List List::operator + (const List& L)
{
	List Result(*this);
	
	Element * temp = L.Head;
	
	while (temp != 0)
	{
		Result.Add(temp->data);
		temp = temp->Next;
	}
	return Result;
}

List List::operator * (const List& L)
{
	List Result(*this);
	
	Element *temp1 = L.Head,
			*temp2 = Result.Head;
	int pos = 0;
	
	while (temp2)
	{
		while (temp1 && (temp1->data != temp2->data))
			temp1 = temp1->Next;
		
		if (!temp1)
		{
			Result.Del(pos);
			temp2 = Result.Head;
			for (int i(0); i < pos; i++) temp2 = temp2->Next;
		}
		else
		{
			temp2 = temp2->Next;
			pos++;	
		}
		temp1 = L.Head;
	}
	return Result;
}