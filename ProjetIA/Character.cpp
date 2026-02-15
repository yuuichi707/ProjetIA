#include "Character.h"
Character::Character(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 100.f, 100.f });
    texture = sf::Texture("asset/eren.png");
    rectangle.setTexture(&texture);
    setPosition(x, y);
}

void Character::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({{0, 0}, {50, 30}});
}

void Character::setPosition(float x, float y)
{
    rectangle.setPosition({470.f, 260.f});
}

void Character::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}

