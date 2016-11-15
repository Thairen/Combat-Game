#include "Character.h"
#include "Owner.h"
#include "Enemy.h"
#include "Stat.h"
#include "Panel.h"
#include "Managers.h"

Character::Character(std::string texturePath, const sf::Vector2f & pos, Owner* owner) : GameObject(texturePath, pos)
{
	//Extend these into a vector of stats? (More convienant to work with? IE COMPONENT SYSTEM
	m_name = SetName();
	m_health = new Stat("Health", 50, rand() % 30 + 10);
	m_strength = new Stat("Strength", 10, rand() % 7 + 5);
	m_defense = new Stat("Defense", 10, rand() % 5 + 5);
	m_level = new Stat("Level", 1, 100);
	m_exp = new Stat("XP", 0, 100);

	m_panel = new PanelWithStats(sf::Vector2f(this->GetPosition().x - 200, this->GetPosition().y + 230), this);
	m_panel->m_sprite.setScale(2.0f, 2.0f);

	m_buttonPanel = new PanelWithButtons(sf::Vector2f(this->GetPosition().x, this->GetPosition().y + 230), this);
	m_buttonPanel->m_sprite.setScale(2.0f, 2.0f);

	m_sprite.setOrigin(m_sprite.getScale().x * 0.5f, m_sprite.getScale().y * 0.5f);
	m_sprite.setTextureRect(sf::IntRect(10, 40, 80, 85));
	m_sprite.setScale(-2.2f, 2.2f);

	SetOwner(owner);
	

	Enemy* enemy = dynamic_cast<Enemy*>(owner);

	//If owning character is an enemy
	//=========================================
	if (enemy)
	{
		m_panel->SetPos(sf::Vector2f(this->GetPosition().x, this->GetPosition().y + 230));
		m_buttonPanel->SetVisible(false);
		m_sprite.setScale(2.2f, 2.2f);
	}
	//============================================

	anim = new AnimationManager(this);

}

Character::~Character()
{
	delete m_health, m_strength, m_defense, m_level, m_exp; //Delete them pointers (vector of stats more convienant for sure here
}

void Character::Update(sf::RenderWindow* window, float dt)
{
	m_panel->Update(window, dt);
	m_buttonPanel->Update(window, dt);
	GameObject::Update(window, dt);

	anim->Update(window, dt);

	Action(m_buttonPanel->IsSelected());
}

void Character::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
	m_panel->Draw(window);
	m_buttonPanel->Draw(window);
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

float Character::Attack()
{
	return m_strength->GetCurrent();
}

void Character::TakeDamage(float dmg)
{
	 dmg -= m_defense->GetCurrent();

	 m_health->SubtractCurrent(dmg);
}

void Character::SetOwner(Owner * owner)
{
	m_owner = owner;

	owner->AddCharacter(this);
}

void Character::Action(ButtonType type)
{
	switch (type)
	{

	case ButtonType::Empty: // NO BUTTON SELECTED
		break;

	case ButtonType::Attack:
	{
		//this->Attack();
		anim->ChooseRow(ATTACK);
		break;
	}

	case ButtonType::Skill:
	{
		//open skill panel
		anim->ChooseRow(SKILL);
		break;
	}

	case ButtonType::Item:
	{
		//open item panel
		anim->ChooseRow(ITEM);
		break;
	}

	case ButtonType::Defend:
	{
		//Defend Behavior
		anim->ChooseRow(DEFEND);
		break;
	}

	}
}

std::string Character::SetName()
{
	std::string name;
	int num = rand() % 15;

	name = prefix[num] + mid[num] + suffix[num];

	return name;
}
