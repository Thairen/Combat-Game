#include "Clickable.h"
#include "Character.h"
#include <iostream>


Clickable::Clickable(const sf::Vector2f& pos, ButtonType buttonType, Character* owner) : GameObject("Sprites/UI.png", pos),
m_isHovering(false), m_type(buttonType), m_owner(owner), m_isClicked(false)
{
	SetType(buttonType);
	m_font.loadFromFile("Fonts/kenpixel_high_square.ttf");
	m_sprite.setTextureRect(sf::IntRect(0, 50, 190, 48));
	m_sprite.setScale(0.8f, 0.8f);
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
	Clicked();
}

void Clickable::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
	window->draw(m_text);
}

void Clickable::SetType(ButtonType type)
{
	switch (type)
	{

	case ButtonType::Attack:
	{
		buttonText = "Attack";
		break;
	}

	case ButtonType::Skill:
	{
		buttonText = "Skill";
		break;
	}

	case ButtonType::Item:
	{
		buttonText = "Item";
		break;
	}

	case ButtonType::Escape:
	{
		buttonText = "Escape";
		break;
	}

	}
}

void Clickable::Hovering(sf::RenderWindow* window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

	if (mousePos.x >= this->GetPosition().x &&                  
		mousePos.x <= this->GetPosition().x + this->GetPosition().x / 2 && 
		mousePos.y >= this->GetPosition().y &&
		mousePos.y <= this->GetPosition().y + 30)
	{
		m_isHovering = true;
		m_sprite.setColor(sf::Color(205,205,205));
	}

	else
	{
		m_isHovering = false;
		m_sprite.setColor(sf::Color(255, 255, 255));
	}
}

void Clickable::Clicked()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_isHovering)
	{
		m_sprite.setTextureRect(sf::IntRect(0, 98, 190, 45));  //Move this to when button pressed
		m_sprite.setColor(sf::Color(0, 255, 0));
		m_isClicked = true;
	}

	else
	{
		m_sprite.setTextureRect(sf::IntRect(0, 50, 190, 48));
		m_isClicked = false;
	}
}





