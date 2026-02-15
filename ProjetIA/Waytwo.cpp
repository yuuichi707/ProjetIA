//
// Created by Youssef on 12/02/2026.
//

#include "Waytwo.h"

Waytwo::Waytwo(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 700.f, 1000.f });
    texture = sf::Texture("asset/Waytwo.png");
    rectangle.setTexture(&texture);
    setPosition(x, y);
}
void Waytwo::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({{10, 10}, {50, 30}});
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