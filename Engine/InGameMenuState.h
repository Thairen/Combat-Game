#pragma once
#include "State.h"

class Game;

class InGameMenuState : public State
{
public:
	InGameMenuState(StateMachine* machine);
	~InGameMenuState();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow* window);
	virtual void OnEnter();
	virtual void OnExit();

private:

};

