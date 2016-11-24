#pragma once
#include "State.h"
class EmptyState : public State
{
public:
	EmptyState();
	~EmptyState();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow* window);
	virtual void OnEnter();
	virtual void OnExit();

};

