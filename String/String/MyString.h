#pragma once

class MyString
{
public:
	MyString();
	
	MyString(char*);
	
	MyString(const MyString&);
	
	const char* getString();

	char& operator[](unsigned int);
	
	bool operator<(const MyString&) const;

	bool operator>(const MyString&) const;

	bool operator==(const MyString&) const;

	bool operator!=(const MyString&) const;

    MyString& operator+(const MyString&);

	void operator+=(const MyString&);

	void operator=(const MyString&);

	unsigned int getLen();

	bool bracket_location(); //Определяет правильное расположение скобок

	friend std::ostream& operator<<(std::ostream&, const MyString&);
	
	friend std::istream& operator>>(std::istream&, const MyString&);
	
	~MyString();

private:
	char* _s;
	unsigned int _len;
};

/*
Описать класс «Битовая строка» производный от класса «Строка».
(Строки данного класса могут содержать только символы ‘0’ и ‘1’). 
Если в основе инициализирующей строки
встретятся любые символы, отличные от допустимых, то
«Битовая строка» становится пустой. Содержимое строки
рассматривается как двоичное представление целого числа
со знаковым разрядом. Отрицательные числа хранятся
в дополнительном коде.
Методы:
1) конструктор без параметров;
2) конструктор, принимающий в качестве параметра
C-строку;
3) конструктор копирования;
4) оператор присваивания;
4) деструктор;
5) изменение знака числа (перевод числа в дополнительный код);
8) сложение битовых строк (перегрузить операторы +
и +=);
9) проверка на равенство (==) и на неравенство (!=)
*/

class BitString : public MyString
{
public:
	BitString();

	BitString(char*);

	BitString(const BitString&);

	void change_sign ();

	void operator=(const BitString&);

	BitString& operator+(const BitString&);

	void operator+=(BitString&);

	bool operator==(const BitString&) const;

	bool operator!=(const BitString&) const;

	friend std::ostream& operator<<(std::ostream&, const BitString&);
	
	~BitString();

private:
	char* _s;
	unsigned int _len;
};
	

