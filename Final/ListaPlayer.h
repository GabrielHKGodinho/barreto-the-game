#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"

class ListaPlayer
{
public:
	ListaPlayer(bool TwoPlayers = 0);
	~ListaPlayer();

	std::vector<Player*> getPlayers() const { return players; }
	void imprimir(sf::RenderWindow& window);
	void inserir(Player* objeto) { players.push_back(objeto); }
	Player* getPlayer(int pos) { return players[pos]; }
private:
	std::vector<Player*> players;
};

