#include "Batiment1.h"

// define a 120x50 rectangle

Batiment1::Batiment1(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 850.f, 500.f });
    texture = sf::Texture("asset/bar.png");
    rectangle.setTexture(&texture);
    setPosition(x, y);
}
void Batiment1::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({ {10, 10}, {50, 30} });
}
void Batiment1::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Batiment1::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Batiment1::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}

