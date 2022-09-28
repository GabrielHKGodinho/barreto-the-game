#pragma once
#include "Projeteis.h"

class TerraPlana : public Projeteis
{
public:
	TerraPlana();
	TerraPlana(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~TerraPlana();

	void atirando(float deltaTime);
	void inserir(TerraPlana* terraP) { TerraPlanaVect.insert(TerraPlanaVect.begin(), terraP); }
	void imprimir(sf::RenderWindow& window);
	void setVelocidade(sf::Vector2f velocity);
	std::vector < TerraPlana* > getProjeteisTerra() { return TerraPlanaVect; }
	void OnCollison() { TerraPlanaVect.resize(0); }

private:
	std::vector < TerraPlana* > TerraPlanaVect;
};

