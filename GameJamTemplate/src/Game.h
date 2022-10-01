#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include "Button.h"
class Game
{
public:
	Game();
	void Update(float& dt);
	void Draw(sf::RenderWindow& RenderWindow);
private:
	void HandleCollisions();

};
