#pragma once
#include <vector>
#include "Inimigo.h"

class ListaInimigos
{
public:
	ListaInimigos();
	~ListaInimigos();

	std::vector<Inimigo*> getLista() const { return lista; }
	void imprimir(sf::RenderWindow& window);
	void inserir(Inimigo* objeto) { lista.push_back(objeto); }
	Inimigo* getInimigo(int pos) { return lista[pos]; }
	void deletar(int i) { lista.erase(lista.begin()+i); }

private:
	std::vector<Inimigo*> lista;
};


