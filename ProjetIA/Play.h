//
// Created by Youssef on 03/02/2026.
//

#ifndef PROJETIA_PLAY_H
#define PROJETIA_PLAY_H
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
#endif //PROJETIA_PLAY_H