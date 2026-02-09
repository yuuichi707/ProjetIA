#include "Batiment1.h"

// define a 120x50 rectangle

Batiment1::Batiment1(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 700.f, 350.f });
    setPosition(x, y);

}

void Batiment1::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Batiment1::setPosition(float x, float y)
{
    rectangle.setPosition({x, y});
}

void Batiment1::setColor(const sf::Color& color)
{
    rectangle.setFillColor(color);
}

void Batiment1::draw(sf::RenderWindow& window) 
{
    window.draw(rectangle);
}
