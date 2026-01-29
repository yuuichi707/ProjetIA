#pragma once
#include "Scene.h"
class Menu : public Scene
{
	void update(float dt) override;
	void render(sf::RenderWindow* render) override;
};

