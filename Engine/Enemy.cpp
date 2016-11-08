#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f & pos) : Owner(pos)
{
	starter = new Character(CharacterType::Vincent, sf::Vector2f(1000.f, 350.f), this);
	starter->m_sprite.setScale(0.8f, 0.8f);
	AddCharacter(starter);
}

Enemy::~Enemy()
{
}

void Enemy::Update(sf::RenderWindow * window, float dt)
{
	Owner::Update(window, dt);

	//Loop not ideal, Temp until Arena is built to handle passing in the proper character for draw/update
	//In base class perhaps make a selected character thing of some sort. (Won't really matter for Enemy)
	for (int i = 0; i < m_characterList.size(); i++)
	{
		m_characterList[i]->Update(window, dt);
	}
}

void Enemy::Draw(sf::RenderWindow * window)
{
	Owner::Draw(window);

	//Loop not ideal, Temp until Arena is built to handle passing in the proper character for draw/update
	for (int i = 0; i < m_characterList.size(); i++)
	{
		m_characterList[i]->Draw(window);
	}
}
