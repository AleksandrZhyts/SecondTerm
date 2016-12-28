#include "stdafx.h"
#include "Map_Chip.h"
#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>

using namespace sf;

int arr_start[] = {1,2,3,7,8,9};
int arr_finish[] = {7,8,9,1,2,3};
bool game_over(int* a, int* b, int size)
{
	int i = 0;
	while (i < size && a[i++] == b[i++]);
	return (i >= size);
}

class Chip {
	sf::RenderWindow* window; // ��������� �� ����, ����� ��� ���������
	sf::RectangleShape rectangle; // ����������, ���� �������
	//int y; // ���������� y ������� (x �� ������ � ����)
	int num_chip; // ����� ����� (1,2,3,4,5 ��� 6)
	int position; // ������� �� ���� (1,2,3,4,5,6,7,8 ��� 9)
	//color ?
public:
	// �����������
	Chip(sf::RenderWindow* window, int num, int pos) {
		
		this->num_chip = num;
		this->position = pos;

		this->window = window;
		// ������������� ������ ��� ������� � ������� Vector2f
		this->rectangle.setSize(sf::Vector2f(50, 50));
		// ��� �������� ��������� �������� ����� �� ������ �������� ���� � �����
		//this->rectangle.setOrigin(5, 50);
		// � ������������� ����� � ��������� �������
		this->rectangle.setPosition(((pos-1) % 3) * 100 + 100, ((pos-1) / 3) * 100 + 100);
		switch (num)
		{
		case 1: rectangle.setFillColor(sf::Color::Yellow);
			break;
		case 2: rectangle.setFillColor(sf::Color::Green);
			break;
		case 3: rectangle.setFillColor(sf::Color::White);
			break;
		case 4: rectangle.setFillColor(sf::Color::Blue);
			break;
		case 5: rectangle.setFillColor(sf::Color::Red);
			break;
		case 6: rectangle.setFillColor(sf::Color::Magenta);
			break;
		}
	}
	// ����� ��� ��������� �������
	void draw() {
		this->window->draw(this->rectangle);
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
	}
	
	/* ��������� ������� ������ � ����������� �������
	������ ����� ��������� ���������, ������ -- ��������� W � S */
	void update(float time) {
		if (this->player == 1) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				// �������� ��������� ������� � ����������� �� ������� �������
				this->y -= time * 0.3;
				this->setY(this->y); // setY - ������ ��� ���������� Y
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				this->y += time * 0.3;
				this->setY(this->y);
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				this->setY(this->y - time * 0.3);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				this->setY(this->y + time * 0.3);
			}
		}
	}
};

int main()
{
	// ������� ������� ���� ����������
	sf::RenderWindow window(sf::VideoMode(450, 450), "Cupboards");

	// ������� ���������� ������� (����� ��� ������� ��������)
	sf::Clock clock;
	float time;
	// �������� ������������ ������������� (��� ������� ��������)
	window.setVerticalSyncEnabled(true);

	// ������� ���� ����������
	while (window.isOpen())
	{
		// ������������ ������� � �����
		sf::Event event;
		while (window.pollEvent(event))
		{
			// ����� �������� ������� ���� ���� ����� ����������� �� ������� �� Escape
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}

		// �������
		window.clear();
		time = clock.getElapsedTime().asMilliseconds();
		clock.restart();
		
		// ��� ����� ���������� ������� ���������� � ��������� ��������
		// ���������
		window.display();
	}

	return 0;
}

