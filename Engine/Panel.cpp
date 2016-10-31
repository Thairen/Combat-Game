#include "Panel.h"
#include "Character.h"


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

PanelWithStats::PanelWithStats(const sf::Vector2f & pos, Character* owner) : Panel(pos),
m_owner(owner)
{
	m_font.loadFromFile("Fonts/kenpixel_high_square.ttf");
}

PanelWithStats::~PanelWithStats()
{
}

void PanelWithStats::Draw(sf::RenderWindow * window)
{
	Panel::Draw(window);
	ShowStats(window);
}

void PanelWithStats::Update(sf::RenderWindow * window, float dt)
{
	Panel::Update(window, dt);
}

void PanelWithStats::ShowStats(sf::RenderWindow * window)
{
	name.setFont(m_font);
	name.setString(m_owner->m_name);
	name.setPosition(this->GetPosition().x + 25, this->GetPosition().y + 20);
	name.setColor(sf::Color::Black);
	window->draw(name);

	health.setFont(m_font);
	health.setString("HP: " + std::to_string((int)m_owner->GetCurrent("Health")) + " / " + std::to_string((int)m_owner->GetMax("Health")));
	health.setPosition(this->GetPosition().x + 25, this->GetPosition().y + 50);
	health.setColor(sf::Color::Black);
	window->draw(health);

	strength.setFont(m_font);
	strength.setString("Str: " + std::to_string((int)m_owner->GetCurrent("Strength")));
	strength.setPosition(this->GetPosition().x + 25, this->GetPosition().y + 80);
	strength.setColor(sf::Color::Black);
	window->draw(strength);

	defense.setFont(m_font);
	defense.setString("Def: " + std::to_string((int)m_owner->GetCurrent("Defense")));
	defense.setPosition(this->GetPosition().x + 25, this->GetPosition().y + 110);
	defense.setColor(sf::Color::Black);
	window->draw(defense);

	level.setFont(m_font);
	level.setString("Lvl: " + std::to_string((int)m_owner->GetCurrent("Level")));
	level.setPosition(this->GetPosition().x + 25, this->GetPosition().y + 140);
	level.setColor(sf::Color::Black);
	window->draw(level);
}

void PanelWithStats::SetOwningCharacter(Character * character)
{
	m_owner = character;
}
