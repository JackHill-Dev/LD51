#include "Spell.h"

Spell::Spell(const char* filePath)
{
	m_Texture = std::make_shared<sf::Texture>();
	m_Texture->loadFromFile(filePath);
	m_Sprite.setTexture(*m_Texture);
	m_Sprite.setScale(0.3f, 0.3f);
	m_Sprite.setPosition(64, 320);
}

Spell::~Spell()
{

}

void Spell::Update(const float& dt)
{

	m_Sprite.move(100 * dt , 0);
}

void Spell::Draw(sf::RenderWindow& window)
{
	if(m_LifeTime > 0)
		window.draw(m_Sprite);
}
