#include "Clickable.h"



Clickable::Clickable(const sf::Vector2f& pos) : GameObject("Sprites/Button.png", pos)
{
	//m_sprite.setTextureRect(sf::IntRect(177.f, 204.f, 300.f, 200.f));
}

void Clickable::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);
}

void Clickable::Draw(sf::RenderWindow * window)
{
	GameObject::Draw(window);
}

