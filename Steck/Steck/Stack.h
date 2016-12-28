#pragma once

template <class T>
class Stack
{
public:
	class bad_Stack
	{
	private:
		int wrong_index;
	public:
		bad_Stack(int i) 
		{ 
			wrong_index = i; 
		}
		void what()
		{
			cout << "In stack type: "
				 << (typeid(T)).name() 
				 << ", wrong method Pop with index: "
				 << wrong_index << endl;
		}
	};

	Stack(int);

	void Push(T d);
	
	T Pop();
	
	int GetCount();
	
	bool IsEmpty();
	
	bool IsFull();

	void Show();

	~Stack();

private:
	struct _steck
	{
		T key;
		_steck* next;
	};
	
	_steck *head;

	int topIndex;
	int maxSize;
};

template <class T>
Stack<T>::Stack(int size)
{
	head = NULL;
	topIndex = 0;
	maxSize = size;
}

template <class T>
void Stack<T>::Push(T d)
{
	if (IsFull()) maxSize++;
	_steck *pv = new _steck;
	pv->key = d;
	pv->next = head;
	head = pv;
	topIndex++;
}

template <class T>
T Stack<T>::Pop()
{
	if (--topIndex >= 0)
	{
		T element = head->key;
		_steck *pv = head;

		head = head->next;
		delete pv;
		return element;
	}
	else
	{
		//throw "In method Pop Stack is Empty ";
		throw bad_Stack(topIndex);
	}
}

template <class T>
bool Stack<T>::IsEmpty()
{
	return (topIndex <= 0);
}

template <class T>
bool Stack<T>::IsFull()
{
	return (topIndex == maxSize);
}

template <class T>
int Stack<T>::GetCount()
{
	return maxSize;
}

template <class T>
void Stack<T>::Show()
{
	_steck *temp = head;
	for (int i(0); i < topIndex; i++)
	{
		cout << temp->key << endl;
		temp = temp->next;
	}
	
	delete temp;
}

template <class T>
Stack<T>::~Stack() 
{
	delete[] head; 
}


