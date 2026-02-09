//
// Created by Youssef on 03/02/2026.
//

#ifndef PROJETIA_PLAY_H
#define PROJETIA_PLAY_H
#pragma once
#include <SFML/Graphics.hpp>
#include "Bouton.h"
#include "Scene.h"


class PlayParams : public Params {
public:
    PlayParams() = default;
    PlayParams(Scene* _Scene) {
        InternScene = _Scene;
    }

    Scene* InternScene;
};

class Play : public Bouton
{
public:
    Play();
    Play(float width, float height, float x, float y);

    void OnClick(Params* _params) override;

};
#endif //PROJETIA_PLAY_H