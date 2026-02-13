#pragma once
#include <SFML/Graphics.hpp>
#include "Bouton.h"

class QuitParams : public Params {
public:
    QuitParams() = default;
    QuitParams(sf::RenderWindow* Window) {
        InternWindow = Window;
    }

    sf::RenderWindow* InternWindow;
};

class Quit : public Bouton
{
private:
    sf::Texture texture;
public:

    Quit();
    Quit(float width, float height, float x, float y);

    void setTextureRect(float x, float y);
    void OnClick(Params* _params) override;
};