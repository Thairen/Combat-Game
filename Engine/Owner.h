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

protected:
	std::vector<Character*> m_characterList; // List of the player's characters
};

