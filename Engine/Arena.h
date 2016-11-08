#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include "Character.h"

class Arena : public GameObject
{
public:
	Arena(const sf::Vector2f& pos, Character* attacker);
	~Arena();

	void Battle(Character* attacker, Character* defender);

private:
	Enemy* e;
	Character* player;
};

