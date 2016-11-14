#include "Arena.h"
#include "Enemy.h"
#include "Character.h"


Arena::Arena(const sf::Vector2f& pos, Character* attacker) : GameObject("", pos) //Perhaps throw backgrounds into this class?
{
	e = new Enemy(sf::Vector2f(0.f, 0.f)); //Init the enemy
	playerCharacter = attacker;
}

void Arena::Battle(Character * attacker, Character * defender)
{
	char turn = 'p';

	//INFINITE LOOP RIGHT MEOW!!!!!!!!!!!!!!!!!!
	while (attacker->GetCurrent("Health") > 0 && defender->GetCurrent("Health") > 0)
	{
		if (turn == 'p')
		{
			//player input
			//
			//if (Action)
			//
			// DoAction();
			//
			//Play Anim
			turn = 'e';
		}
		if (turn == 'e')
		{
			//enemy input
			// Random roll move
			// DoAction();
			//
			// Play Anim
			turn = 'p';
		}
	}
}

void Arena::Draw(sf::RenderWindow * window)
{
	GameObject::Draw(window);
	e->Draw(window);
}

void Arena::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);
	e->Update(window, dt);

	//Battle(playerCharacter, e->m_selectedCharacter[0]);
}


Arena::~Arena()
{
	delete e; //Delete enemy when Arena deletes (after player leaves battle screen)
}
