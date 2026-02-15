#include "Batiment.h"

Batiment::Batiment(const std::filesystem::path& texturePath1, float x, float y)
{
    rectangle = sf::RectangleShape({ 700.f, 400.f });
    texture = sf::Texture(texturePath1);
    rectangle.setTexture(&texture);
    setPosition(x, y);
}
void Batiment::setTextureRect(float x, float y)
{
    rectangle.setTextureRect({ {10, 10}, {50, 30} });
}
void Batiment::setSize(float x, float y)
{
    rectangle.setSize({ 100.f, 100.f });

}

void Batiment::setPosition(float x, float y)
{
    rectangle.setPosition({ x, y });
}

void Batiment::draw(sf::RenderWindow& window)
{
    window.draw(rectangle);
}