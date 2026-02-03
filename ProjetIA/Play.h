#pragma once
#include <SFML/Graphics.hpp>
#include "Bouton.h"


class PlayParams : public Params {
public:
    PlayParams() = default;
    PlayParams(sf::RenderWindow* Window) {
        InternWindow = Window;
    }

    sf::RenderWindow* InternWindow;
};

class Play : public Bouton
{
public:

    Play();
    Play(float width, float height, float x, float y);

    void OnClick(Params* _params) override;

};

