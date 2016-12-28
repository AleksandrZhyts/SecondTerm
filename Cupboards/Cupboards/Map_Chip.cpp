#include "stdafx.h"
#include "Map_Chip.h"

/*
Map_Chip::Map_Chip()
{
}


Map_Chip::~Map_Chip()
{
}
*/



////////////////////////////////////////////////////����� ������////////////////////////
/*
class Player { // ����� ������
public:
float x, y, w, h, dx, dy, speed; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
int dir; //����������� (direction) �������� ������
String File; //���� � �����������
Image image;//���� �����������
Texture texture;//���� ��������
Sprite sprite;//���� ������
Player(String F, float X, float Y, float W, float H)
{ //����������� � �����������(�����������) ��� ������ Player.
//��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
dx = 0; dy = 0; speed = 0; dir = 0;
File = F;//��� �����+����������
w = W; h = H;//������ � ������

//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������.
//� ����� ������ "hero.png" � ��������� ������ ���������� image.loadFromFile("images/hero/png");
image.loadFromFile("images/" + File);

//������� �������� �����-����� ����, ��� ���� ��� ���������� �� ��������.
image.createMaskFromColor(Color(41, 33, 59));
texture.loadFromImage(image);//���������� ���� ����������� � ��������
sprite.setTexture(texture);//�������� ������ ���������
x = X; y = Y;//���������� ��������� �������
sprite.setTextureRect(IntRect(0, 0, w, h)); //������ ������� ���� ������������� ��� ������ ������ ����, � �� ���� ����� �����. IntRect - ���������� �����
}

void update(float time) //������� "���������" ������� ������. update - ����������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.
{
switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
{
case 0: dx = speed; dy = 0; break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� �������� ���� ������ ������
case 1: dx = -speed; dy = 0; break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
case 2: dx = 0; dy = speed; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ ����
case 3: dx = 0; dy = -speed; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ �����
}

x += dx*time;//�� �������� �� �������� �����. ���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
y += dy*time;//���������� �� ������

speed = 0;//�������� ��������, ����� �������� �����������.
sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
}
};
*/
/*
int main()
{
//������� ������ p ������ player,������ "hero.png" ��� ��� �����+����������, ����� ���������� �,�, ������, ������
Player p("tigers.png", 0, 150, 150.0, 150.0);

Clock clock;
float CurrentFrame = 0;//������ ������� ����


//float heroteleporttimer = 0; //������� ��� ������� ������������ ����� ����� 3 �������


RenderWindow window(sf::VideoMode(650, 490), "Lesson 3"); //��������� ��� �������� ������ ����

Image heroimage; //������� ������ Image (�����������)
heroimage.loadFromFile("images/tigers.png");//��������� � ���� ����
heroimage.createMaskFromColor(Color(0, 0, 100));

Texture herotexture;//������� ������ Texture (��������)
herotexture.loadFromImage(heroimage);//�������� � ���� ������ Image (�����������)
*/
/*
Texture herotexture;//������� ������ Texture (��������)
herotexture.loadFromFile("images/tigers.png");//��������� ��������
*/
/*
Sprite herosprite;//������� ������ Sprite(������)
herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)
herosprite.setTextureRect(IntRect(0, 0, 150, 150));//�������� ������ ��� ������������� � �����
herosprite.setPosition(5, 5);//������ ��������� ���������� ��������� �������
*/
/*
sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
sf::CircleShape shape(100.f);
shape.setFillColor(sf::Color::Green);
*/
/*
while (window.isOpen())
{
float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
clock.restart(); //������������� �����
time = time / 800; //�������� ����
//std::cout << time << "\n";//������� ��� ����� ����� (���������������, ��� �����)

//heroteleporttimer += time;//���������� � ����� ���������� time
//if (heroteleporttimer > 3000) { herosprite.setPosition(0, 120); heroteleporttimer = 0; } //���� ��������������� ������ 3000 (��� �������� 3 �������), �� ������������� ����� � �������� ������ ������������


sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}
*/
/*
if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
{
CurrentFrame += 0.005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
if (CurrentFrame > 3) CurrentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.

herosprite.setTextureRect(IntRect(210* int(CurrentFrame), 150, 210, 150)); //���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0
herosprite.move(-0.1*time, 0);//���������� ���� �������� ��������� �����
} //������ ���������� � ������������ =>��� �����
if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
{
CurrentFrame += 0.005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
if (CurrentFrame > 3) CurrentFrame -= 3; //���� ������ � �������� ����� - ������������ �����.
herosprite.setTextureRect(IntRect(200 * int(CurrentFrame), 320, 200, 150)); //���������� �� ����������� �. ���������� 0, 96,96*2 � ����� 0
herosprite.move(0.1*time, 0);//���������� ���� �������� ��������� ������
} //������ ���������� � ������������ =>��� ������
if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
{
CurrentFrame += 0.005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
if (CurrentFrame > 3) CurrentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
herosprite.setTextureRect(IntRect(150 * int(CurrentFrame), 0, 150, 150)); //���������� �� ����������� �. ���������� 0,96,96*2, � ����� 0
herosprite.move(0, -0.1*time);//���������� ���� �������� ��������� �����
} //������ ���������� (�) ������������ =>��� �����
if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
{
CurrentFrame += 0.005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
if (CurrentFrame > 3) CurrentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
herosprite.setTextureRect(IntRect(150 * int(CurrentFrame), 0, 150, 150)); //���������� �� ����������� �. ���������� 0,96,96*2, � ����� 0
herosprite.move(0, 0.1*time);//���������� ���� �������� ��������� ����
} //������ ���������� (�) ������������ =>��� ����
*/
///////////////////////////////////////////���������� ���������� � ���������////////////////////////////////////////////////////////////////////////
/*
if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
p.dir = 1; p.speed = 0.1;//dir =1 - ����������� �����, speed =0.1 - �������� ��������. �������� - ����� �� ��� ����� �� �� ��� �� �������� � ����� �� ���������� ������ ���
CurrentFrame += 0.005*time;
if (CurrentFrame > 3) CurrentFrame -= 3;
p.sprite.setTextureRect(IntRect(210 * int(CurrentFrame), 150, 210, 150)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
}

if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
p.dir = 0; p.speed = 0.1;//����������� ������, �� ����
CurrentFrame += 0.005*time;
if (CurrentFrame > 3) CurrentFrame -= 3;
p.sprite.setTextureRect(IntRect(200 * int(CurrentFrame), 320, 200, 150)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
}

if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
p.dir = 3; p.speed = 0.1;//����������� ����, �� ����
CurrentFrame += 0.005*time;
if (CurrentFrame > 3) CurrentFrame -= 3;
p.sprite.setTextureRect(IntRect(150 * int(CurrentFrame), 0, 150, 150)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)

}

if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
p.dir = 2; p.speed = 0.1;//����������� �����, �� ����
CurrentFrame += 0.005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
if (CurrentFrame > 3) CurrentFrame -= 3; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
p.sprite.setTextureRect(IntRect(150 * int(CurrentFrame), 0, 150, 150)); //���������� �� ����������� �. ���������� 96,96*2,96*3 � ����� 96

}
*/
/*
if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
{
herosprite.setColor(Color::Red);
}
if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
{
herosprite.setColor(Color::Blue);
}
*/
/*
p.update(time);//�������� ������ p ������ Player � ������� ������� sfml, ��������� ����� � �������� ��������� ������� update. ��������� ����� �������� ����� ���������

window.clear();
window.draw(p.sprite);//������ ������ ������� p ������ player
window.display();

}

return 0;
}
*/