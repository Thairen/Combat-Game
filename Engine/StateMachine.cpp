#include "StateMachine.h"



StateMachine::StateMachine() : m_currentState(new EmptyState(this))
{
	m_states = std::map<std::string, State*>();
	m_stateStack = std::vector<State*>();
}

void StateMachine::Update(sf::RenderWindow* window, float dt)
{
	m_currentState->Update(window, dt);
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
	m_stateStack.push_back(state);
}

void StateMachine::PopState()
{
	return m_stateStack.pop_back();
}
