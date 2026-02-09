
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
