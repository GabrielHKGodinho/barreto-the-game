#include "ListaPlayer.h"




ListaPlayer::ListaPlayer(bool TwoPlayers)
{

	if (TwoPlayers) {

	}
}


ListaPlayer::~ListaPlayer()
{
}

void ListaPlayer::imprimir(sf::RenderWindow & window)
{
	for (Player* pls : players)
		pls->Draw(window);
}
