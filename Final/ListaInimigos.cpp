#include "ListaInimigos.h"



ListaInimigos::ListaInimigos()
{
}


ListaInimigos::~ListaInimigos()
{
}

void ListaInimigos::imprimir(sf::RenderWindow & window)
{
	for (Inimigo* inimigos : lista)
		inimigos->Draw(window);
}
