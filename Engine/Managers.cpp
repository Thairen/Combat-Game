#include "Managers.h"
#include "Character.h"
#include <iostream>

AnimationManager::AnimationManager(Character* owner) : m_owner(owner),
m_column(0), m_row(0), m_timer(0.35f), m_timeElapsed(0.f)
{
}

void AnimationManager::Update(sf::RenderWindow* window, float dt)
{
	//Starts idle (base row = 0, base column = 0)
	m_owner->m_sprite.setTextureRect(sf::IntRect(m_column * 96, m_row * 96, 96, 96));

	LoopAnimation(dt);
}

int AnimationManager::ChooseRow(AnimationType type)
{
	switch (type)
	{
	case AnimationType::ATTACK:
	{
		return m_row = 4;
		break;
	}
	case AnimationType::DEFEND:
	{
		return m_row = 1;
		break;
	}
	case AnimationType::SKILL:
	{
		return m_row = 6;
		break;
	}
	case AnimationType::ITEM:
	{
		return m_row = 5;
		break;
	}
	case AnimationType::HIT:
	{
		return m_row = 3;
		break;
	}
	case AnimationType::DEAD:
	{
		return m_row = 12;
		break;
	}
	default:
	{
		return m_row = 0;
		break;
	}
	}
}

void AnimationManager::LoopAnimation(float dt)
{
	m_timeElapsed -= dt;

	if (m_timeElapsed <= 0)
	{
		m_timeElapsed = m_timer;
		m_column++;
	}

	if (m_column > 3)

	{
		m_column = 0;

		if (m_row != 18) // If character isn't dead
		{
			m_row = 0; //switch back to idle (maybe better way to do)
		}
	}
}
/*
AudioManager::AudioManager()
{
	LoadSounds(); //Load the sounds when the manager is created..
}

void AudioManager::PlaySound(SoundType type)
{
	m_soundInstance[type].play(); //Play the sound
}

void AudioManager::LoadSounds()
{
	//Here's were we load sounds
	//Uncomment when files are in project, add sounds as desired followin this method


	//m_sounds[SoundType::SHOOTING].loadFromFile("");
	//m_sounds[SoundType::DEATH].loadFromFile("");
	//m_sounds[SoundType::DAMAGE].loadFromFile("");

	//Set the buffer for the sounds
	for (int i = 0; i < SoundType::COUNT; i++)
	{
		m_soundInstance[i].setBuffer(m_sounds[i]);
	}
}
*/