#include "Projeteis.h"
#include <iostream>



Projeteis::Projeteis()
{
}

Projeteis::Projeteis(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Entidade(texture,size,position)
{
}


Projeteis::~Projeteis()
{
}

void Projeteis::atirando(float deltaTime)
{
	for (int i = 0; i < projet.size(); i++)
	{
		projet[i]->body.move(projet[i]->velocity * deltaTime);
		projet[i]->velocity.y += 1800.0f * deltaTime;
	}
}

void Projeteis::imprimir(sf::RenderWindow& window)
{
	for (Projeteis* projeteis : projet)
		projeteis->Draw(window);

}

void Projeteis::setVelocidade(sf::Vector2f velocity)
{
		projet[0]->velocity = velocity;
		if (projet.size() > 6)
			projet.resize(5);
}
