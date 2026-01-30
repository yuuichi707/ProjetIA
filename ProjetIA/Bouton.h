#pragma once
#include <SFML/Graphics.hpp>

class Bouton
{
public:
    Bouton(float width, float height, float x, float y);

    void setSize(float x, float y);
    void setPosition(float x, float y);
    void setColor(const sf::Color& color);
    void draw(sf::RenderWindow& window);

    void DetectOnClick(const sf::Event::MouseButtonPressed* currentInputMouse);
    virtual void OnClick();

    sf::Vector2f GetPosition();
    sf::Vector2f GetBoutonExtent();


    sf::RectangleShape _bouton;
};