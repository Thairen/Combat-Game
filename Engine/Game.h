#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "StateMachine.h"

class Player;
class Arena;

class Game
{
public:
	Game();
	void Draw(sf::RenderWindow* window);
	void Update(sf::RenderWindow * window, float dt);
	void GameOver() { m_gameOver = true;  }

	void AddGameStates();

	void UpdateBattle(sf::RenderWindow * window, float dt);
	void DrawBattle(sf::RenderWindow* window);

private:
	StateMachine* m_gameStateMachine;

	bool m_gameOver;
	sf::Font m_mainFont;
	Player* m_player;
	Arena* m_arena;

	sf::Texture tex; //May stay
	sf::Sprite background; // ""
};