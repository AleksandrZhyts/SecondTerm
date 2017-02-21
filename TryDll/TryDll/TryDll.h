#pragma once

#define DECLEXPORT __declspec(dllexport)

extern "C"
{
	DECLEXPORT int Add(int a, int b);

	DECLEXPORT int Sub(int a, int b);

}
