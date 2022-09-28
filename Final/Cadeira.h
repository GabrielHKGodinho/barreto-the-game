#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorColisoes.h"
#include "Entidade.h"
#include "Obstaculo.h"

class Cadeira: public Obstaculo
{
public:
	Cadeira(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float push);
	~Cadeira();
};

