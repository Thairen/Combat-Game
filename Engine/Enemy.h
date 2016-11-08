#pragma once
#include "Owner.h"
class Enemy : public Owner
{
public:
	Enemy(const sf::Vector2f& pos);
	~Enemy();

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);
};

