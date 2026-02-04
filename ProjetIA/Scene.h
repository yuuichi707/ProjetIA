//
// Created by Youssef on 03/02/2026.
//

#ifndef PROJETIA_SCENE_H
#define PROJETIA_SCENE_H
#pragma once
#include <SFML/Graphics.hpp>
#include "Play.h"

enum SceneState
{
    Menu,
    PLAY,
    Pause
};

class Scene : public Play
{
public:

    Scene() = default;

    float WindowHeight;
    float WindowWidth;

    float currentScene;
    float PreviousScene;

    SceneState CurrentState;
    SceneState PreviousState;

    sf::RenderWindow* _render;

    Scene(sf::RenderWindow* _render, float _WindowHeight, int _WindowWidth);
    virtual ~Scene();

    void update(float dt);
};
#endif //PROJETIA_SCENE_H