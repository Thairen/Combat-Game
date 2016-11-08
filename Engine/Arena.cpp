#include "Arena.h"



Arena::Arena(const sf::Vector2f& pos, Character* attacker) : GameObject("", pos) //Perhaps throw backgrounds into this class?
{
	e = new Enemy(sf::Vector2f(0.f, 0.f)); //Init the enemy
	player = attacker;
}

void Arena::Battle(Character * attacker, Character * defender)
{
	char turn = 'p';

	//INFINITE LOOP RIGHT MEOW!!!!!!!!!!!!!!!!!!
	while (attacker->GetCurrent("Health") > 0 && defender->GetCurrent("Health") > 0)
	{
		if (turn == 'p')
		{
			turn = 'e';
		}
		if (turn == 'e')
		{
			turn = 'p';
		}
	}
}


Arena::~Arena()
{
	delete e; //Delete enemy when Arena deletes (after player leaves battle screen)
}
