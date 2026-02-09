#include "Batiment2.h"

// define a 120x50 rectangle

Batiment2::Batiment2(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 700, 350 });
    setPosition(x, y);
}

void Batiment2::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Batiment2::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Batiment2::setColor(const sf::Color& color)
{
    rectangle.setFillColor(color);
}

void Batiment2::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}