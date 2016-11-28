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

	m_arena = new Arena(sf::Vector2f(0.f, 0.f), m_player->m_selectedCharacter[0]);

	m_gameStateMachine = new StateMachine();
	AddGameStates();
}
void Game::Draw(sf::RenderWindow * window)
{	
	window->draw(background);
	m_player->Draw(window);
	m_gameStateMachine->Draw(window);
}

void Game::Update(sf::RenderWindow * window, float dt)
{
	m_player->Update(window, dt);
	m_gameStateMachine->Update(window, dt);
}

void Game::AddGameStates()
{
	m_gameStateMachine->AddState("mainmenu", new MainMenuState(m_gameStateMachine));
	m_gameStateMachine->AddState("battle", new BattleState(m_gameStateMachine, this));
	m_gameStateMachine->AddState("ingameMenu", new InGameMenuState(m_gameStateMachine));

	m_gameStateMachine->ChangeState("battle");
}

void Game::UpdateBattle(sf::RenderWindow * window, float dt)
{
	m_arena->Update(window, dt);
}

void Game::DrawBattle(sf::RenderWindow * window)
{
	m_arena->Draw(window);
}
