#include "Game.h"
#include <functional>
#include <string>
Game::Game()
{

}

void Game::Update(sf::RenderWindow& window, float& dt)
{
	sf::Vector2f pos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	m_Player.Update(dt);
	cursor.SetPos(pos);
	HandleCollisions();
}

void Game::Draw(sf::RenderWindow& RenderWindow)
{
	RenderWindow.draw(cursor.GetSprite());
	RenderWindow.draw(m_Player.GetSprite());
}

void Game::HandleCollisions()
{
}


