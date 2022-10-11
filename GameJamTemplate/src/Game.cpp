#include "Game.h"
#include <functional>
#include <string>
Game::Game()
{
	Spell temp = Spell("Assets/Spell.png");
	spell = temp;
}

void Game::Update(sf::RenderWindow& window, float& dt)
{
	sf::Vector2f pos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	m_Player.Update(dt);
	spell.Update(dt);
	cursor.SetPos(pos);
	HandleCollisions();
}

void Game::Draw(sf::RenderWindow& RenderWindow)
{
	RenderWindow.draw(cursor.GetSprite());
	m_Player.Draw(RenderWindow);
	spell.Draw(RenderWindow);
}

void Game::HandleCollisions()
{
}


