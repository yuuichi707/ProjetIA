//
// Created by Youssef on 13/02/2026.
//

#ifndef PROJETIA_TRADER_H
#define PROJETIA_TRADER_H


#pragma once
#include <SFML/Graphics.hpp>
class trader
{
private:
    sf::Texture texture;
public:
    trader(float width, float height, float x, float y);

    void setTextureRect(float x, float y);
    void setPosition(float x, float y);

    void draw(sf::RenderWindow& window);

    sf::RectangleShape rectangle;
};


#endif //PROJETIA_TRADER_H