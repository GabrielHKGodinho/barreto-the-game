#pragma once
#include "Elemento.h"
#include <iostream>
using namespace std;

template<class TIPO>
class Lista
{
private:
	Elemento<TIPO>* pPrimeiro;
	Elemento<TIPO>* pAtual;
	int tamanho;
public:
	Lista();
	~Lista();
	void inicializa();
	bool incluaElemento(Elemento<TIPO>* pElemento);
	TIPO* getElemento(int pos);
	Elemento<TIPO>* getPrimeiro() { return pPrimeiro; }
	bool incluaInfo(TIPO* pInfo);
	int getTamanho() { return tamanho; }

};
template<class TIPO>Lista<TIPO>::Lista()
{
	inicializa();
}

template<class TIPO>Lista<TIPO>::~Lista()
{
	// Fazer código de desalocação...
}

template<class TIPO>void Lista<TIPO>::inicializa()
{
	pPrimeiro = NULL;
	pAtual = NULL;
	tamanho = 0;
}

template<class TIPO>bool Lista<TIPO>::incluaElemento(Elemento	<TIPO	>* pElemento)
{
	tamanho++;

	if (NULL != pElemento)
	{
		if (NULL == pPrimeiro)
		{
			pPrimeiro
				= pElemento;
			pAtual
				= pPrimeiro;
		}
		else
		{
			pElemento->setAnterior(pAtual);
			pElemento->setProximo(NULL);
			pAtual->setProximo(pElemento);
			pAtual
				= pAtual->getProximo();
		}
		return true;
	}
	else
	{
		cout << " Erro, elemento nulo na lista. " << endl;
		return false;
	}
}

template<class TIPO> TIPO* Lista<TIPO>::getElemento(int pos) {
	Elemento<TIPO>* aux;
	aux = getPrimeiro();

	for (int i = 0; i < pos; i++) {
		aux = aux->getProximo();
	}

	return aux->getInfo();
}
template<class TIPO>bool Lista<TIPO>::incluaInfo(TIPO * pInfo)
{
	if (NULL != pInfo)
	{
		Elemento<TIPO>* pElemento;
		pElemento = new Elemento<TIPO>();
		pElemento->setInfo(pInfo);
		incluaElemento(pElemento);
		return true;
	}
	else
	{
		printf("Erro, elemento (informação) nulo(a) na lista. \n");
		return false;
	}
}
