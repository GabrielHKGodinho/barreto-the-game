#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorColisoes.h"
#include "Entidade.h"
#include "Obstaculo.h"

class Mesa : public Obstaculo
{
public:
	Mesa(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Mesa();
};

