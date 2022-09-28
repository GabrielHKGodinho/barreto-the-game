#include "Fase.h"



Fase::Fase():
	State()
{
}


Fase::~Fase()
{
}

void Fase::imprimir(sf::RenderWindow & window)
{
	bg->Draw(window);
	fase1.imprimir(window);
	inimigos.imprimir(window);
	players.imprimir(window);
}
