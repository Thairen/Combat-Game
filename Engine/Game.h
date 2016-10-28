#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Game
{
public:
	Game();
	void Draw(sf::RenderWindow* window);
	void Update(sf::RenderWindow * window, float dt);
	void AddObject(GameObject* object);
	void GameOver() { m_gameOver = true;  }
	void ShowFonts(sf::RenderWindow* window);

private:
	std::vector<GameObject*> m_gameObjects;
	bool m_gameOver;
	sf::Font m_mainFont;
};