#pragma once
#include <string>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "Animation.h"
class Spell
{
public:
	Spell() = default;
	Spell(const char* filePath);
	~Spell();

	void Update(const float& dt);
	void Draw(sf::RenderWindow& window);
private:
	std::shared_ptr<sf::Texture> m_Texture = nullptr;
	sf::Vector2f m_Velocity;
	sf::Sprite m_Sprite;
	Animation m_Animation;
	int m_LifeTime = 3;
};