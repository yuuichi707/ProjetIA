//
// Created by Youssef on 04/02/2026.
//

#include "Character2.h"
Character2::Character2(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 100.f, 100.f });
    texture = sf::Texture("asset/Character2.png");
    rectangle.setTexture(&texture);
    setPosition(x, y);
}

void Character2::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({{10, 10}, {50, 30}});
}

void Character2::setPosition(float x, float y)
{
    //entre 415 et 400
    rectangle.setPosition({300, 415});
}

void Character2::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}