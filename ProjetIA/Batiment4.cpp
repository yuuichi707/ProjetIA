#include "Batiment4.h"

// define a 120x50 rectangle

Batiment4::Batiment4(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 900.f, 420.f });
    setPosition(x, y);
}

void Batiment4::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Batiment4::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Batiment4::setColor(const sf::Color& color)
{
    rectangle.setFillColor(color);
}

void Batiment4::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}