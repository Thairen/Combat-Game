#include "Arena.h"
#include "Enemy.h"
#include "Character.h"


Arena::Arena(const sf::Vector2f& pos, Character* attacker) : GameObject("", pos), //Perhaps throw backgrounds into this class?
m_attackTimer(0.5f)
{
	e = new Enemy(sf::Vector2f(0.f, 0.f)); //Init the enemy
	playerCharacter = attacker;
	enemyCharacter = e->m_selectedCharacter[0];

	m_buttonPanel = new PanelWithButtons(sf::Vector2f(attacker->GetPosition().x, attacker->GetPosition().y + 230), attacker);
	m_buttonPanel->m_sprite.setScale(2.0f, 2.0f);
}

void Arena::Battle(Character* attacker, Character* defender, float dt)
{
	if (turn == 'p')
	{
		defender->SetActedBool(false);

		if (!attacker->HasActed())
		{
			Action(m_buttonPanel->IsSelected(), attacker, defender, dt);
		}

		//When action is done, swap turn
		if (attacker->HasActed())
		{
			m_elapsedTime -= dt;

			if (m_elapsedTime <= 0.f)
			{
				turn = 'e';
				m_elapsedTime = m_attackTimer;
			}
		}
	}
	if (turn == 'e')
	{	
		attacker->SetActedBool(false);

		if (!defender->HasActed())
		{
			EnemyAction(defender, attacker, dt);
		}

		if (defender->HasActed())
		{
			m_elapsedTime -= dt;

			if (m_elapsedTime <= 0.f)
			{
				turn = 'p';
				m_elapsedTime = m_attackTimer;
			}
		}
	}
}

void Arena::Action(ButtonType type, Character* actor, Character* target, float dt)
{
	switch (type)
	{

	case ButtonType::Empty: // NO BUTTON SELECTED
		break;

	case ButtonType::Attack:
	{
		actor->SetTarget(target->GetPosition());
		actor->anim->ChooseRow(ATTACK);
		target->TakeDamage(actor->Attack());
		actor->SetActedBool(true);
		break;
	}


	case ButtonType::Skill:
	{
		//open skill panel
		actor->anim->ChooseRow(SKILL);
		actor->SetActedBool(true);
		break;
	}

	case ButtonType::Item:
	{
		//open item panel
		actor->anim->ChooseRow(ITEM);
		actor->SetActedBool(true);
		break;
	}

	case ButtonType::Defend:
	{
		//Defend Behavior
		actor->anim->ChooseRow(DEFEND);
		actor->SetActedBool(true);
		break;
	}

	}
}

void Arena::EnemyAction(Character * actor, Character * target, float dt)
{
	int choice = rand() % 4;
	
	switch (choice)
	{
	case 0: // Attack
	{
		actor->SetTarget(target->GetPosition());
		actor->anim->ChooseRow(ATTACK);
		target->TakeDamage(actor->Attack());
		actor->SetActedBool(true);
		break;

	}
	case 1: // Defend
	{
		actor->anim->ChooseRow(DEFEND);
		actor->SetActedBool(true);
		break;
	}
	case 2: // Skill
	{
		actor->anim->ChooseRow(SKILL);
		actor->SetActedBool(true);
		break;
	}
	case 3: // Item
	{
		actor->anim->ChooseRow(ITEM);
		actor->SetActedBool(true);
		break;
	}
	}
}

float Arena::Approach(float goal, float current, float dt)
{
	float difference = goal - current;

	if (difference > dt)
		return current + dt;
	if (difference < -dt)
		return current - dt;

	return goal;
}

void Arena::Draw(sf::RenderWindow * window)
{
	GameObject::Draw(window);
	m_buttonPanel->Draw(window);
	e->Draw(window);
}

void Arena::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);
	m_buttonPanel->Update(window, dt);
	e->Update(window, dt);

	Battle(playerCharacter, enemyCharacter, dt);
}


Arena::~Arena()
{
	delete e; //Delete enemy when Arena deletes (after player leaves battle screen)
}
