#include "Clickable.h"
#include <iostream>


Clickable::Clickable(const sf::Vector2f& pos, std::string buttonText) : GameObject("Sprites/UI.png", pos),
m_isHovering(false)
{
	m_font.loadFromFile("Fonts/kenpixel_high_square.ttf");
	m_sprite.setTextureRect(sf::IntRect(0, 50, 190, 48));
	m_sprite.setOrigin(m_sprite.getScale().x * 0.5f, m_sprite.getScale().y * 0.5f);
	m_text.setString(buttonText);
	m_text.setFont(m_font);
	m_text.setColor(sf::Color::White);
	m_text.setPosition(this->GetPosition().x + 35, this->GetPosition().y - 5);
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

	//Fix this for improved button response
	if (mousePos.x >= this->GetPosition().x &&                   //Here
		mousePos.x <= this->GetPosition().x + this->GetPosition().x / 2 && 
		mousePos.y >= this->GetPosition().y &&
		mousePos.y <= this->GetPosition().y + 50) //Here
	{
		m_isHovering = true;
		m_sprite.setTextureRect(sf::IntRect(0, 98, 190, 45)); //Change this with perhaps a draw border, push in should happen on click
	}

	else
	{
		m_isHovering = false;
		m_sprite.setTextureRect(sf::IntRect(0, 50, 190, 48));
	}
}

