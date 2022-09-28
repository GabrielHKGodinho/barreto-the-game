#pragma once
#include "Projeteis.h"

class Loli :
	public Projeteis
{
public:
	Loli(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	Loli();
	~Loli();

	void atirando(float deltaTime, sf::Vector2f player);
	void inserir(Loli* Loli) { LoliVect.insert(LoliVect.begin(), Loli); }
	void imprimir(sf::RenderWindow& window);
	void setVelocidade(sf::Vector2f velocity);
	std::vector < Loli* > getProjeteisLoli() { return LoliVect; }
	void OnCollison() { LoliVect.resize(0); }

private:
	std::vector < Loli* > LoliVect;
};

