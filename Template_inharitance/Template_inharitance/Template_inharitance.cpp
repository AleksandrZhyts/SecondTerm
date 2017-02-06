#include "stdafx.h"

using namespace std;

template<class T1, class T2>
class base
{
public:
	base(T1, T2);

	base(const base<T1, T2>&);

	T1 getValue1();

	T2 getValue2();
	
	void setValue1(T1);

	void setValue2(T2);

	void print();

	~base<T1, T2>();

private:
	T1 value1;
	T2 value2;
};

template<class T1, class T2>
base<T1, T2>::base(T1 v1, T2 v2) : value1(v1), value2(v2) {}

template<class T1, class T2>
base<T1, T2>::base(const base& b)
{
	value1 = b.value1;
	value2 = b.value2;
}

template<class T1, class T2>
T1 base<T1, T2>::getValue1()
{
	return value1;
}

template<class T1, class T2>
T2 base<T1, T2>::getValue2()
{
	return value2;
}

template<class T1, class T2>
void base<T1, T2>::setValue1(T1 t1)
{
	value1 = t1;
}

template<class T1, class T2>
void base<T1, T2>::setValue2(T2 t2)
{
	value2 = t2;
}

template<class T1, class T2>
void base<T1, T2>::print()
{
	cout << "Value1 : " << value1 << "\nValue2 : " << value2 << endl;
}

template<class T1, class T2>
base<T1, T2>::~base()
{
	cout << "\nDestructor base\n";
}
	
template< class T1, class T2, class T3, class T4>
class child : public base<T1,T2> 
{
public:
	child(T1, T2, T3, T4);

	child(const child&);

	T3 getValue3();

	T4 getValue4();

	void setValue3(T3);

	void setValue4(T4);
	
	void print();
	
	~child();

private:
	T3 value3;
	T4 value4;
};

template<class T1, class T2, class T3, class T4>
child<T1, T2, T3, T4>::child(T1 v1, T2 v2, T3 v3, T4 v4) : base<T1, T2>(v1, v2), value3(v3), value4(v4) {}

template<class T1, class T2, class T3, class T4>
child<T1, T2, T3, T4>::child(const child& c)
{
	value3 = c.value3;
	value4 = c.value4;
}

template<class T1, class T2, class T3, class T4>
 T3 child<T1, T2, T3, T4>::getValue3()
{
	 return value3;
}

 template<class T1, class T2, class T3, class T4>
 T4 child<T1, T2, T3, T4>::getValue4()
{
	 return value4;
}

 template<class T1, class T2, class T3, class T4>
 void child<T1, T2, T3, T4>::setValue3(T3 t3)
{
	 value3 = t3;
}

 template<class T1, class T2, class T3, class T4>
 void child<T1, T2, T3, T4>::setValue4(T4 t4)
{
	 value4 = t4;
}

 template<class T1, class T2, class T3, class T4>
 void child<T1, T2, T3, T4>::print()
 {
	 cout << "\n************\n";
	 base<T1, T2>::print();
	 cout << "Value3 : " << value3 << "\nValue4 : " << value4 << endl;
 }

template<class T1, class T2, class T3, class T4>
child<T1, T2, T3, T4>::~child()
{
	cout << "\nDestructor child\n";
}

template< class T1, class T2, class T5, class T6>
class child2 : public base<T1, T2>
{
public:
	child2(T1, T2, T5, T6);

	child2(const child2&);

	T5 getValue5();

	T6 getValue6();

	void setValue5(T5);

	void setValue6(T6);

	void print();

	~child2();

private:
	T5 value5;
	T6 value6;
};

template<class T1, class T2, class T5, class T6>
child2<T1, T2, T5, T6>::child2(T1 v1, T2 v2, T5 v5, T6 v6) : base<T1, T2>(v1, v2), value5(v5), value6(v6) {}

template<class T1, class T2, class T5, class T6>
child2<T1, T2, T5, T6>::child2(const child2& c)
{
	value5 = c.value5;
	value6 = c.value6;
}

template<class T1, class T2, class T5, class T6>
T5 child2<T1, T2, T5, T6>::getValue5()
{
	return value5;
}

template<class T1, class T2, class T5, class T6>
T6 child2<T1, T2, T5, T6>::getValue6()
{
	return value6;
}

template<class T1, class T2, class T5, class T6>
void child2<T1, T2, T5, T6>::setValue5(T5 t5)
{
	value5 = t5;
}

template<class T1, class T2, class T5, class T6>
void child2<T1, T2, T5, T6>::setValue6(T6 t6)
{
	value6 = t6;
}

template<class T1, class T2, class T5, class T6>
void child2<T1, T2, T5, T6>::print()
{
	cout << "\n************\n";
	base<T1,T2>::print();
	cout << "Value5 : " << value5 << "\nValue6 : " << value6 << endl;
}

template<class T1, class T2, class T5, class T6>
child2<T1, T2, T5, T6>::~child2()
{
	cout << "\nDestructor child2\n";
}

template <class T>
struct example
{
	T data;
	
	T operator=(example<T>& ex)
	{
		return data = ex.data;
	}

	friend ostream& operator<<(ostream& os, example<T>& ex)
	{
		return os << ex.data;
	}
};

int main()
{
	example <int>ex1;
	ex1.data = 5;
	example <char>ex2;
	ex2.data = 'b';
	
	base <example<int>, example<char>> b(ex1, ex2);
		
	example <int>ex3;
	ex3 = b.getValue1();
	ex3.data += 15;

	example <char>ex4;
	ex4 = b.getValue2();
	ex4.data++;

	b.print();

	child <int, char, example<int>, example<char>> ch(10, 'a', ex3, ex4);
	
	ch.print();

	child2 <int, char, example<int>, example<char>> ch2(1, 'c', ex1, ex4);

	ch2.setValue5(ch.getValue3());
	ch2.setValue6(b.getValue2());

	ch2.print();

	return 0;
}

