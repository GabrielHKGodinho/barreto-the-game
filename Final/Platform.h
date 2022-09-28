#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorColisoes.h"
#include "Entidade.h"

class Platform : public Entidade
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position );
	virtual ~Platform();

	virtual void Draw(sf::RenderWindow& window);

protected:
};

