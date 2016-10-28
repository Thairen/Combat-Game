#include "Character.h"



Character::Character(std::string texturePath, const sf::Vector2f & pos) : GameObject(texturePath, pos)
{
}

void Character::Update(sf::RenderWindow* window, float dt)
{
	GameObject::Update(window, dt);
}

void Character::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}
