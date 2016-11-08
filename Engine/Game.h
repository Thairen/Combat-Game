#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Character.h"
#include "Clickable.h"
#include "Panel.h"
#include "Enemy.h"

class Game
{
public:
	Game();
	void Draw(sf::RenderWindow* window);
	void Update(sf::RenderWindow * window, float dt);
	void AddObject(GameObject* object);
	void GameOver() { m_gameOver = true;  }

private:
	std::vector<GameObject*> m_gameObjects;

	bool m_gameOver;
	sf::Font m_mainFont;
	Player* m_player;
	Enemy* m_ai;

	sf::Texture tex; //May stay
	sf::Sprite background; // ""
};