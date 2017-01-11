#include "stdafx.h"
#include "equals.h"

int main()
{
	equals *eq = new line_equals (5, 1);
	eq->roots();
	eq->~equals();

	eq = new quadratic_equals(1, 5, 4);
	eq->roots();
	eq->~equals();

	return 0;
}

