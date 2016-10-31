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
	button = new Clickable(sf::Vector2f(80.f, 600.f), "Attack");
	button->m_sprite.setScale(0.8f, 0.8f);

	button1 = new Clickable(sf::Vector2f(80.f, 650.f), "Defend");
	button1->m_sprite.setScale(0.8f, 0.8f);

	button2 = new Clickable(sf::Vector2f(245.f, 600.f), "Items");
	button2->m_sprite.setScale(0.8f, 0.8f);

	button3 = new Clickable(sf::Vector2f(245.f, 650.f), "Escape");
	button3->m_sprite.setScale(0.8f, 0.8f);
}

PanelWithButtons::~PanelWithButtons()
{
	delete button, button1, button2, button3;
}

void PanelWithButtons::Draw(sf::RenderWindow * window)
{
	Panel::Draw(window);
	button->Draw(window);
	button1->Draw(window);
	button2->Draw(window);
	button3->Draw(window);
}

void PanelWithButtons::Update(sf::RenderWindow * window, float dt)
{
	Panel::Update(window, dt);
	button->Update(window, dt);
	button1->Update(window, dt);
	button2->Update(window, dt);
	button3->Update(window, dt);
}
