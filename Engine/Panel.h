#pragma once
#include "GameObject.h"
#include "Clickable.h"


class Character;

class Panel : public GameObject
{
public:
	Panel(const sf::Vector2f& pos, Character* owner);
	
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

protected:

	Character* m_owner;
};



class PanelWithButtons : public Panel
{
	//Modify buttons to set the position relative to the panel
public:

	PanelWithButtons(const sf::Vector2f& pos, Character* owner);
	~PanelWithButtons();

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

private:

	Clickable* m_buttonList[4]; // To hold selection buttons

};

class PanelWithStats : public Panel
{
public:
	PanelWithStats(const sf::Vector2f& pos, Character* owner);
	~PanelWithStats();

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

	void ShowStats(sf::RenderWindow* window);

	void SetOwningCharacter(Character* character);

private:

	Character* m_owner;
	sf::Font m_font;
	sf::Text name;
	sf::Text health;
	sf::Text defense;
	sf::Text strength;
	sf::Text level;
};

