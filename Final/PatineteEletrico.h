#pragma once
#include "Inimigo.h"
#include "GerenciadorGrafico.h"
#include <SFML/Graphics.hpp>

class PatineteEletrico: public Inimigo
{
public:
	PatineteEletrico(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~PatineteEletrico();

	void Update(Player* player, float deltaTime);
private:
	GerenciadorGrafico GerenciadorGrafico;
};

