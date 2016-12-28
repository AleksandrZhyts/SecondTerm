#include "stdafx.h"
#include "Stack.h"

using namespace std;

int main()
{
	Stack <int>st(4);
	
	for (int i(0); i < 4; i++)
		st.Push(i + 1);
	
	st.Push(5);
	st.Show();
	cout << "**********\n";
		
	int i = 0;
	try
	{
		while (i++ < 7)
		{
			cout << st.Pop() << endl;
		}
	}
/*
	catch (const char* message)
	{
		cout << "Error: " << message << endl;
	}
*/
	catch (int i)
	{
		cout << "Error wrong index in Stack Pop: " << i << endl;
	}
	catch (Stack<int>::bad_Stack a)
	{
		a.what();
	}
	
	return 0;
}

