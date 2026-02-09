//
// Created by Youssef on 03/02/2026.
//

#include "Play.h"
#include <iostream>



Play::Play(){}

Play::Play(float width, float height, float x, float y)
: Bouton(width, height, x, y){
}

void Play::OnClick(Params* _params)
{
    PlayParams* CastedParams = static_cast<PlayParams*>(_params);
    CastedParams->InternScene->currentScene = SceneState::PLAY;
    std::cout << "Play";
}
