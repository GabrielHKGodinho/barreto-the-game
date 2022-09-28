#include "Giz.h"



Giz::Giz()
{
}

Giz::Giz(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Projeteis(texture, size, position)
{
}


Giz::~Giz()
{
}

void Giz::atirando(float deltaTime)
{
	for (int i = 0; i < gizVect.size(); i++)
	{
		gizVect[i]->body.move(gizVect[i]->velocity * deltaTime);
		gizVect[i]->velocity.y += 1800.0f * deltaTime;
	}
}

void Giz::imprimir(sf::RenderWindow& window)
{
	for (Giz* giz : gizVect)
		giz->Draw(window);

}

void Giz::setVelocidade(sf::Vector2f velocity)
{
	gizVect[0]->velocity = velocity;
	if (gizVect.size() > 6)
		gizVect.resize(5);
}

