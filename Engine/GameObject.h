#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

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