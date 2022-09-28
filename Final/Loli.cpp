#include "Loli.h"

Loli::Loli()
{
}
	

Loli::Loli(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Projeteis(texture, size, position)
{
}


Loli::~Loli()
{
}

void Loli::atirando(float deltaTime, sf::Vector2f player)
{
	for (Loli* lolis : LoliVect)
	{
			lolis->velocity=player;
		lolis->body.move(lolis->velocity * deltaTime);
	}
}

void Loli::imprimir(sf::RenderWindow& window)
{
	for (Loli* Loli : LoliVect)
		Loli->Draw(window);

}

void Loli::setVelocidade(sf::Vector2f velocity)
{
	for (Loli* lolis : LoliVect) {

		if (velocity.x > 0.0f)
			lolis->velocity = sf::Vector2f(-50.0f,0.0f);

		else if (velocity.x < 0.0f)
			lolis->velocity = sf::Vector2f(50.0f,0.0f);

		if (velocity.y > 0.0f)
			lolis->velocity.y = 50.0f;

		else if (velocity.y < 0.0f)
			lolis->velocity.y = -50.0f;
	}
	

	if (LoliVect.size() > 1)
		LoliVect.resize(1);
}