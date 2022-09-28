#include "TerraPlana.h"


TerraPlana::TerraPlana()
{
}

TerraPlana::TerraPlana(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Projeteis(texture, size, position)
{
}


TerraPlana::~TerraPlana()
{
}

void TerraPlana::atirando(float deltaTime)
{
	for (int i = 0; i < TerraPlanaVect.size(); i++)
		TerraPlanaVect[i]->body.move(TerraPlanaVect[i]->velocity * deltaTime);
}

void TerraPlana::imprimir(sf::RenderWindow& window)
{
	for (TerraPlana* terraP : TerraPlanaVect)
		terraP->Draw(window);
}

void TerraPlana::setVelocidade(sf::Vector2f velocity)
{
	TerraPlanaVect[0]->velocity = velocity;
	if (TerraPlanaVect.size() > 1)
		TerraPlanaVect.resize(1);
}
