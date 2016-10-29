#include "Clickable.h"
#include <iostream>


Clickable::Clickable(const sf::Vector2f& pos, std::string buttonText) : GameObject("Sprites/UI.png", pos),
m_isHovering(false)
{
	m_font.loadFromFile("Fonts/kenpixel_high_square.ttf");
	m_sprite.setTextureRect(sf::IntRect(0.f, 50.f, 190.f, 45.f));
	m_sprite.setOrigin(m_sprite.getScale().x * 0.5f, m_sprite.getScale().y * 0.5);
	m_text.setString(buttonText);
	m_text.setFont(m_font);
	m_text.setColor(sf::Color::White);
	m_text.setPosition(this->GetPosition().x + 50, this->GetPosition().y);
}

void Clickable::Update(sf::RenderWindow* window, float dt)
{
	GameObject::Update(window, dt);
	Hovering(window);
}

void Clickable::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
	window->draw(m_text);
}

void Clickable::Hovering(sf::RenderWindow* window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

	if (mousePos.x >= this->GetPosition().x &&
		mousePos.x <= this->GetPosition().x + this->GetPosition().x / 2 && 
		mousePos.y >= this->GetPosition().y &&
		mousePos.y <= this->GetPosition().y + 50.f)
	{
		m_isHovering = true;
		m_sprite.setTextureRect(sf::IntRect(0.f, 98.f, 190.f, 45.f));
	}

	else
	{
		m_isHovering = false;
		m_sprite.setTextureRect(sf::IntRect(0.f, 50.f, 190.f, 45.f));
	}
}

