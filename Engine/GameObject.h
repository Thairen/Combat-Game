#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

//SUPER TEMP======================
//std::string prefix[16] = { "Ste", "Mah", "Joa", "Mar", "Tin", "Gra", "Flo", "Sto", "Cor", "Dor", "Gan", "Ch", "Bra", "Da", "Fra", "Sta" };
//std::string mid[16] = { "ven", "tun", "tre", "sun", "ohn", "ger", "der", "fla", "net", "meh", "harl", "guh", "and", "ave", "gin", "sin" };
//std::string suffix[16] = { "son", "yen", "ith", "tran", "gov", "man", "jer", "ser", "don", "ez", "en", "an", "ve", "net", "fo", "ohm" };
//================================

class Game;

class GameObject
{
public:
	GameObject(std::string texturePath, const sf::Vector2f& pos);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow * window, float dt);
	
	void SetPos(const sf::Vector2f& pos);
	sf::Vector2f GetPosition() { return m_pos; }
	void SetOwner(Game* owner);
	sf::Sprite getowner() { return m_sprite; }
	virtual void Destroy();
	bool IsDestroyed();

	sf::Sprite m_sprite;

protected:
	sf::Vector2f m_pos;

	sf::Texture m_texture;

	Game* m_owner;
	bool m_destroyed;
};