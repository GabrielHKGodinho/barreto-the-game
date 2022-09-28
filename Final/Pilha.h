#pragma once
#include "State.h"

class Pilha
{
public:
	Pilha();
	~Pilha();
	void push_back(class State* obj);
	void pop(); 
	void pop_duplo(); 
	class State* top();
	void substituir(class State* obj);
	int getScore() { return (int)score.getElapsedTime().asSeconds(); }
	sf::Clock getClock() { return score; }

private:
	class State* vetor[4];
	int prim;
	int fim;
	sf::Clock score;
};

