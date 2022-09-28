#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorColisoes.h"
#include "Entidade.h"

class Obstaculo : public Entidade
{
public:
	Obstaculo(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float push = 1.0f);
	~Obstaculo();
};

