//
// Created by Youssef on 03/02/2026.
//

#include "Bouton.h"
#include <iostream>

// define a 120x50 rectangle

Bouton::Bouton(float width, float height, float x, float y)
{
    _bouton = sf::RectangleShape({ 120.f, 50.f });
    setPosition(x - (120 / 2), y - (50 / 2));
}

void Bouton::setSize(float x, float y)
{
    _bouton.setSize({ 100.f, 100.f });
}

void Bouton::setPosition(float x, float y)
{
    _bouton.setPosition({ x, y });
}

void Bouton::setColor(const sf::Color& color)
{
    _bouton.setFillColor(color);
}

void Bouton::draw(sf::RenderWindow& window)
{
    window.draw(_bouton);
}

bool Bouton::DetectOnClick(const sf::Event::MouseButtonPressed* currentInputMouse)
{
    bool HasClick = false;
    if (currentInputMouse != nullptr) {
        sf::Vector2f CursorPosition = sf::Vector2f(currentInputMouse->position);
        if (CursorPosition.x > GetPosition().x && CursorPosition.y > GetPosition().y && CursorPosition.x < GetBoutonExtent().x && CursorPosition.y < GetBoutonExtent().y)
        {
            HasClick = true;
        }
    }
    return HasClick;
}

void Bouton::OnClick(Params* _params)
{

}

sf::Vector2f Bouton::GetPosition()
{
    return _bouton.getPosition();
}

sf::Vector2f Bouton::GetBoutonExtent()
{
    return GetPosition() + _bouton.getSize();
}