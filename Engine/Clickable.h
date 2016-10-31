#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"

class Clickable : public GameObject
{
public:
	Clickable(const sf::Vector2f& pos, std::string buttonText); //Button was taken o.O so clickable..

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);

	void Hovering(sf::RenderWindow* window);
	
private:
	
	//m_sprite.setTextureRect(sf::IntRect(0, 98, 190, 45));  //Move this to when button pressed

	bool m_isHovering;
	sf::Text m_text;
	sf::Font m_font;
};

