#pragma once
#include "stdafx.h"

class Map_Chip
{
public:
	sf::RenderWindow* window; // Указатель на окно, нужен для отрисовки
	sf::RectangleShape rectangle; // Собственно, сама ракетка
	Position *arr_node;
	unsigned int count_chip;
	unsigned int count_node;
	Map_Chip(sf::RenderWindow* window, unsigned int chip, unsigned int node = 9)
	{
		
		window = window;                                           //this->
		// Устанавливаем размер для фишки с помощью Vector2f
		rectangle.setSize(sf::Vector2f(50, 50));                  //this->
		// Для удобства перенесем основную точку из левого верхнего угла в центр
		//this->rectangle.setOrigin(5, 50); //??
		
		count_chip = chip;
		count_node = node;
		arr_node = new Position[node];
		for (unsigned int i(0); i < node; i++)
		{
			arr_node[i]._x = (i % 3) * 100 + 100;
			arr_node[i]._y = (i / 3) * 100 + 100;
			arr_node[i]._color = Black;
			rectangle.setPosition(arr_node[i]._x, arr_node[i]._y);   //this
			arr_node[i]._color = Black;
			rectangle.setFillColor(sf::Color::Black);       //this
		}
	}

	// Метод для отрисовки фишки
	void setColor(Position& pos, unsigned int num)
	{

	}

	
	void Move(float time, unsigned int from, unsigned int to)
	{
		switch (from)
		{
		case 1:
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (arr_node[from]._color == Black || arr_node[to]._color != Black || to != 2) return;
				//herosprite.setColor(Color::Blue);
			}
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		default:
			break;
		}
		
		
		

		arr_node[from]._color = Black;
		if (arr_node[from]._color == Black || arr_node[to]._color != Black ) return false;
		else
		{
			arr_node[to]._color = arr_node[from]._color;
			arr_node[from]._color = Black;
		}
	}

	~Map_Chip()
	{
		delete[] arr_node;
		arr_node = NULL;
	}
};



