#include "Batiment3.h"

// define a 120x50 rectangle

Batiment3::Batiment3(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 900.f, 420.f });
    setPosition(x, y);
}

void Batiment3::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Batiment3::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Batiment3::setColor(const sf::Color& color)
{
    rectangle.setFillColor(color);
}

void Batiment3::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}