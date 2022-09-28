#include "Personagem.h"



Personagem::Personagem(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float push):
	Entidade(texture, size, position, push)
{
	clock.restart().asSeconds();
}


Personagem::~Personagem()
{
}

