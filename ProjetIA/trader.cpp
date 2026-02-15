//
// Created by Youssef on 13/02/2026.
//

#include "trader.h"
trader::trader(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 100.f, 100.f });
    texture = sf::Texture("asset/trader.png");
    rectangle.setTexture(&texture);
    setPosition(x, y);
}

void trader::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({{0, 0}, {50, 30}});
}

void trader::setPosition(float x, float y)
{
    rectangle.setPosition({1080.f, 170.f});
}

void trader::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}