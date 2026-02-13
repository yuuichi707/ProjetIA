#include "Waytwo.h"

Waytwo::Waytwo(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 600.f, 1000.f });
    texture = sf::Texture("asset/Waytwo.png");
    rectangle.setTexture(&texture);
    setPosition(x, y);
}
void Waytwo::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({ {10, 10}, {50, 30} });
}
void Waytwo::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Waytwo::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Waytwo::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}