#include "Action.h"



Action::Action(Character* owner) : m_owner(owner), m_target(nullptr)
{
	//Default constructor
}

void Action::Start()
{
	//Starting behavior here
}

void Action::End()
{
	//What needs to be done before action is removed
}

void Action::Update(float dt)
{
	//Update
}

void Action::Draw(sf::RenderWindow * window)
{
	//Draw
}
