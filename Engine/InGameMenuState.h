#pragma once
#include "State.h"
class InGameMenuState : public State
{
public:
	InGameMenuState();
	~InGameMenuState();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow* window);
	virtual void OnEnter();
	virtual void OnExit();
};

