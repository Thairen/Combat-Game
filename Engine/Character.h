#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "Stat.h"

enum class CharacterType
{
	Cloud,
	Tifa,
	Aerith,
	RedX,
	Barrett,
	CaitSith,
	Yuffie,
	Vincent,
	Cid
};

class Character : public GameObject
{
public:
	Character(CharacterType type, const sf::Vector2f & pos);
	~Character();

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);

	void SetCharacter();
	

private:
	Stat* m_health;
	Stat* m_strength;
	Stat* m_defense;
	Stat* m_level;
	Stat* m_exp;

	CharacterType m_type;
};

