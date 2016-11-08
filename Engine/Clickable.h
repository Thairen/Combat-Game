#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "Character.h"

enum class ButtonType
{
	Attack,
	Skill,
	Item,
	Escape
};

class Clickable : public GameObject
{
public:
	Clickable(const sf::Vector2f& pos, ButtonType buttonType, Character* owner); //Button was taken o.O so clickable..

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);
	ButtonType GetType() { return m_type; }
	void SetType(ButtonType type);

	void Hovering(sf::RenderWindow* window);
	void Clicked();

	void Action(ButtonType buttonType);
	
private:

	ButtonType m_type;

	std::string buttonText; // Find a cleaner way to do this?

	bool m_isHovering;
	sf::Text m_text;
	sf::Font m_font;

	Character* m_owner;
};

