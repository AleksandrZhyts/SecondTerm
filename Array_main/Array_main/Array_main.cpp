#include "stdafx.h"
#include "Array.h"

int main()
{
	Array<int> a1,a2;
	
	a1.SetSize(10);
	a2.SetSize(10);

	for (int i(0); i < 2; i++)
	{
		a1.Add(i + 1);
		a2.SetAt(i + 1, i + 11);
	}
	
	a1.Append(a2);
	a1.SetAt(4, 50);
	
	cout << a1.GetAt(3) << endl;
	
	a1.Print();
	
	a2.Print();
	
	cout << "Size a1 = " << a1.GetSize() << endl;
	cout << "True index a1 = " << a1.GetUpperBound() << endl;
	
	a1.FreeExtra();
	
	cout << "Size a1 = " << a1.GetSize() << endl;
	
	a1.Add(51);
	a1.Print();
	
	cout << "Size a1 = " << a1.GetSize() << endl;
	cout << "True index a1 = " << a1.GetUpperBound() << endl;
	
	a1.SetSize(4);
	a2 = a1;
	
	cout << "Size a2 = " << a2.GetSize() << endl;
	cout << "True index a2 = " << a2.GetUpperBound() << endl;

	a2.InsertAt(99,2);
	
	a2.Print(); 
	a1.Print();
	
	return 0;
}

