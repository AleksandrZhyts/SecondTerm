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
class Array
{
public:
	Array();

	Array(const Array&);

	~Array();

	//количество элементов, под которые выделена пам€ть
	int GetSize();
	
	//установка размера массива
	void SetSize(int size, int grow = 1);
	
	//получение последнего допустимого индекса в массиве
	int GetUpperBound();
	
	bool IsEmpty();

	// удалить Ђлишнююї пам€ть(выше последнего допустимого индекса);
	void FreeExtra();
	
	//удалить все;
	void RemoveAll();

	// Ч получение определенного элемента(по индексу)
	T& GetAt(int);

	//установка нового значени€ дл€ определенного
	//элемента(индекс элемента должен быть меньше текущего размера массива)
	void SetAt(int, T);
	
	Elem<T>* operator [](int);
	
	//добавление элемента в массив(при необходимости массив увеличиваетс€ на значение grow функции SetSize
	void Add(T);

	//сложение двух массивов
	void Append(const Array&);

	Array& operator = (const Array&);

	//получени€ адреса массива с данными
	Array& GetData();

	//вставка элемента(-ов) в заданную позицию;
	void InsertAt(T, int);

	//удаление элемента(-ов) с заданной позиции
	void RemoveAt(int);
	
	void Print();

private:
	Elem<T> *Head,
		    *Tail;
	int _size;
	int _current;
};

template <class T>
Array<T>::Array()
{
	Head = Tail = 0;
	_size = 0;
	_current = 0;
}

template <class T>
Array<T>::Array(const Array &arr)
{
	Head = Tail = 0;
	_size = _current = 0;

	Elem<T> * temp = arr.Head;
	while (temp != 0)
	{
		Add(temp->data);
		temp = temp->next;
	}
}

template <class T>
Array<T>::~Array()
{
	cout << "Destructor\n";
	RemoveAll();
}
 
template<class T>
bool Array<T>::IsEmpty()
{
	return (_current == 0);
}

//количество элементов, под которые выделена пам€ть
template <class T>
int Array<T>::GetSize()
{
	return _size;
}

//установка размера массива
template <class T>
void Array<T>::SetSize(int size, int grow = 1)
{
	if (size < _size) RemoveAt(size + 1);
	else
	{
		int add_size = size - _size + grow;
		
		for (int i(0); i < add_size; i++)
		{
			Elem<T> *temp = new Elem<T>;
			temp->next = 0;
			temp->prev = Tail;

			if (Tail != 0)
				Tail->next = temp;
			if (_size == 0)
				Head = Tail = temp;
			else
				Tail = temp;
			_size++;
		}
	}
}

//получение последнего допустимого индекса в массиве
template <class T>
int Array<T>::GetUpperBound()
{
	return _current;
}

// удалить Ђлишнююї пам€ть(выше последнего допустимого индекса);
template <class T>
void Array<T>::FreeExtra()
{
	RemoveAt(_current+1);
}

//удалить все;
template <class T>
void Array<T>::RemoveAll()
{
	RemoveAt(1);
}

// Ч получение определенного элемента(по индексу)
template <class T>
T& Array<T>::GetAt(int pos)
{
	return operator[](pos)->data;
}

//установка нового значени€ дл€ определенного
//элемента(индекс элемента должен быть меньше текущего размера массива)
template <class T>
void Array<T>::SetAt(int pos, T _data)
{
	if (pos < 1 || pos > _current+1)
	{
		cout << "Incorrect position !!!\n";
		return;
	}
	
	if (pos == _size + 1) SetSize(_size + 1);
		
	if (pos == _current + 1) _current++;

	operator[](pos)->data = _data;	
}

template <class T>
Elem<T>* Array<T>::operator [](int pos)
{
	while (pos < 1 || pos >_current)
	{
		cout << "Incorrect position ! Enter position between " 
			 << 1 
			 << " and " 
			 << _current 
			 << " : ";
		cin >> pos;
	}  
	
	int i = 0;
	Elem<T> * temp = Head;
	
	while (++i < pos)
	{
		temp = temp->next;
	}
	return temp; //temp->data;
}

//добавление элемента в массив(при необходимости массив увеличиваетс€ на значение grow функции SetSize
template <class T>
void Array<T>::Add(T d)
{
	if (_current == _size) SetSize(_size);
	SetAt(++_current, d);
}

//сложение двух массивов
template <class T>
void Array<T>::Append(const Array& arr)
{
	SetSize(_size + arr._size);

	Elem<T> *temp = arr.Head;
	
	int i = _current;

	for (int j(0); j < arr._current; j++)
	{
		SetAt(++i, temp->data);
		temp = temp->next;
	}
}

template <class T>
Array<T>& Array<T>::operator = (const Array<T>& arr)
{
	if (this == &arr)
		return *this;
	
	this->~Array();
	
	Elem<T> * temp = arr.Head;
	
	while (temp != 0)
	{
		Add(temp->data);
		temp = temp->next;
	}
	_current = arr._current;
	return *this;
}

//получени€ адреса массива с данными
template <class T>
Array<T>& Array<T>::GetData()
{
	return *this;
}

//вставка элемента(-ов) в заданную позицию;
template <class T>
void Array<T>::InsertAt(T d, int pos)
{
	if (pos < 1 || pos > _current+1)
	{
		cout << "Incorrect position !!!\n";
		return;
	}
	if (pos == _current + 1)
	{
		Add(d);
		return;
	}
	
	Elem<T> * temp = new Elem<T>;
	temp->data = d;

	if (pos == 1)
	{
		temp->prev = 0;
		temp->next = Head;

		if (Head != 0) Head->prev = temp;
		if (_current == 0)	Head = Tail = temp;
		else Head = temp;
		_current++;
		_size++;
		return;
	}
	
	int i = 0;
	
	Elem<T> * Ins = Head;
	while (++i < pos)
	{
		Ins = Ins->next;
	}
	
	Elem<T> * PrevIns = Ins->prev;
	
	if (PrevIns != 0 && _current != 1)
		PrevIns->next = temp;
	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;

	_current++;
	_size++;
}

//удаление элемента(-ов) с заданной позиции
template <class T>
void Array<T>::RemoveAt(int pos)
{
	if (pos < 1 || pos > _size)
	{
		cout << "Incorect position !!!\n";
		return;
	}
	Elem<T> * Del = Head;
	int i = 0;
	while (++i < pos)
	{
		Del=Del->next;
	}
	Tail = Del->prev;

	while (!Del)
	{
		Elem<T> * PrevDel = Del;
		Del = Del->next;
		delete PrevDel;
	}
	_size = pos - 1;
	if (_current > _size) _current = _size;
}

template <class T>
void Array<T>::Print()
{
	if (_current != 0)
	{
		Elem<T> * Temp = Head;
		int i = 0;
		while (i++ < _current)
		{
			cout << " -> " << Temp->data;
			Temp = Temp->next;
		}
		cout << endl;
	}
}