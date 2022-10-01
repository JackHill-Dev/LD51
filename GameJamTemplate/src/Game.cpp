#include "Game.h"
#include <functional>
#include <string>
Game::Game()
{

}

void Game::Update(sf::RenderWindow& window, float& dt)
{
	sf::Vector2f pos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

	cursor.SetPos(pos);
	HandleCollisions();
}

void Game::Draw(sf::RenderWindow& RenderWindow)
{
	
	RenderWindow.draw(cursor.GetSprite());
}

void Game::HandleCollisions()
{
}


