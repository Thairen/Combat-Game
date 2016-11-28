#include "BattleState.h"
#include <iostream>
#include "Game.h"



BattleState::BattleState(StateMachine* machine, Game* game) : State(machine), m_game(game)
{
}


BattleState::~BattleState()
{
}

void BattleState::Update(sf::RenderWindow* window, float dt)
{
	State::Update(window, dt);
	m_game->UpdateBattle(window, dt);
}

void BattleState::Draw(sf::RenderWindow * window)
{
	State::Draw(window);
	m_game->DrawBattle(window);
}

void BattleState::OnEnter()
{

}

void BattleState::OnExit()
{
}
