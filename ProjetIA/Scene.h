#pragma once
#include <SFML/Graphics.hpp>
#include "Play.h"

enum SceneState
{
	Menu,
	Play,
	Game,
};

class Scene : public Play
{
public:

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