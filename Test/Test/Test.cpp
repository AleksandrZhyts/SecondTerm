// Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


using namespace std;
/*
typedef int(*intMax)(int, int);
typedef double(*doubleMin)(double, double);

int Max(int a, int b) {
return a>b ? a : b;
}
double Min(double a, double b) {
return a>b ? b : a;
}

int main() {
void * ptr;
void * ptr2;

(intMax&)ptr = Max;
(doubleMin&)ptr2 = Min;

cout << ((intMax)ptr)(1, 2) << " " << ((doubleMin)ptr2)(1.1, 2.1);
return 0;
}
*/
/*
int Summa(int a, int b) {
return a + b;
}

int Mult(int a, int b) {
return a * b;
}

int Action(int a, int b, int ch, int(*ptr)(int, int)) {

return ch == 1 ? ptr(a, b) : ptr(a, b);
}
int main() {

cout << Action(3, 4, 2, Summa);

return 0;
}
*/
/*
void Create2D(int ***arr, int rows, int cols) {
*arr = new int*[rows];
for (int i = 0; i < rows; i++)
(*arr)[i] = new int[cols];

}

void Show2D(int **arr, int rows, int cols) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
cout << arr[i][j];
}
cout << endl;
}
}

void Clean2D(int **arr, int rows) {
for (int i = 0; i < rows; i++) {
delete[]arr[i];
}

delete[]arr;
}
int main() {
int ** arr;
const int rows = 2;
const int cols = 2;

Create2D(&arr, rows, cols);

for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
arr[i][j] = 8;
}
}

Show2D(arr, rows, cols);
Clean2D(arr, rows);

return 0;
}
*/
/*
int** Create2D(int rows, int cols) {
int **arr = new int*[rows];

for (int i = 0; i < rows; i++)
arr[i] = new int[cols];

return arr;
}

void Clean2D(int **arr, int rows) {
for (int i = 0; i < rows; i++) {
delete[]arr[i];
}

delete[]arr;
}

int main() {

const int rows = 3;
const int cols = 4;

void ** ptr = (void**)Create2D(rows, cols);
((int**)ptr)[0][0] = 1;
((int**)ptr)[1][0] = 2;

int **matr = (int**)ptr;
cout << ((int**)ptr)[1][0] << " " << matr[1][0];

Clean2D(matr, rows);
return 0;
}
*/

/*
class A {
int *a;
public:
A(int x)
{
a = new int(x);
cout << "A(" << x << ")\n";
}
A(const A &a1)
{
cout << "A(const A" << "&a1)\n";
a = new int(*(a1.a));
}
~A()
{
delete a;
cout << "~A()\n";
}
};
A f()
{
A a1(123);
return a1;
}
void main() {
f();

_getch();
}
*/

struct p
{
	int x;
	int y;
}  point[3];

void calculate(p point[], double &per, double &s)
{
	double a, b;
	a = sqrt(pow(abs(point[0].x - point[1].x), 2) + pow(abs(point[0].y - point[1].y), 2));
	b = sqrt(pow(abs(point[1].x - point[2].x), 2) + pow(abs(point[1].y - point[2].y), 2));
	per = (2 * a + 2 * b);
	s = a*b;
}

struct stack
{
	int a;
	stack * ptr;
};

class queue
{
private:
		stack *next;
public:
	queue() { next = NULL; }
	
	void push(int n)
	{
		stack *st = new stack;
		st->a = n;
		st->ptr = next;
		next = st;
	}
	
	void push2(int n)
	{
		stack *st = new stack;
		st->a = n;
		st->ptr = NULL;

		if (!next)
		{
			next = st;
			return;
		}
		stack *tmp = next;
		while (tmp->ptr != NULL) tmp = tmp->ptr;
		tmp->ptr = st;
	}

	int pop2()
	{
		if (!next) return false;
		int tmp = next->a;
		stack *st = next;
		next = next->ptr;
		delete st;
		return tmp;
	}

	int pop()
	{
		if (!next) return false;
		int tmp = next->a;
		stack *st = next;
		next = next->ptr;
		delete st;
		return tmp;	
	}
};

class container
{
private:
	int *mas;
	int size;
	int curent;
	int min;
public:
	
	container(int n = 0)
	{ 
		if (!n)
		{
			mas = NULL; 
			size = 0;
			curent = 0;
			min = 0;
		}
		else
		{
			mas = new int[n];
			size = n;
			curent = 0;
			min = 0;
		}
	}

	void set(int a)
	{
		if (curent < size) mas[curent++] = a;
	}

	int get()
	{
		if (curent >= 0) return mas[--curent];
	}

	int get2()
	{
		if (min <= curent ) return mas[min++];
	}
	void resize()
	{
		curent = min;
		min = 0;
	}

	bool Is_Empty()
	{
		return (curent == 0);
	}
	bool Is_Empty2()
	{
		return (curent == min);
	}

	bool Is_Full()
	{
		return (curent == size);
	}

	~container()
	{
		delete mas;
	}

};


int  main()
{
	/*
	char name_file[16];
	cout << "Enter name of file to record " << endl;
	cin >> name_file;

	ofstream fout;
	fout.open(name_file);   //, ios::app
	
	ifstream fin;
	fin.open(name_file);

	for (int i(0); i < 3; i++)
	{
		cout << "Enter "
			<< i + 1
			<< " coordinates x and y: ";

		fout << point[i].x
			<< point[i].y;
		
		cin >> point[i].x
			>> point[i].y;

		fin >> point[i].x
			>> point[i].y;
	}

	double per, s;

	calculate(point, per, s);

	char name_file2[16];

	ofstream fout2;
	cout << "Enter name of file to record " << endl;

	cin >> name_file2;
	fout2.open(name_file2, ios::app);

	fout2 << "Perimetr = "
		<< per
		<< endl;

	cout << "Perimetr = "
		<< per
		<< endl;

	fout2 << "Area = "
		<< s
		<< endl;
	
	cout << "Area = "
		<< s
		<< endl;
*/
	/*
	queue q;
	for (int i(0); i < 6; i++)
	{
		q.push(i + 1);
	}
	
	for (int i(0); i < 6; i++)
	{
		cout << q.pop() << endl;
	}
	
	for (int i(0); i < 6; i++)
	{
		q.push2(i + 1);
	}

	for (int i(0); i < 6; i++)
	{
		cout << q.pop2() << endl;
	}
	*/

	container mas(6);
	for (int i(0); !mas.Is_Full(); i++)
	{
		mas.set(i + 1);
	}
	
	for (int i(0); !mas.Is_Empty(); i++)
	{
		cout << mas.get() << endl;
	}

	for (int i(0); !mas.Is_Empty2(); i++)
	{
		cout << mas.get2() << endl;
	}

	_getch();
	return 0;
}