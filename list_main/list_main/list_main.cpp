#include "stdafx.h"
#include "List.h"

int main()
{
	List lst1, lst2, lst3, lst4;
	
	char s1[] = "Hellow World!!!";
	char s2[] = "Yellow submarin!";
	
	int len1 = strlen(s1),
		len2 = strlen(s2);

	for (int i = 0; i < len1; i++)
		lst1.Add(s1[i]);

	lst2 = lst1;
	std::cout << "First string :\n\n";
	lst2.Print();
	
	lst1.DelAll();

	for (int i = 0; i < len2; i++)
		lst1.Add(s2[i]);
	
	std::cout << "Second string :\n\n";
	lst1.Print();
	
	lst3 = lst2 * lst1;
	std::cout << "The same elements:\n\n";
	lst3.Print();

	lst4 = lst1 + lst2;
	std::cout << "Concatenation:\n\n";
	lst4.Print();
	
	return 0;
}

