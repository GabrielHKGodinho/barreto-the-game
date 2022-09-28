#pragma once
#include <SFML/Graphics.hpp>
#include "Pilha.h"

class State
{
public:
	State();
	~State();

	virtual void update(float deltaTime, sf::RenderWindow& window, sf::View& view)=0;
	virtual void imprimir(sf::RenderWindow& window)=0;

	void setPpilha(class Pilha* pp) { Ppilha = pp; }

protected:
	class Pilha* Ppilha;
};

