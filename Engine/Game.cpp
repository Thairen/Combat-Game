#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Arena.h"

Game::Game()
	: m_gameOver(false)
{
	tex.loadFromFile("Sprites/forest.jpg");
	background.setTexture(tex);
	background.setScale(2.0f, 2.0f);
	background.setPosition(sf::Vector2f(50, 0));

	m_mainFont.loadFromFile("Fonts/kenpixel_high_square.ttf");
	m_player = new Player(sf::Vector2f(0.f, 0.f), 500.f, Location::Main_Menu);
	AddObject(m_player);

	m_arena = new Arena(sf::Vector2f(0.f, 0.f), m_player->m_selectedCharacter[0]);
	AddObject(m_arena);

	m_gameStateMachine = new StateMachine();
	AddGameStates();
}
void Game::Draw(sf::RenderWindow * window)
{	
	window->draw(background);

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		current->Draw(window);
	}

	m_gameStateMachine->Draw(window);
}

void Game::Update(sf::RenderWindow * window, float dt)
{

	//Check and delete destroyed objects
	for (int i = m_gameObjects.size() - 1; i >= 0; i--)
	{
		GameObject* current = m_gameObjects[i];
		if (current->IsDestroyed())
		{
			delete current;
			m_gameObjects.erase(m_gameObjects.begin() + i);
		}
	}

	//Update GameObjects
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		current->Update(window, dt);
	}

	m_gameStateMachine->Update(dt);
	
}

void Game::AddObject(GameObject * object)
{
	object->SetOwner(this);
	m_gameObjects.push_back(object);
}

void Game::AddGameStates()
{
	m_gameStateMachine->AddState("mainmenu", new MainMenuState());
	m_gameStateMachine->AddState("battle", new BattleState());
	m_gameStateMachine->AddState("ingameMenu", new InGameMenuState());

	m_gameStateMachine->ChangeState("mainmenu");
}
