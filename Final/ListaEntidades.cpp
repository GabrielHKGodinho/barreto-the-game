#include "ListaEntidades.h"
#include "Entidade.h"


ListaEntidades::ListaEntidades()
{
}


ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::imprimir(sf::RenderWindow& window)
{
	for (int i=0; i<lista.getTamanho(); i++)
		lista.getElemento(i)->Draw(window);
}
