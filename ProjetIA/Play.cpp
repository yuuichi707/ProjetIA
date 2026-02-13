#include "Play.h"
#include <iostream>



Play::Play() {}

Play::Play(float width, float height, float x, float y)
    : Bouton(width, height, x, y) {
    _bouton = sf::RectangleShape({ 250.f, 100.f });
    texture = sf::Texture("asset/play.png");
    _bouton.setTexture(&texture);
    setPosition(x, y);
}

void Play::setTextureRect(float x, float y)
{
    _bouton.setTextureRect({ {10, 10}, {50, 30} });
}

void Play::OnClick(Params* _params)
{
    PlayParams* CastedParams = static_cast<PlayParams*>(_params);
    CastedParams->InternScene->currentScene = SceneState::PLAY;
    std::cout << "Play";
}
void Play::draw(sf::RenderWindow& window)
{
    window.draw(_bouton);
}