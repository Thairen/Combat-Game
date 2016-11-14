#include "Managers.h"
#include "Character.h"
#include <iostream>

AnimationManager::AnimationManager(Character* owner) : m_owner(owner),
m_column(0), m_row(0), m_timer(0.5f), m_timeElapsed(0.f)
{
	//m_sprite.setScale = owner->m_sprite.getScale();
}

void AnimationManager::Update(sf::RenderWindow* window, float dt)
{
	//Starts idle (base row = 0, base column = 0)

	m_owner->m_sprite.setTextureRect(sf::IntRect(m_column * 96, m_row * 65 + 5, 90, 90));

	LoopAnimation(dt);
}

void AnimationManager::LoopAnimation(float dt)
{
	if (m_column > 3)

	{
		m_column = 0;
	}

	m_timeElapsed -= dt;

	if (m_timeElapsed <= 0)
	{
		m_timeElapsed = m_timer;
		m_column++;
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