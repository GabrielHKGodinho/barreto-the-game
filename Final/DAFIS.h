#pragma once
#include "Fase.h"
#include "E208.h"
#include "Ricky.h"
 

class DAFIS: public Fase
{
public:
	DAFIS(sf::View& view, bool p2);
	DAFIS();
	~DAFIS();

	int randomEnemies();
	void gerarFase(int enemies);

	void atualizar(float deltaTime);
	void ColisaoInimigo();
	void update(float deltaTime, sf::RenderWindow& window, sf::View& view);
};

