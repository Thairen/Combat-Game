#pragma once
#include "GameObject.h"
#include "Clickable.h"

class Panel : public GameObject
{
public:
	Panel(const sf::Vector2f& pos);
	
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);
};



class PanelWithButtons : public Panel
{
	//Modify buttons to set the position relative to the panel
public:

	PanelWithButtons(const sf::Vector2f& pos);
	~PanelWithButtons();

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

private:

	Clickable* m_buttonList[4]; // To hold selection buttons

};

