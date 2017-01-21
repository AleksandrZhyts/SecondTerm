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

	bool bracket_location(); //���������� ���������� ������������ ������

	friend std::ostream& operator<<(std::ostream&, const MyString&);
	
	friend std::istream& operator>>(std::istream&, const MyString&);
	
	~MyString();

private:
	char* _s;
	unsigned int _len;
};

/*
������� ����� �������� ������ ����������� �� ������ �������.
(������ ������� ������ ����� ��������� ������ ������� �0� � �1�). 
���� � ������ ���������������� ������
���������� ����� �������, �������� �� ����������, ��
�������� ������ ���������� ������. ���������� ������
��������������� ��� �������� ������������� ������ �����
�� �������� ��������. ������������� ����� ��������
� �������������� ����.
������:
1) ����������� ��� ����������;
2) �����������, ����������� � �������� ���������
C-������;
3) ����������� �����������;
4) �������� ������������;
4) ����������;
5) ��������� ����� ����� (������� ����� � �������������� ���);
8) �������� ������� ����� (����������� ��������� +
� +=);
9) �������� �� ��������� (==) � �� ����������� (!=)
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
	

