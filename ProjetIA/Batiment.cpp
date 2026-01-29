#include "Batiment.h"


// define a 120x50 rectangle

Batiment::Batiment(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 120.f, 50.f });
}

void Batiment::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Batiment::setPosition(float x, float y)
{
    rectangle.setPosition({x, y});
}

void Batiment::setColor(sf::Color& color)
{
    rectangle.setFillColor(color);
}

void Batiment::draw(sf::RenderWindow& window) 
{
    window.draw(rectangle);
}
