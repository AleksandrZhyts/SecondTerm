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



////////////////////////////////////////////////////КЛАСС ИГРОКА////////////////////////
/*
class Player { // класс Игрока
public:
float x, y, w, h, dx, dy, speed; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
int dir; //направление (direction) движения игрока
String File; //файл с расширением
Image image;//сфмл изображение
Texture texture;//сфмл текстура
Sprite sprite;//сфмл спрайт
Player(String F, float X, float Y, float W, float H)
{ //Конструктор с параметрами(формальными) для класса Player.
//При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
dx = 0; dy = 0; speed = 0; dir = 0;
File = F;//имя файла+расширение
w = W; h = H;//высота и ширина

//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта.
//В нашем случае "hero.png" и получится запись идентичная image.loadFromFile("images/hero/png");
image.loadFromFile("images/" + File);

//убираем ненужный темно-синий цвет, эта тень мне показалась не красивой.
image.createMaskFromColor(Color(41, 33, 59));
texture.loadFromImage(image);//закидываем наше изображение в текстуру
sprite.setTexture(texture);//заливаем спрайт текстурой
x = X; y = Y;//координата появления спрайта
sprite.setTextureRect(IntRect(0, 0, w, h)); //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
}

void update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
{
switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
{
case 0: dx = speed; dy = 0; break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
case 1: dx = -speed; dy = 0; break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
case 2: dx = 0; dy = speed; break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
case 3: dx = 0; dy = -speed; break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
}

x += dx*time;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
y += dy*time;//аналогично по игреку

speed = 0;//зануляем скорость, чтобы персонаж остановился.
sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
}
};
*/
/*
int main()
{
//создаем объект p класса player,задаем "hero.png" как имя файла+расширение, далее координата Х,У, ширина, высота
Player p("tigers.png", 0, 150, 150.0, 150.0);

Clock clock;
float CurrentFrame = 0;//хранит текущий кадр


//float heroteleporttimer = 0; //создаем для примера телепортации героя через 3 секунды


RenderWindow window(sf::VideoMode(650, 490), "Lesson 3"); //увеличили для удобства размер окна

Image heroimage; //создаем объект Image (изображение)
heroimage.loadFromFile("images/tigers.png");//загружаем в него файл
heroimage.createMaskFromColor(Color(0, 0, 100));

Texture herotexture;//создаем объект Texture (текстура)
herotexture.loadFromImage(heroimage);//передаем в него объект Image (изображения)
*/
/*
Texture herotexture;//создаем объект Texture (текстура)
herotexture.loadFromFile("images/tigers.png");//загружаем картинку
*/
/*
Sprite herosprite;//создаем объект Sprite(спрайт)
herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
herosprite.setTextureRect(IntRect(0, 0, 150, 150));//получили нужный нам прямоугольник с котом
herosprite.setPosition(5, 5);//задаем начальные координаты появления спрайта
*/
/*
sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
sf::CircleShape shape(100.f);
shape.setFillColor(sf::Color::Green);
*/
/*
while (window.isOpen())
{
float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
clock.restart(); //перезагружает время
time = time / 800; //скорость игры
//std::cout << time << "\n";//смотрим как живет время (перезагружается, как видим)

//heroteleporttimer += time;//прибавляем к нашей переменной time
//if (heroteleporttimer > 3000) { herosprite.setPosition(0, 120); heroteleporttimer = 0; } //если таймертелепорта больше 3000 (это примерно 3 секунды), то телепортируем героя и обнуляем таймер телепортации


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
CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.

herosprite.setTextureRect(IntRect(210* int(CurrentFrame), 150, 210, 150)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0
herosprite.move(-0.1*time, 0);//происходит само движение персонажа влево
} //первая координата Х отрицательна =>идём влево
if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
{
CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
if (CurrentFrame > 3) CurrentFrame -= 3; //если пришли к третьему кадру - откидываемся назад.
herosprite.setTextureRect(IntRect(200 * int(CurrentFrame), 320, 200, 150)); //проходимся по координатам Х. получается 0, 96,96*2 и опять 0
herosprite.move(0.1*time, 0);//происходит само движение персонажа вправо
} //первая координата Х положительна =>идём вправо
if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
{
CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
herosprite.setTextureRect(IntRect(150 * int(CurrentFrame), 0, 150, 150)); //проходимся по координатам Х. получается 0,96,96*2, и опять 0
herosprite.move(0, -0.1*time);//происходит само движение персонажа вверх
} //вторая координата (У) отрицательна =>идём вверх
if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
{
CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
herosprite.setTextureRect(IntRect(150 * int(CurrentFrame), 0, 150, 150)); //проходимся по координатам Х. получается 0,96,96*2, и опять 0
herosprite.move(0, 0.1*time);//происходит само движение персонажа вниз
} //вторая координата (У) положительна =>идём вниз
*/
///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
/*
if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
p.dir = 1; p.speed = 0.1;//dir =1 - направление влево, speed =0.1 - скорость движения. Заметьте - время мы уже здесь ни на что не умножаем и нигде не используем каждый раз
CurrentFrame += 0.005*time;
if (CurrentFrame > 3) CurrentFrame -= 3;
p.sprite.setTextureRect(IntRect(210 * int(CurrentFrame), 150, 210, 150)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
}

if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
p.dir = 0; p.speed = 0.1;//направление вправо, см выше
CurrentFrame += 0.005*time;
if (CurrentFrame > 3) CurrentFrame -= 3;
p.sprite.setTextureRect(IntRect(200 * int(CurrentFrame), 320, 200, 150)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
}

if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
p.dir = 3; p.speed = 0.1;//направление вниз, см выше
CurrentFrame += 0.005*time;
if (CurrentFrame > 3) CurrentFrame -= 3;
p.sprite.setTextureRect(IntRect(150 * int(CurrentFrame), 0, 150, 150)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)

}

if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква А
p.dir = 2; p.speed = 0.1;//направление вверх, см выше
CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
p.sprite.setTextureRect(IntRect(150 * int(CurrentFrame), 0, 150, 150)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96

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
p.update(time);//оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться

window.clear();
window.draw(p.sprite);//рисуем спрайт объекта p класса player
window.display();

}

return 0;
}
*/