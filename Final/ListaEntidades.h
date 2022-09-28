#pragma once
#include <vector>
#include "Entidade.h"
#include "Blackboard.h"
#include "Limites.h"
#include "Lista.h"


class ListaEntidades
{
public:
	ListaEntidades();
	~ListaEntidades();

	Lista<Entidade> getLista() const { return lista; }
	void imprimir(sf::RenderWindow& window);
	void inserir(Entidade* objeto) { lista.incluaInfo(objeto); }
	Entidade* getEntidade(int pos) { return lista.getElemento(pos); }

private:
	Lista<Entidade> lista;
};

