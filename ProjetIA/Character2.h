//
// Created by Youssef on 04/02/2026.
//

#ifndef PROJETIA_CHARACTER2_H
#define PROJETIA_CHARACTER2_H
#pragma once
#include <SFML/Graphics.hpp>
class Character2
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
#endif //PROJETIA_CHARACTER2_H