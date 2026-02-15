//
// Created by Youssef on 12/02/2026.
//

#ifndef PROJETIA_WAYTWO_H
#define PROJETIA_WAYTWO_H

#pragma once
#include <SFML/Graphics.hpp>

class Waytwo
{
private:
    sf::Texture texture;
public:
    Waytwo(float width, float height, float x = 0.f, float y = 0.f);

    void setTextureRect(float x, float y);
    void setSize(float x, float y);
    void setPosition(float x, float y);

    void draw(sf::RenderWindow & window);

    sf::RectangleShape rectangle;
};


#endif //PROJETIA_WAYTWO_H