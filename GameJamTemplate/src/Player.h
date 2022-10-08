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
	void InitAnims();
	sf::Sprite& GetSprite() { return m_Sprite; }
	const sf::FloatRect& GetGlobalBounds() const { return m_Sprite.getGlobalBounds(); }
	void Update(float& dt);
	void UpdateMovement(float& dt);
	void Shoot();
	void UpdateAnimations(float& dt);
	void Decelerate(float& dt);
	enum AnimState
	{
		Idle,
		WalkRight,
		WalkLeft,
		WalkUp,
		WalkDown,
		SpellCastRight,
		SpellCastLeft,
		SpellCastUp,
		SpellCastDown,
		Count
	};
private:
	float speed = 1400;
	float deceleration = 1000;
	float m_MaxVelocity = 140;
	sf::Vector2f m_Velocity;
	sf::Texture* m_Texture;
	sf::Sprite m_Sprite;
	Animation m_WalkingAnim;
	AnimState m_CurrentAnimState = AnimState::WalkRight;
	std::vector<Animation> m_Anims;

};

