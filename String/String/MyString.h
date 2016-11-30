#pragma once
class MyString
{
	char* _s;
	unsigned int _len;
public:
	MyString(unsigned int);
	
	MyString(char*);
	
	MyString(const MyString&);
	
	const char* getString();

	char& operator[](unsigned int);
	
	bool operator<(const MyString&) const;

	bool operator>(const MyString&) const;

	bool operator==(const MyString&) const;

    const MyString operator+(const MyString&);

	void operator+=(const MyString&);

	void operator=(const MyString&);

	unsigned int getLen();

	friend std::ostream& operator<<(std::ostream& os, const MyString& st)
	{
		return os << st._s;
	}

	friend std::istream& operator>>(std::istream& is, const MyString& st)
	{
		std::cout << "Enter string : ";
		is.getline(st._s, 80);
		return is;
	}
	~MyString();
};

