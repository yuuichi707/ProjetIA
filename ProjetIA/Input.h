//
// Created by Youssef on 03/02/2026.
//

#ifndef PROJETIA_INPUT_H
#define PROJETIA_INPUT_H
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
#endif //PROJETIA_INPUT_H