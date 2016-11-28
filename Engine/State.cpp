#include "State.h"
#include "StateMachine.h"


State::State(StateMachine* machine) : m_machine(machine)
{
	//No behavior for base state
}

void State::Update(sf::RenderWindow* window, float dt)
{
	//No behavior for base state
}

void State::Draw(sf::RenderWindow * window)
{
	//No behavior for base state
}

void State::OnEnter()
{
	//No behavior for base state
}

void State::OnExit()
{
	//No behavior for base state
}