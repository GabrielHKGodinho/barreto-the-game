#pragma once
#include "Obstaculo.h"

class Mochila: public Obstaculo
{
public:
	Mochila(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float push=0);
	~Mochila();
};

