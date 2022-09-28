#pragma once
#include <SFML/Graphics.hpp>
#include "Entidade.h"
#include <vector>
#include "GerenciadorGrafico.h"



class Projeteis: public Entidade
{
public:
	Projeteis();
	Projeteis(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Projeteis();

	virtual void atirando(float deltaTime);
	virtual void inserir(Projeteis* prjt) { projet.insert(projet.begin(), prjt); }
	virtual void imprimir(sf::RenderWindow& window);
	virtual void setVelocidade(sf::Vector2f velocity);
	std::vector < Projeteis*> getProjeteis() { return projet; }
	
protected:
	std::vector <Projeteis*> projet;

	
};

