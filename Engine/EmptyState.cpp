#include "EmptyState.h"



EmptyState::EmptyState(StateMachine* machine) : State(machine)
{
}


EmptyState::~EmptyState()
{
}

void EmptyState::Update(float dt)
{
	//The most empty of all the states
}

void EmptyState::Draw(sf::RenderWindow * window)
{
	//The most empty of all the states
}

void EmptyState::OnEnter()
{
	//The most empty of all the states
}

void EmptyState::OnExit()
{
	//The most empty of all the states
}
