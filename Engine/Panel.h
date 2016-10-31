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
	//Figure out how to push the buttons to the game object list (game reference?)
public:

	PanelWithButtons(const sf::Vector2f& pos);
	~PanelWithButtons();

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

private:

	Clickable* button;
	Clickable* button1;
	Clickable* button2;
	Clickable* button3;
};

