#pragma once
#include "SFML\Graphics.hpp"

class StateMachine;

class State
{
public:
	State(StateMachine* machine);
	
	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);
	virtual void OnEnter();
	virtual void OnExit();

private:
	StateMachine* m_machine;
};

