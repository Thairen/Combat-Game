#pragma once
#include "GameObject.h"
class Enemy;
class Character;

class Arena : public GameObject
{
public:
	Arena(const sf::Vector2f& pos, Character* attacker);
	~Arena();

	void Battle(Character* attacker, Character* defender);

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

private:
	Enemy* e;
	Character* playerCharacter;
};

