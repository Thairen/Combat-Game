#include "Character.h"



Character::Character(std::string texturePath, const sf::Vector2f & pos) : GameObject(texturePath, pos)
{
	m_health = new Stat("Health", 50, 50);
	m_strength = new Stat("Strength", 10, 10);
	m_defense = new Stat("Defense", 10, 10);
	m_level = new Stat("Level", 1, 100);
	m_exp = new Stat("XP", 0, 100);
}

Character::~Character()
{
	delete m_health, m_strength, m_defense, m_level, m_exp;
}

void Character::Update(sf::RenderWindow* window, float dt)
{
	GameObject::Update(window, dt);
}

void Character::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}
