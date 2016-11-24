#pragma once
#include "SFML\Graphics.hpp"
class State
{
public:
	State();
	
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow* window);
	virtual void OnEnter();
	virtual void OnExit();
};

