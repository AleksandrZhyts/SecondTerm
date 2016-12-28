#pragma once

using namespace std;

template <typename T>
struct Elem
{
	T data;
	Elem *next, 
		 *prev;
};

template <typename T>
class List_2
{
public:
	List_2();
	
	List_2(const List_2&);
	
	~List_2();
	
	int GetCount();
	
	Elem<T>* GetElem(int);
	
	void DelAll();
	
	void Del(int);
	
	void AddTail(T);
	
	void AddHead(T);
	
	void Print();
	
	void Print(int pos);
	
	List_2& operator = (const List_2&);
	
	List_2 operator + (const List_2&);

	List_2 operator * (const List_2&);

	T Pop();
	
private:
	Elem<T> *Head, 
		    *Tail;
	int Count;
};

template <typename T>
List_2<T>::List_2()
{
	Head = Tail = 0;
	Count = 0;
}

template <typename T>
List_2<T>::List_2(const List_2 &L)
{
	Head = Tail = 0;
	Count = 0;
	Elem<T> * temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

template <typename T>
List_2<T>::~List_2()
{
	DelAll();
}

template <typename T>
int List_2<T>::GetCount()
{
	return Count;
}

template <typename T>
Elem<T>* List_2<T>::GetElem(int pos)
{
	Elem<T> *temp = Head;
	
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position !!!\n";
		return 0;
	}
	int i = 1;
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}
	if (temp == 0)
		return 0;
	else
		return temp;
}

template <typename T>
void List_2<T>::DelAll()
{
	while (Count != 0)
		Del(1);
}

template <typename T>
void List_2<T>::Del(int n)
{
	if (n < 0 || n > Count)
	{
		cout << "Incorrect position !!!\n";
		return;
	}

	int i = 1;
	Elem<T> * Del = Head;
	while (i < n)
	{
		Del = Del->next;
		i++;
	}
	Elem<T> * PrevDel = Del->prev;
	Elem<T> * AfterDel = Del->next;

	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;
	if (n == 1)
		Head = AfterDel;
	if (n == Count)
		Tail = PrevDel;
	delete Del;
	Count--;
}

template <typename T>
void List_2<T>::AddHead(T n)
{
	Elem<T> * temp = new Elem<T>;
	temp->prev = 0;
	temp->data = n;
	temp->next = Head;
	if (Head != 0)
		Head->prev = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Head = temp;
	Count++;
}

template <typename T>
void List_2<T>::AddTail(T n)
{
	Elem<T> * temp = new Elem<T>;
	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;
	if (Tail != 0)
		Tail->next = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;
	Count++;
}

template <typename T>
void List_2<T>::Print()
{
	if (Count != 0)
	{
		Elem<T> * temp = Head;
		while (temp != 0)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}

template <typename T>
void List_2<T>::Print(int pos)
{
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position !!!\n";
		return;
	}
	Elem<T> * temp;
	if (pos <= Count / 2)
	{
		temp = Head;
		int i = 1;
		while (i < pos)
		{
			temp = temp->next;
			i++;
		}
	}
	else
	{
		temp = Tail;
		int i = 1;
		while (i <= Count - pos)
		{
			temp = temp->prev;
			i++;
		}
	}
	cout << pos << " element: ";
	cout << temp->data << " ";
}

template <typename T>
List_2<T>& List_2<T>::operator = (const List_2<T> & L)
{
	if (this == &L)
		return *this;
	this->~List_2();
	Elem<T> * temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
	return *this;
}

template <typename T>
List_2<T> List_2<T>::operator + (const List_2<T>& L)
{
	List_2 Result(*this);
	Elem<T> * temp = L.Head;
	while (temp != 0)
	{
		Result.AddTail(temp->data);
		temp = temp->next;
	}
	return Result;
}

template <typename T>
List_2<T> List_2<T>::operator * (const List_2<T>& L)
{
	List_2<T> Result(*this);

	Elem<T> *temp1 = L.Head,
		    *temp2 = Result.Head;
	int pos = 1;

	while (temp2)
	{
		while (temp1 && (temp1->data != temp2->data))
			temp1 = temp1->next;

		if (!temp1)
		{
			Result.Del(pos);
			temp2 = Result.Head;
			for (int i(1); i < pos; i++) temp2 = temp2->next;
		}
		else
		{
			temp2 = temp2->next;
			pos++;
		}
		temp1 = L.Head;
	}
	return Result;
}

//Method queue
template<typename T>
T List_2<T>::Pop()
{
	T temp = Tail->data;
	this->Del(Count);
	return temp;
}


