/*«адание 2.
—оздайте абстрактный класс Shape дл€ рисовани€ плоских
фигур.ќпределите виртуальные методы :
	 Show() Ч вывод на экран информации о фигуре,
Х	 Save() Ч сохранение фигуры в файл,
Х	 Load() Ч считывание фигуры из файла.
ќпределите производные классы:
Х	 Square Ч квадрат, который характеризуетс€ координатами левого верхнего угла и длиной стороны;
Х	 Rectangle Ч пр€моугольник с заданными координатами
верхнего левого угла и размерами;
Х	 Circle Ч окружность с заданными координатами центра и радиусом;
Х	 Ellipse Ч эллипс с заданными координатами верхнего угла описанного вокруг него пр€моугольника со
сторонами, параллельными ос€м координат, и размерами этого пр€моугольника.
—оздайте массив фигур, сохраните фигуры в файл, загрузите в другой массив и отобразите информацию о каждой
из фигур.*/
#pragma once
#include"stdafx.h"

using namespace std;

class shape
{
public:
	shape() {};
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;
	virtual ~shape() = 0;
};

shape::~shape() { cout << "\nDestructor\n"; };

class square : public shape
{
public:
	square(float x, float y, float side)
	{
		_x = x;
		_y = y;
		_side = side;
		_perimetr = 4 * _side;
		_area = _side * _side;
	}

	virtual void Show()
	{
		cout << "\nSquare :\n";
		cout << "Side : " << _side << endl;
		cout << "Perimetr : " <<_perimetr << endl;
		cout << "Area : " << _area << endl;
	}
	
	virtual void Save()
	{
		FILE *f;

		if (fopen_s(&f, "D:\\square.txt", "w"))
		{
			perror("Open");
			return;
		}
				
		char str[20];
        
		fputs("Square :\n", f);
		
		fputs("Side : ", f);
		sprintf_s(str,20, "%f", _side);
		fputs(str, f);

		fputs("\nPerimetr : ", f);
		sprintf_s(str, 20, "%f", _perimetr);
		fputs(str, f);

		fputs("\nArea : ", f);
		sprintf_s(str, 20, "%f", _area);
		fputs(str, f);
		
		fclose(f);
	}
	
	virtual void Load()
	{
		FILE *f;

		if (fopen_s(&f, "D:\\square.txt", "r"))
		{
			perror("Open");
			return;
		}
		char s[200];

		while (!feof(f))
		{
			fgets(s, 200, f);
			cout << s << endl;
		}		
		
		fclose(f);
	}
	
	~square() {}

private:
	float _x;
	float _y;
	float _side;
	float _perimetr;
	float _area;
};

class rectangle : public shape
{
public:
	rectangle(float x, float y, float side1, float side2)
	{
		_x = x;
		_y = y;
		_side1 = side1;
		_side2 = side2;
		_perimetr = 2* _side1 + 2*_side2;
		_area = _side1 * _side2;
	}

	virtual void Show()
	{
		cout << "\nRectangle :\n";
		cout << "First side : " << _side1 << endl;
		cout << "Second side : " << _side2 << endl;
		cout << "Perimetr : " << _perimetr << endl;
		cout << "Area : " << _area << endl;
	}

	virtual void Save()
	{
		FILE *f;

		if (fopen_s(&f, "D:\\rectangle.txt", "w"))
		{
			perror("Open");
			return;
		}

		char str[20];

		fputs("Rectangle :\n", f);

		fputs("First side : ", f);
		sprintf_s(str, 20, "%f", _side1);
		fputs(str, f);

		fputs("\nSecond side : ", f);
		sprintf_s(str, 20, "%f", _side2);
		fputs(str, f);

		fputs("\nPerimetr : ", f);
		sprintf_s(str, 20, "%f", _perimetr);
		fputs(str, f);

		fputs("\nArea : ", f);
		sprintf_s(str, 20, "%f", _area);
		fputs(str, f);

		fclose(f);
	}

	virtual void Load()
	{
		FILE *f;

		if (fopen_s(&f, "D:\\rectangle.txt", "r"))
		{
			perror("Open");
			return;
		}
		char s[200];

		while (!feof(f))
		{
			fgets(s, 200, f);
			cout << s << endl;
		}

		fclose(f);
	}

	~rectangle() {}

private:
	float _x;
	float _y;
	float _side1;
	float _side2;
	float _perimetr;
	float _area;
};

class circle : public shape
{
public:
	circle(float x, float y, float radius)
	{
		_x = x;
		_y = y;
		_radius = radius;
		_area = 3.1415f * _radius * _radius;
	}

	virtual void Show()
	{
		cout << "\nCircle :\n";
		cout << "X : " << _x << " Y : " << _y << endl;
		cout << "Radius : " << _radius << endl;
		cout << "Area : " << _area << endl;
	}
	
	virtual void Save()
	{
		FILE *f;

		if (fopen_s(&f, "D:\\circle.txt", "w"))
		{
			perror("Open");
			return;
		}

		char str[20];

		fputs("Circle :\n", f);

		fputs("X : ", f);
		sprintf_s(str, 20, "%f", _x);
		fputs(str, f);

		fputs(" Y : ", f);
		sprintf_s(str, 20, "%f", _y);
		fputs(str, f);
		
		fputs("\nRadius : ", f);
		sprintf_s(str, 20, "%f", _radius);
		fputs(str, f);

		fputs("\nArea : ", f);
		sprintf_s(str, 20, "%f", _area);
		fputs(str, f);

		fclose(f);
	}

	virtual void Load()
	{
		FILE *f;

		if (fopen_s(&f, "D:\\circle.txt", "r"))
		{
			perror("Open");
			return;
		}
		char s[200];

		while (!feof(f))
		{
			fgets(s, 200, f);
			cout << s << endl;
		}

		fclose(f);
	}

	~circle() {}

private:
	float _x;
	float _y;
	float _radius;
	float _area;
};

class ellipse : public shape
{
public:
	ellipse(float x, float y, float side1, float side2)
	{
		_x = x;
		_y = y;
		_radius1 = side1 / 2;
		_radius2 = side2 / 2;
	}

	virtual void Show()
	{
		cout << "\nEllipse :\n";
		cout << "X : " << _x << " Y : " << _y << endl;
		cout << "First radius : " << _radius1 << endl;
		cout << "Second rsdius : " << _radius2 << endl;
	}

	virtual void Save()
	{
		FILE *f;

		if (fopen_s(&f, "D:\\ellipse.txt", "w"))
		{
			perror("Open");
			return;
		}

		char str[20];

		fputs("Ellipse :\n", f);

		fputs("X : ", f);
		sprintf_s(str, 20, "%f", _x);
		fputs(str, f);

		fputs(" Y : ", f);
		sprintf_s(str, 20, "%f", _y);
		fputs(str, f);
		
		fputs("\nFirst radius : ", f);
		sprintf_s(str, 20, "%f", _radius1);
		fputs(str, f);

		fputs("\nSecond radius : ", f);
		sprintf_s(str, 20, "%f", _radius2);
		fputs(str, f);

		fclose(f);
	}

	virtual void Load()
	{
		FILE *f;

		if (fopen_s(&f, "D:\\ellipse.txt", "r"))
		{
			perror("Open");
			return;
		}
		char s[200];

		while (!feof(f))
		{
			fgets(s, 200, f);
			cout << s << endl;
		}

		fclose(f);
	}

	~ellipse() {}

private:
	float _x;
	float _y;
	float _radius1;
	float _radius2;
};
