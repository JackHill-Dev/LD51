#include "Spell.h"

Spell::Spell(std::string& filePath)
{
	m_Texture = new sf::Texture;
	m_Texture->loadFromFile("Assets/Spell.png");
	m_Sprite.setTexture(*m_Texture);
}

Spell::~Spell()
{
	delete m_Texture;
	m_Texture = nullptr;
}

void Spell::Update(const float& dt)
{
	m_Sprite.move(1 * dt, 0);
}

void Spell::Draw(sf::RenderWindow& window)
{
	if(m_LifeTime > 0)
		window.draw(m_Sprite);
}
