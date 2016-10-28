#include "Player.h"



Player::Player(float gold, Location loc) : m_gold(gold), m_location(loc)
{
}

void Player::AddCharacter(Character* character)
{
	m_characterList.push_back(character);
}
