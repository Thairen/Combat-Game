#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "Stat.h"
class Character : public GameObject
{
public:
	Character(std::string texturePath, const sf::Vector2f & pos);

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);

private:
	Stat* m_health;
	Stat* m_strength;
	Stat* m_defense;
};

