#include "Panel.h"



Panel::Panel(const sf::Vector2f& pos) : GameObject("Sprites/UI.png", pos)
{
	m_sprite.setTextureRect(sf::IntRect(190, 100, 100, 100));
	m_sprite.setOrigin(m_sprite.getScale().x * 0.5f, m_sprite.getScale().y * 0.5f);
}

void Panel::Draw(sf::RenderWindow * window)
{
	GameObject::Draw(window);
}

void Panel::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);
}

PanelWithButtons::PanelWithButtons(const sf::Vector2f& pos) : Panel(pos)
{
	m_buttonList[0] = new Clickable(sf::Vector2f(270.f, 525.f), "Attack");

	m_buttonList[1] = new Clickable(sf::Vector2f(270.f, 566.f), "Defend");

	m_buttonList[2] = new Clickable(sf::Vector2f(270.f, 608.f), "Items");

	m_buttonList[3] = new Clickable(sf::Vector2f(270.f, 650.f), "Escape");

}

PanelWithButtons::~PanelWithButtons()
{
	for (int i = 0; i < 4; i++)
	{
		delete m_buttonList[i];
	}
}

void PanelWithButtons::Draw(sf::RenderWindow * window)
{
	Panel::Draw(window);

	for (int i = 0; i < 4; i++)
	{
		m_buttonList[i]->Draw(window);
	}
}

void PanelWithButtons::Update(sf::RenderWindow * window, float dt)
{
	Panel::Update(window, dt);

	for (int i = 0; i < 4; i++)
	{
		m_buttonList[i]->Update(window, dt);
	}
}
