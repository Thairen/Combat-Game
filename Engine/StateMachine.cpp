#include "StateMachine.h"



StateMachine::StateMachine() : m_currentState(new EmptyState)
{
	m_states = std::map<std::string, State*>();
	m_stateStack = std::vector<State*>();
}

void StateMachine::Update(float dt)
{
	m_currentState->Update(dt);
}

void StateMachine::Draw(sf::RenderWindow * window)
{
	m_currentState->Draw(window);
}

void StateMachine::ChangeState(std::string stateName)
{
	m_currentState->OnExit();
	m_currentState = m_states[stateName];
	m_currentState->OnEnter();
}

void StateMachine::AddState(std::string stateName, State * state)
{
	m_states[stateName] = state;
}

void StateMachine::PushState(std::string name)
{
	State* state = m_states[name];
}

void StateMachine::PopState()
{
	return m_stateStack.pop_back();
}
