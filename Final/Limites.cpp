#include "Limites.h"



Limites::Limites(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Platform(texture, size, position)
{

}


Limites::~Limites()
{
}

void Limites::Draw(sf::RenderWindow & window)
{
	body.setFillColor(sf::Color(113, 74, 23));
	window.draw(body);
}
