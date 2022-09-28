#pragma once
#include "Projeteis.h"

class Giz : public Projeteis
{
public:
	Giz();
	Giz(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Giz();

	void atirando(float deltaTime);
	void inserir(Giz* giz) { gizVect.insert(gizVect.begin(), giz); }
	void imprimir(sf::RenderWindow& window);
	void setVelocidade(sf::Vector2f velocity);
	std::vector < Giz* > getProjeteisGiz() { return gizVect; }
	void OnCollison() { gizVect.resize(0); }

private:
	std::vector < Giz* > gizVect;

};

