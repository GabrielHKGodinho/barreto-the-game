#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h"

class Limites : public Platform
{
public:
	Limites(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Limites();

	void Draw(sf::RenderWindow& window);
private:

};

