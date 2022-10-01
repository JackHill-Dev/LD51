#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Button.h"

struct Cursor
{
	Cursor()
	{
		m_Texture = new sf::Texture;
		m_Texture->loadFromFile("Assets/Cursor.png");
		m_Sprite.setTexture(*m_Texture);
		m_Sprite.setScale({ 0.5f, 0.5f });
		m_Sprite.setOrigin(m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2);
	}

	~Cursor()
	{
		m_Texture = nullptr;
		delete m_Texture;
	}
	void SetPos(sf::Vector2f& pos) { m_Sprite.setPosition(pos); }
	sf::Sprite& GetSprite() { return m_Sprite; }
private:
	sf::Texture* m_Texture;
	sf::Sprite m_Sprite;
};

class Game
{
public:
	Game();
	void Update(sf::RenderWindow& window, float& dt);
	void Draw(sf::RenderWindow& RenderWindow);
private:
	void HandleCollisions();
private:
	Cursor cursor;

};
