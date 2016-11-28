#pragma once
#include "State.h"

class Game;

class BattleState : public State
{
public:
	BattleState(StateMachine* machine, Game* game);
	~BattleState();

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);
	virtual void OnEnter();
	virtual void OnExit();

private:
	Game* m_game;
};

