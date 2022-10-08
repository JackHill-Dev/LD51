#pragma once
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "Animation.h"
class Spell
{
public:
	Spell() = default;
	Spell(std::string& filePath);
	~Spell();

	void Update(const float& dt);
	void Draw(sf::RenderWindow& window);
private:
	sf::Texture* m_Texture;
	sf::Sprite m_Sprite;
	Animation m_Animation;
	int m_LifeTime = 1;
};