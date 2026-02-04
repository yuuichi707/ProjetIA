//
// Created by Youssef on 03/02/2026.
//

#include "Input.h"

Input::Input() {
    currentInputKey = nullptr;
    currentInputMouse = nullptr;
}

Input::~Input() {

}

void Input::setInputKey(const sf::Event::KeyPressed* input) {
    currentInputKey = input;
}

void Input::setInputMouse(const sf::Event::MouseButtonPressed* input) {
    currentInputMouse = input;
}