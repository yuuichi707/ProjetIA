
#pragma once
#include <SFML/Graphics.hpp>

struct Input {

    const sf::Event::KeyPressed* currentInputKey;
    const sf::Event::MouseButtonPressed* currentInputMouse;

    Input();
    ~Input();

    void setInputKey(const sf::Event::KeyPressed* input);
    void setInputMouse(const sf::Event::MouseButtonPressed* input);
};