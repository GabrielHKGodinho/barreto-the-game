#pragma once
#include <SFML/Graphics.hpp>
#include "Barreto.h"
#include <vector>
#include "SaladeAula.h"
#include "Entidade.h"
#include "Jogo.h"
#include "State.h"
#include "MenuIniciar.h"
#include "Pilha.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void executar();
	void ResizeView(const sf::RenderWindow& window, sf::View& view);

private:
	State* currentState;
	Pilha pilha;
};

