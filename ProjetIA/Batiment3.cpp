#include "Batiment3.h"

// define a 120x50 rectangle

Batiment3::Batiment3(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 665.f, 360.f });
    texture = sf::Texture("asset/commerce.png");
    rectangle.setTexture(&texture);
    setPosition(x, y);
}
void Batiment3::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({ {10, 10}, {50, 30} });
}
void Batiment3::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Batiment3::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Batiment3::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}