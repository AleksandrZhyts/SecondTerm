// Dlluse.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "windows.h"
#include <iostream>
using namespace std;

typedef int(*FuncPtr)(int, int);

int main()
{
	std::cout << "Inpuy DLL path : ";
	char path[200];
	std::cin >> path;

	HMODULE dll = LoadLibraryA(path);

	if (dll == NULL)
	{
		std::cout << "Error! Failed load library: \n" << path << std::endl;
		return 1;
	}


	FuncPtr add_addr = (FuncPtr)GetProcAddress(dll, "Add");
	FuncPtr sub_addr = (FuncPtr)GetProcAddress(dll, "Sub");
    
	if (add_addr == NULL || sub_addr == NULL)
	{
		std::cout << "Error! Failed to get function address: \n" << std::endl;
		return 1;
	}
	int add_res = add_addr(3, 5);
	int sub_res = sub_addr(122,-213);

	cout << "add_res = " << add_res << endl;
	cout << "sub_res = " << sub_res << endl;

	return 0;
}

