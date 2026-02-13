#include "Background.h"
Background::Background(float width, float height, float x, float y)
{
    rectangle = sf::RectangleShape({ 1440.f, 900.f });
    texture = sf::Texture("asset/Background.jpg");
    rectangle.setTexture(&texture);
    setPosition(x, y);
}

void Background::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({ {0, 0}, {50, 30} });
}

void Background::setPosition(float x, float y)
{
    rectangle.setPosition({ 0.f, 0.f });
}

void Background::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}