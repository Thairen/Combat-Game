#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class Character;

enum SoundType //Sound types, COUNT always last!!!
{
	SHOOTING,
	DEATH,
	DAMAGE,
	COUNT
};

enum AnimationType
{
	IDLE,
	ATTACK,
	DEFEND,
	SKILL,
	ITEM,
	HIT,
	DEAD
};

class AnimationManager
{
public:
	AnimationManager(Character* owner); // Take in sprite and position
	virtual void Update(sf::RenderWindow* window, float dt);

	int GetRow() { return m_row; }

	int ChooseRow(AnimationType type);
	void LoopAnimation(float dt);

protected:

	Character* m_owner;

	float m_timeElapsed;
	float m_timer;

	int m_column;
	int m_row;
};
// Still need to create system for sprites animations and then this Manager should be complete

//class AudioManager
//{
//public:
//	AudioManager();
//
//	void PlaySound(SoundType type); //Play sound of chose type
//	void LoadSounds(); //Load the sounds into the buffer, then upload for the instance

//private:

	//Array size themselves as sounds are added to the SoundType enum... Don't forget to load them!!!

//	sf::SoundBuffer m_sounds[SoundType::COUNT]; //Array of useable sound files
//	sf::Sound m_soundInstance[SoundType::COUNT]; //Array of currently instanced sounds

//};
