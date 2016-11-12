#include "Owner.h"


Owner::Owner(const sf::Vector2f& pos) : GameObject("", pos)
{
}

Owner::~Owner()
{
}

void Owner::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);
}

void Owner::Draw(sf::RenderWindow * window)
{
	GameObject::Draw(window);
}

void Owner::AddCharacter(Character * character)
{
	m_characterList.push_back(character);
}
