#include "MenuPause.h"



MenuPause::MenuPause(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::View * view, sf::Vector2f playerPosition):
	Menu(texture, size, position)
{
	this->playerPosition = playerPosition;
	this->view = view;
	this->position = position;
	iniciar();
}


MenuPause::~MenuPause()
{
}

void MenuPause::iniciar()
{
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Continuar");
	menu[0].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Salvar e Sair");
	menu[1].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Menu Inicial");
	menu[2].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Sair do Jogo");
	menu[3].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 4));

	selecionado = 0;
}

void MenuPause::enter(sf::RenderWindow & window)
{

	switch (selecionado) {

	case(0):

		Ppilha->pop();
		view->setCenter(playerPosition);
		break;

	case(1):

		break;

	case(2):
		Ppilha->pop_duplo();
		break;

	case(3):
			window.close();

		break;
	};

}
