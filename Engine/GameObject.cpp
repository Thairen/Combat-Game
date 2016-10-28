#include "stdafx.h"
#include "Game.h"
#include "GameObject.h"
#include <iostream>

GameObject::GameObject(std::string texturePath, const sf::Vector2f & pos)
	: m_pos(pos)
	, m_destroyed(false)
{
	// Load the texture
	// Assign the sprite		
	m_texture.loadFromFile(texturePath);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_sprite.getTextureRect().width * 0.5f, m_sprite.getTextureRect().height * 0.5f);
}

void GameObject::Destroy()
{
	m_destroyed = true;
}

bool GameObject::IsDestroyed()
{
	return m_destroyed;
}


void GameObject::Draw(sf::RenderWindow * window)
{
	window->draw(m_sprite);
}

void GameObject::Update(sf::RenderWindow * window, float dt)
{
	m_sprite.setPosition(m_pos);
}

void GameObject::SetPos(const sf::Vector2f & pos)
{
	m_pos = pos;
}

void GameObject::SetOwner(Game * owner)
{
	m_owner = owner;
}

