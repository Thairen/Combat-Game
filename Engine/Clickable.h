#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"

class Clickable : public GameObject
{
public:
	Clickable(const sf::Vector2f& pos); //Button was taken o.O so clickable..

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);

};

