#include "Game.h"
#include "GameObject.h"

Game::Game()
	: m_gameOver(false)
{
	m_mainFont.loadFromFile("Fonts/kenpixel_high_square.ttf");
	m_player = new Player(500.f,Location::Main_Menu);

	c1 = new Character("Sprites/Dude.jpg", sf::Vector2f(300.f, 550.f));
	AddObject(c1);
	c1->m_sprite.setScale(0.8, 0.8);

	c2 = new Character("Sprites/peger.jpg", sf::Vector2f(1000.f, 200.f));
	AddObject(c2);
	c2->m_sprite.setScale(0.8, 0.8);

	button = new Clickable(sf::Vector2f(450.f, 475.f), "Attack");
	AddObject(button);

}
void Game::Draw(sf::RenderWindow * window)
{	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		current->Draw(window);
	}
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
}

void Game::AddObject(GameObject * object)
{
	object->SetOwner(this);
	m_gameObjects.push_back(object);
}

void Game::ShowFonts(sf::RenderWindow* window)
{
	if (m_gameOver)
	{
		sf::Text gameOverText;
		gameOverText.setFont(m_mainFont);
		gameOverText.setString("GAME OVER!");
		gameOverText.setCharacterSize(110);
		gameOverText.setPosition(450, 150);
		window->draw(gameOverText);
	}
}