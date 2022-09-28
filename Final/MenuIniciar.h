#pragma once
#include "SaladeAula.h"
#include "DAFIS.h"
#include "E208.h"
#include "Menu.h"

class MenuIniciar:public Menu
{
public:
	MenuIniciar(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~MenuIniciar();

	void iniciar();

	void enter( sf::RenderWindow& window);

	void menuFases();

	void ranking();

private:
	bool escolhaDeFase;
};

