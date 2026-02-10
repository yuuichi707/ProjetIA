#pragma once
#include <SFML/Graphics.hpp>
#include "NPC.h"

class Character2 : public NPC
{
private:
    sf::Texture texture;
public:
    Character2(float width, float height, float x, float y);

    void setTextureRect(float x, float y);
    void setPosition(float x, float y);

    void draw(sf::RenderWindow& window);

    sf::RectangleShape rectangle;
};
