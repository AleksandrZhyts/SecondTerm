// TryDll.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "TryDll.h"


extern "C"
{

	DECLEXPORT int Add(int a, int b)
	{
		return a + b;
	}
	
	DECLEXPORT int Sub(int a, int b)
	{
		return a - b;
	}

}

