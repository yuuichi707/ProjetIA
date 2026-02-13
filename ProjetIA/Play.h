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
private:
    sf::Texture texture;
public:
    Play();
    Play(float width, float height, float x, float y);
    void setTextureRect(float x, float y);
    void OnClick(Params* _params) override;
    void draw(sf::RenderWindow& window);

    //sf::RectangleShape rectangle;
};