#pragma once
#include <SFML/Graphics.hpp>

class Character 
{
private:
    sf::Texture texture;
    sf::Color color;
public:
    Character() = default;
    Character(float width, float height, float x, float y);

    void setTextureRect(float x, float y);
    void setPosition(float x, float y);
    
    void draw(sf::RenderWindow& window);


public:
    sf::RectangleShape rectangle;
};