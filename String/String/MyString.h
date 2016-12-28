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

	bool bracket_location(); //ќпредел€ет правильное расположение скобок

	friend std::ostream& operator<<(std::ostream&, const MyString&);
	
	friend std::istream& operator>>(std::istream&, const MyString&);
	
	~MyString();
};

