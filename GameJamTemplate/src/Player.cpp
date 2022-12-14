#include "Player.h"

Player::Player()
{
	sf::IntRect rect({ 0, 128 }, { 64,64 });
	m_Texture = new sf::Texture;
	m_Texture->loadFromFile("Assets/Player.png");
	m_Sprite.setTexture(*m_Texture);
	m_Sprite.setTextureRect(rect);
	m_Sprite.setOrigin(m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2);
	m_Sprite.setPosition(640, 320);

	m_Anims.reserve(AnimState::Count);
	// Aniamtion(starting frame x, y, size, no. frames, frame time)
	// Idle
	m_Anims.push_back(Animation(0, 640, 64, 64, 1, 0.1f));
	// Walk Right
	m_Anims.push_back( Animation(0, 704, 64, 64, 9, 0.1f));
	// Walk Left
	m_Anims.push_back( Animation(0, 576, 64, 64, 9, 0.1f));
	// Walk Up
	m_Anims.push_back( Animation(0, 512, 64, 64, 9, 0.1f));
	// Walk Down
	m_Anims.push_back( Animation(0, 640, 64, 64, 9, 0.1f));
	// Shoot Right
	m_Anims.push_back( Animation(0, 19 * 64 , 64, 64, 13, 0.2f));
}

Player::~Player()
{
	m_Texture = nullptr;
	delete m_Texture;
}

void Player::Update(float& dt)
{


	UpdateMovement(dt);
	UpdateAnimations(dt);
	

	Decelerate(dt);
	m_Sprite.move(m_Velocity * dt);
}

void Player::UpdateMovement(float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Velocity.x -= speed;
		m_CurrentAnimState = AnimState::WalkLeft;
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Velocity.x += speed;
		m_CurrentAnimState = AnimState::WalkRight;
	}

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Velocity.y -= speed;
		m_CurrentAnimState = AnimState::WalkUp;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Velocity.y += speed;
		m_CurrentAnimState = AnimState::WalkDown;
	}


}

void Player::UpdateAnimations(float& dt)
{
	m_Anims[m_CurrentAnimState].Update(dt);
	m_Sprite.setTextureRect(m_Anims[m_CurrentAnimState].uv_Rect);

	if (m_Velocity.x <= 0 || m_Velocity.y <= 0)
		m_CurrentAnimState = Idle;
}

void Player::Decelerate(float& dt)
{
	if (m_Velocity.x > 0.0f)
	{

		if (m_Velocity.x > m_MaxVelocity)
			m_Velocity.x = m_MaxVelocity;

		m_Velocity.x -= deceleration * dt;
		if (m_Velocity.x < 0.0f)
			m_Velocity.x = 0;
	}
	else if (m_Velocity.x < 0.0f)
	{

		if (m_Velocity.x < -m_MaxVelocity)
			m_Velocity.x = -m_MaxVelocity;

		m_Velocity.x += deceleration * dt;
		if (m_Velocity.x > 0.0f)
			m_Velocity.x = 0;
	}

	if (m_Velocity.y > 0.0f)
	{

		if (m_Velocity.y > m_MaxVelocity)
			m_Velocity.y = m_MaxVelocity;

		m_Velocity.y -= deceleration * dt;
		if (m_Velocity.y < 0.0f)
			m_Velocity.y = 0;
	}
	else if (m_Velocity.y < 0.0f)
	{

		if (m_Velocity.y < -m_MaxVelocity)
			m_Velocity.y = -m_MaxVelocity;

		m_Velocity.y += deceleration * dt;
		if (m_Velocity.y > 0.0f)
			m_Velocity.y = 0;
	}
}
