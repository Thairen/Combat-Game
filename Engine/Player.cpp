#include "Player.h"

Player::Player(const sf::Vector2f& pos, float gold, Location loc) : Owner(pos), m_gold(gold), m_location(loc)
{
	m_actionPanel = new PanelWithButtons(sf::Vector2f(250, 510));
	m_actionPanel->m_sprite.setScale(2.0, 2.0);
}

void Player::Update(sf::RenderWindow* window, float dt)
{
	Owner::Update(window,dt);

	//Loop not ideal, Temp until Arena is built to handle passing in the proper character for draw/update
	for (int i = 0; i < m_characterList.size(); i++)
	{
		m_characterList[i]->Update(window, dt);
	}

	m_actionPanel->Update(window, dt);
}

void Player::Draw(sf::RenderWindow* window)
{
	Owner::Draw(window);

	//Loop not ideal, Temp until Arena is built to handle passing in the proper character for draw/update
	for (int i = 0; i < m_characterList.size(); i++)
	{
		m_characterList[i]->Draw(window);
	}

	m_actionPanel->Draw(window);
}
