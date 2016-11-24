#pragma once
#include "State.h"
class MainMenuState : public State
{
public:
	MainMenuState();
	~MainMenuState();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow* window);
	virtual void OnEnter();
	virtual void OnExit();
};

