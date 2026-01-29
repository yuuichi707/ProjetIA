#pragma once
#include <SFML/Graphics.hpp>
class Batiment
{
public:
    Batiment(float width, float height, float x = 0.f, float y = 0.f);

    void setSize(float x, float y);
    void setPosition(float x, float y);
    void setColor(sf::Color& color);

    void draw(sf::RenderWindow& window);

};