#pragma once
#include "stdlib.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>
#include "PatineteEletrico.h"
#include "ListaInimigos.h"
#include "Terraplanista.h"
#include "ListaTexturas.h"
#include "ListaPlayer.h"
#include "Fase.h"
#include "Ricky.h"
#include "MenuIniciar.h"
#include "MenuPause.h"


class SaladeAula: public Fase
{
public:
	SaladeAula();
	~SaladeAula();

	int randomEnemies();
	void gerarFase(int enemies);

	void atualizar( float deltaTime);
	void ColisaoInimigo();
	void update( float deltaTime, sf::RenderWindow& window, sf::View& view);

};

