#pragma once
#include "State.h"
#include "stdlib.h"
#include "ListaEntidades.h"
//#include "Barreto.h"
#include <SFML/Graphics.hpp>
#include "Mesa.h"
#include "Janela.h"
#include "Cadeira.h"
#include "PatineteEletrico.h"
#include "ListaInimigos.h"
#include "Terraplanista.h"
#include "ListaTexturas.h"
#include "ListaPlayer.h"
#include "Player.h"
#include "Fase.h"
#include "Mochila.h"

class Fase: public State
{
public:
	Fase();
	virtual ~Fase();

	virtual void gerarFase(int enemies)=0;
	virtual void imprimir(sf::RenderWindow& window);
	virtual Lista<Entidade> getLista() const { return fase1.getLista(); }
	virtual std::vector<Inimigo*> getInimigos() const { return inimigos.getLista(); }
	virtual std::vector<Player*> getPlayers() const { return players.getPlayers(); }
	virtual Entidade* getElemento(int pos) { return fase1.getEntidade(pos); }
	virtual Inimigo* getInimigo(int pos) { return inimigos.getInimigo(pos); }
	virtual Player* getPlayer(int pos) { return players.getPlayer(pos); }

	virtual void atualizar(float deltaTime)=0;
	virtual void ColisaoInimigo()=0;
	virtual void update(float deltaTime, sf::RenderWindow& window, sf::View& view)=0;

protected:
	ListaEntidades fase1;
	ListaInimigos inimigos;
	sf::Vector2f direction;
	ListaTexturas texturas;
	Entidade* bg;
	Entidade* bg2;
	ListaPlayer players;
	bool player2;
};

