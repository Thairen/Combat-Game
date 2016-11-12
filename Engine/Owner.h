#pragma once
#include "GameObject.h"
#include "Character.h"

class Owner : public GameObject
{
public:
	Owner(const sf::Vector2f& pos);
	~Owner();

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);

	void AddCharacter(Character* character);

	Character* m_selectedCharacter[1]; //Extend later for larger combat scenarios....

protected:
	std::vector<Character*> m_characterList; // List of the player's characters
};

