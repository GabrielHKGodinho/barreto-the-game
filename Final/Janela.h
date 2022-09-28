#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorColisoes.h"
#include "Platform.h"

class Janela: public Platform
{
public:
	Janela(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Janela();

	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape win;
};

