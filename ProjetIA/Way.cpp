//
// Created by Youssef on 10/02/2026.
//

#include "Way.h"
Way::Way(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 1500.f, 800.f });
    texture = sf::Texture("asset/Way.png");
    rectangle.setTexture(&texture);
    setPosition(x, y);
}
void Way::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({{10, 10}, {50, 30}});
}
void Way::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });
}

void Way::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Way::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}