#include "Pilha.h"



Pilha::Pilha()
{
	prim = 0;
	fim = 0;
}


Pilha::~Pilha()
{
}

void Pilha::push_back(State * obj)
{
	vetor[fim] = obj;
	fim++;
	obj->setPpilha(this);
}

void Pilha::pop()
{
	delete vetor[fim];
	fim--;
}

void Pilha::pop_duplo()
{
	pop();
	pop();
}

State * Pilha::top()
{
	return vetor[fim-1];
}

void Pilha::substituir(State * obj)
{
	pop();
	push_back(obj);
}
