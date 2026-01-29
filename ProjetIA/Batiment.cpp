#include "Batiment.h"
#include <SFML/Graphics.hpp>

// define a 120x50 rectangle
sf::RectangleShape rectangle({ 120.f, 50.f });

Batiment::Batiment(float width, float height, float x, float y)
{
}

void Batiment::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Batiment::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Batiment::setColor(sf::Color& color)
{
    rectangle.setFillColor(color);
}

void Batiment::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}