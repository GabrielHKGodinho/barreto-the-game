#pragma once
#include "Fase.h"
#include "MenuPause.h"
#include "MenuVitoria.h"
#include "Rauli.h"
#include "Ricky.h"

class E208: public Fase
{
public:
	E208();
	E208(sf::View& view,bool p2);
	~E208();

	void gerarFase(int enemies);

	void atualizar(float deltaTime);
	void ColisaoInimigo();
	void update(float deltaTime, sf::RenderWindow& window, sf::View& view);

	void limitePlayer(Player* player);

};

