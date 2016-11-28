#pragma once
#include "State.h"

class Game;

class MainMenuState : public State
{
public:
	MainMenuState(StateMachine* machine);
	~MainMenuState();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow* window);
	virtual void OnEnter();
	virtual void OnExit();

private:

	
};

