#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Animation.h"
class Player
{
public:
	Player();
	~Player();
	sf::Sprite& GetSprite() { return m_Sprite; }
	const sf::FloatRect& GetGlobalBounds() const { return m_Sprite.getGlobalBounds(); }
	void Update(float& dt);
	void UpdateMovement(float& dt);

	enum AnimState
	{
		WalkRight,
		WalkLeft,
		WalkUp,
		WalkDown,
		Count
	};
private:
	float speed = 1.f;
	sf::Vector2f m_Velocity;
	sf::Texture* m_Texture;
	sf::Sprite m_Sprite;
	Animation m_WalkingAnim;
	AnimState m_CurrentAnimState = AnimState::WalkRight;
	std::vector<Animation> m_Anims;

};

