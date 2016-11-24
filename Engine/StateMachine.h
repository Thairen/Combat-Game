#pragma once
#include "EmptyState.h"
#include "InGameMenuState.h"
#include "MainMenuState.h"
#include "BattleState.h"
#include <vector>
#include <map>

/////// IMPLEMENTED TO TAKE IN STATES WITH A STRING IDENTIFIER
/////// USES A VECTOR FOR POPPING IRRELEVANT STATES

class StateMachine
{
public:
	StateMachine();

	void Update(float dt);
	void Draw(sf::RenderWindow* window);

	//Add states to the machine
	void ChangeState(std::string stateName);
	void AddState(std::string stateName, State* state);

	//Add states to the stack
	void PushState(std::string name);
	void PopState();

private:

	State* m_currentState; //Mark current state for updates and renders
	std::map<std::string, State*> m_states; // Map of all states and their identifier
	std::vector<State*> m_stateStack; //Stack for pushing in new states
};

