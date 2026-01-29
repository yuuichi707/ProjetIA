#pragma once
#include <SFML/Graphics.hpp>

enum SceneState 
{
	Menu,
	Pause,
	Quit,
};

class Scene
{
public:

	float WindowHeight;
	float WindowWidth;

	SceneState CurrentState;
	SceneState PreviousState;

	sf::RenderWindow* _render;

	Scene(sf::RenderWindow* _render, float _WindowHeight, int _WindowWidth);
	virtual ~Scene();

	virtual void update(float dt);
	virtual void render(sf::RenderWindow* render);
};

