#include "Batiment4.h"

// define a 120x50 rectangle

Batiment4::Batiment4(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 800.f, 460.f });
    texture = sf::Texture("asset/Boulangerietwo.png");
    rectangle.setTexture(&texture);
    setPosition(x, y);
}
void Batiment4::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({{10, 10}, {50, 30}});
}
void Batiment4::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Batiment4::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Batiment4::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}