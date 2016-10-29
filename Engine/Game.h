#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Character.h"
#include "Clickable.h"

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

	//Temporary variables for testing purposes....

	Character* c1;
	Character* c2;

	Clickable* button;
	Clickable* button1;
	Clickable* button2;
	Clickable* button3;

};