#pragma once
#include "GameObject.h"
#include "Panel.h"
#include "Managers.h"

class Enemy;
class Character;

class Arena : public GameObject
{
public:
	Arena(const sf::Vector2f& pos, Character* attacker);
	~Arena();

	void Battle(Character* attacker, Character* defender, float dt);

	void Action(ButtonType type, Character* actor, Character* target, float dt);
	void EnemyAction(Character* actor, Character* target, float dt);

	float Approach(float goal, float current, float dt);

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

private:
	Enemy* e;
	Character* enemyCharacter;
	Character* playerCharacter;

	char turn = 'p';

	PanelWithButtons* m_buttonPanel;

	float m_attackTimer;
	float m_elapsedTime;
};

