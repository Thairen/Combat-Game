#include "Player.h"

Player::Player(const sf::Vector2f& pos, float gold, Location loc) : Owner(pos), m_gold(gold), m_location(loc)
{
	//TEMP ============== Panel requires a character to Initilize. FIX ================================
	starter = new Character(CharacterType::Yuffie, sf::Vector2f(250.f, 350.f), this);
	starter->m_sprite.setScale(-0.8f, 0.8f);
	this->AddCharacter(starter);
	//=================================================================================================
}

void Player::Update(sf::RenderWindow* window, float dt)
{
	Owner::Update(window,dt);

	//Loop not ideal, Temp until Arena is built to handle passing in the proper character for draw/update
	for (int i = 0; i < m_characterList.size(); i++)
	{
		m_characterList[i]->Update(window, dt);
	}
}

void Player::Draw(sf::RenderWindow* window)
{
	Owner::Draw(window);

	//Loop not ideal, Temp until Arena is built to handle passing in the proper character for draw/update
	for (int i = 0; i < m_characterList.size(); i++)
	{
		m_characterList[i]->Draw(window);
	}
}
