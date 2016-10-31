#include "Game.h"
#include "GameObject.h"

Game::Game()
	: m_gameOver(false)
{
	tex.loadFromFile("Sprites/forest.jpg");
	background.setTexture(tex);
	background.setScale(2.0f, 2.0f);
	background.setPosition(sf::Vector2f(50, 0));

	m_mainFont.loadFromFile("Fonts/kenpixel_high_square.ttf");
	m_player = new Player(500.f,Location::Main_Menu);

	c1 = new Character(CharacterType::Yuffie, sf::Vector2f(250.f, 350.f));
	AddObject(c1);
	c1->m_sprite.setScale(-0.8f, 0.8f);

	c2 = new Character(CharacterType::Tifa, sf::Vector2f(1000.f, 350.f));
	AddObject(c2);
	c2->m_sprite.setScale(0.8f, 0.8f);

	enemyPanel = new Panel(sf::Vector2f(950, 510));
	enemyPanel->m_sprite.setScale(2.0f, 2.0f);
	AddObject(enemyPanel);
}
void Game::Draw(sf::RenderWindow * window)
{	
	window->draw(background);
	m_player->Draw(window);

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		current->Draw(window);
	}

	
}

void Game::Update(sf::RenderWindow * window, float dt)
{
	m_player->Update(window, dt);
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
	
	
}

void Game::AddObject(GameObject * object)
{
	object->SetOwner(this);
	m_gameObjects.push_back(object);
}
