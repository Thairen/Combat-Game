#include "Character.h"
#include "Owner.h"
#include "Enemy.h"
#include "Stat.h"
#include "Panel.h"
#include "Managers.h"

Character::Character(std::string texturePath, const sf::Vector2f & pos, Owner* owner) : GameObject(texturePath, pos),
hasActed(false), m_target(sf::Vector2f(0,0)), hasArrived(false)
{
	//Extend these into a vector of stats? (More convienant to work with?)
	m_name = SetName();
	m_health = new Stat("Health", 50, rand() % 30 + 10);
	m_strength = new Stat("Strength", 10, rand() % 7 + 5);
	m_defense = new Stat("Defense", 10, rand() % 5 + 5);
	m_speed = new Stat("Speed", 10, rand() % 4 + 4);
	m_level = new Stat("Level", 1, 100);
	m_exp = new Stat("XP", 0, 100);

	m_panel = new PanelWithStats(sf::Vector2f(this->GetPosition().x - 200, this->GetPosition().y + 230), this);
	m_panel->m_sprite.setScale(2.0f, 2.0f);

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
	GameObject::Update(window, dt);

	MoveTo(dt);

	anim->Update(window, dt);
}

void Character::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
	m_panel->Draw(window);
}

//// FOR CONVIENCE WHEN READING STATS TO A TEXT OBJECT
/////////////////////////////////////////////////////////////////////////
float Character::GetCurrent(std::string desired)
{
	float result;

	if (desired == "Health")
		result = m_health->GetCurrent();

	if (desired == "Strength")
		result = m_strength->GetCurrent();

	if (desired == "Defense")
		result = m_defense->GetCurrent();

	if (desired == "Speed")
		result = m_speed->GetCurrent();

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

	if (desired == "Speed")
		result = m_speed->GetMax();

	if (desired == "Level")
		result = m_level->GetMax();

	if (desired == "XP")
		result = m_exp->GetMax();

	return result;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

float Character::Attack()
{
	return m_strength->GetCurrent();
}

void Character::TakeDamage(float dmg)
{
	 dmg -= m_defense->GetCurrent();

	 anim->ChooseRow(HIT);

	 if (dmg > 0)
		m_health->SubtractCurrent(dmg);
}

void Character::MoveTo(float dt)
{
	if (m_target.x != 0 && m_target.y != 0) // If target isn't initialized yet
	{
		sf::Vector2f currentPos = this->GetPosition();
		sf::Vector2f targetPos = m_target; // Enemies Pos

		float difference = targetPos.x - currentPos.x;

		if (!hasArrived)
		{
			anim->ChooseRow(MOVE);
		}

		if (difference > 10) // If character is AI
		{
			currentPos.x += dt * 500;
		}

		if (difference < -10) // AI to player Character
		{

			currentPos.x -= dt * 500;
		}

		this->SetPos(currentPos);

		if (currentPos.x >= targetPos.x - 10.f || currentPos.x >= targetPos.x + 10.f ||
			currentPos.x <= targetPos.x + 10.f || currentPos.x <= targetPos.x - 10.f)
		{
			hasArrived = true;
		}

	}
}

void Character::SetOwner(Owner * owner)
{
	m_owner = owner;

	owner->AddCharacter(this); // BELIEVE IT!!
}

std::string Character::SetName() //Need to improve on this list for more unique and better names
{
	std::string name;
	int num = rand() % 15;

	name = prefix[num] + mid[num] + suffix[num];

	return name;
}
