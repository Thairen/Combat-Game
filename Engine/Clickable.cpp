#include "Clickable.h"



Clickable::Clickable(const sf::Vector2f& pos, std::string buttonText) : GameObject("Sprites/UI.png", pos),
m_isHovering(false)
{
	m_font.loadFromFile("Fonts/kenpixel_high_square.ttf");
	m_sprite.setTextureRect(sf::IntRect(0.f, 50.f, 190.f, 45.f));
	m_sprite.setOrigin(5, 5);
	m_text.setString(buttonText);
	m_text.setFont(m_font);
	m_text.setColor(sf::Color::White);
	m_text.setPosition(this->GetPosition().x + 50.f, this->GetPosition().y - 5.f);
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
		mousePos.x <= this->GetPosition().x && //needs to be set size
		mousePos.y >= this->GetPosition().y &&
		mousePos.y <= this->GetPosition().y)
	{
		m_isHovering = true;
	}

	else
	{
		m_isHovering = false;
	}
}

