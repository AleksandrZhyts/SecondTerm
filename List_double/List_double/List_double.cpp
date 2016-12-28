#include "stdafx.h"
#include "List_2.h"

int main()
{
	List_2 <int> L1,L2;
	const int n = 10;
	int a[n] = { 0,1,2,3,4,5,6,7,8,9 },
	    b[n] = { 3,4,5,6,7,8,9,10,11,12};  
	
	for (int i = 0; i < n; i++)
		L1.AddHead(a[i]);
		
	cout << "List L1:\n";
	L1.Print();
		
	for (int i = 0; i < n; i++)
		L2.AddHead(b[i]);

	cout << "\n\nList L2:\n";
	L2.Print();
	
	List_2 <int> Sum;
	Sum = L1 + L2;
	cout << "\n\nList Sum:\n";
	Sum.Print();

	List_2 <int> Mul;
	Mul = L1 * L2;
	cout << "\n\nList intersection:\n";
	Mul.Print();
	
	cout << "\n\nL1 is working like queue:\n";
	
	for (int i = 0; L1.GetCount(); i++)
		cout << L1.Pop() << " ";
	cout << "\n\n";
	
	return 0;
}

