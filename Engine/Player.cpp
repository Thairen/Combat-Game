#include "Player.h"



Player::Player(float gold, Location loc) : m_gold(gold), m_location(loc)
{
	m_actionPanel = new PanelWithButtons(sf::Vector2f(250, 510));
	m_actionPanel->m_sprite.setScale(2.0, 2.0);
}

void Player::Update(sf::RenderWindow* window, float dt)
{
	m_actionPanel->Update(window, dt);
}

void Player::Draw(sf::RenderWindow* window)
{
	m_actionPanel->Draw(window);
}

void Player::AddCharacter(Character* character)
{
	m_characterList.push_back(character);
}
