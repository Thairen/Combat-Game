#include "Character.h"



Character::Character(CharacterType type, const sf::Vector2f & pos) : GameObject("Sprites/chars.png", pos),
m_type(type)
{
	//Extend these into a vector of stats? (More convienant to work with? IE COMPONENT SYSTEM
	m_health = new Stat("Health", 50, 50);
	m_strength = new Stat("Strength", 10, 10);
	m_defense = new Stat("Defense", 10, 10);
	m_level = new Stat("Level", 1, 100);
	m_exp = new Stat("XP", 0, 100);

	SetCharacter();
	
	m_sprite.setOrigin(m_sprite.getScale().x * 0.5f, m_sprite.getScale().y * 0.5f); 
}

Character::~Character()
{
	delete m_health, m_strength, m_defense, m_level, m_exp; //Delete them pointers (vector of stats more convienant for sure here
}

void Character::Update(sf::RenderWindow* window, float dt)
{
	GameObject::Update(window, dt);
}

void Character::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}

void Character::SetCharacter()
{
	switch (m_type)
	{
	case CharacterType::Aerith:
		m_sprite.setTextureRect(sf::IntRect(0, 200, 190, 180)); //Aerith
		break;

	case CharacterType::Cloud:
		m_sprite.setTextureRect(sf::IntRect(0, 0, 230, 200)); //Cloud
		break;

	case CharacterType::Barrett:
		m_sprite.setTextureRect(sf::IntRect(220, 0, 240, 230)); //Barrett
		break;

	case CharacterType::Tifa:
		m_sprite.setTextureRect(sf::IntRect(490, 0, 240, 230)); //Tifa
		break;

	case CharacterType::CaitSith:
		m_sprite.setTextureRect(sf::IntRect(0, 380, 260, 230)); //CaitSith
		break;

	case CharacterType::RedX:
		m_sprite.setTextureRect(sf::IntRect(240, 220, 270, 160)); //RedXIII
		break;

	case CharacterType::Yuffie:
		m_sprite.setTextureRect(sf::IntRect(500, 200, 230, 200)); //Tifa
		break;

	case CharacterType::Cid:
		m_sprite.setTextureRect(sf::IntRect(280, 420, 200, 180)); //Cid
		break;

	case CharacterType::Vincent:
		m_sprite.setTextureRect(sf::IntRect(470, 410, 180, 180)); //Tifa
		break;
	}
}
