#include "Character.h"
#include "Owner.h"
#include "Enemy.h"


Character::Character(CharacterType type, const sf::Vector2f & pos, Owner* owner) : GameObject("Sprites/chars.png", pos),
m_type(type)
{
	//Extend these into a vector of stats? (More convienant to work with? IE COMPONENT SYSTEM
	m_health = new Stat("Health", 50, rand() % 30 + 10);
	m_strength = new Stat("Strength", 10, rand() % 7 + 5);
	m_defense = new Stat("Defense", 10, rand() % 5 + 5);
	m_level = new Stat("Level", 1, 100);
	m_exp = new Stat("XP", 0, 100);

	m_panel = new PanelWithStats(sf::Vector2f(this->GetPosition().x - 200, this->GetPosition().y + 160), this);
	m_panel->m_sprite.setScale(2.0f, 2.0f);

	SetCharacter();
	
	m_sprite.setOrigin(m_sprite.getScale().x * 0.5f, m_sprite.getScale().y * 0.5f); 

	SetOwner(owner);

	Enemy* enemy = dynamic_cast<Enemy*>(owner);

	if (enemy)
	{
		m_panel->SetPos(sf::Vector2f(this->GetPosition().x, this->GetPosition().y + 160));
	}
}

Character::~Character()
{
	delete m_health, m_strength, m_defense, m_level, m_exp; //Delete them pointers (vector of stats more convienant for sure here
}

void Character::Update(sf::RenderWindow* window, float dt)
{
	m_panel->Update(window, dt);
	GameObject::Update(window, dt);
}

void Character::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
	m_panel->Draw(window);
}

float Character::GetCurrent(std::string desired)
{
	float result;

	if (desired == "Health")
		result = m_health->GetCurrent();

	if (desired == "Strength")
		result = m_strength->GetCurrent();

	if (desired == "Defense")
		result = m_defense->GetCurrent();

	if (desired == "Level")
		result = m_level->GetCurrent();

	if (desired == "XP")
		result = m_exp->GetCurrent();

	return result;
}

float Character::GetMax(std::string desired)
{
	float result;

	if (desired == "Health")
		result = m_health->GetMax();

	if (desired == "Strength")
		result = m_strength->GetMax();

	if (desired == "Defense")
		result = m_defense->GetMax();

	if (desired == "Level")
		result = m_level->GetMax();

	if (desired == "XP")
		result = m_exp->GetMax();

	return result;
}

void Character::SetOwner(Owner * owner)
{
	m_owner = owner;

	owner->AddCharacter(this);
}

void Character::SetCharacter()
{
	switch (m_type)
	{
	case CharacterType::Aerith:
		m_sprite.setTextureRect(sf::IntRect(0, 200, 190, 180)); //Aerith
		m_name = "Aerith";
		break;

	case CharacterType::Cloud:
		m_sprite.setTextureRect(sf::IntRect(0, 0, 230, 200)); //Cloud
		m_name = "Cloud";
		break;

	case CharacterType::Barrett:
		m_sprite.setTextureRect(sf::IntRect(220, 0, 240, 230)); //Barrett
		m_name = "Barrett";
		break;

	case CharacterType::Tifa:
		m_sprite.setTextureRect(sf::IntRect(490, 0, 240, 210)); //Tifa
		m_name = "Tifa";
		break;

	case CharacterType::CaitSith:
		m_sprite.setTextureRect(sf::IntRect(0, 380, 260, 230)); //CaitSith
		m_name = "Cait Sith";
		break;

	case CharacterType::RedX:
		m_sprite.setTextureRect(sf::IntRect(240, 220, 270, 160)); //RedXIII
		m_name = "Red XIII";
		break;

	case CharacterType::Yuffie:
		m_sprite.setTextureRect(sf::IntRect(500, 200, 230, 200)); //Tifa
		m_name = "Yuffie";
		break;

	case CharacterType::Cid:
		m_sprite.setTextureRect(sf::IntRect(280, 420, 200, 180)); //Cid
		m_name = "Cid";
		break;

	case CharacterType::Vincent:
		m_sprite.setTextureRect(sf::IntRect(470, 410, 180, 180)); //Vincent
		m_name = "Vincent";
		break;
	}
}
