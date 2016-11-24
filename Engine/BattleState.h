#pragma once
#include "State.h"
class BattleState : public State
{
public:
	BattleState();
	~BattleState();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow* window);
	virtual void OnEnter();
	virtual void OnExit();
};

