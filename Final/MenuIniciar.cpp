#include "MenuIniciar.h"



MenuIniciar::MenuIniciar(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Menu(texture, size, position)
{
	this->position= position;
	iniciar();
}


MenuIniciar::~MenuIniciar()
{
}


void MenuIniciar::iniciar()
{

	escolhaDeFase = false;

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Novo Jogo");
	menu[0].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Carregar Jogo");
	menu[1].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Ranking");
	menu[2].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Sair");
	menu[3].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 4));

	selecionado = 0;
}

void MenuIniciar::enter( sf::RenderWindow& window)
{
	clock.restart();

	switch (selecionado) {

	case(0):
		if (!escolhaDeFase) {
			escolhaDeFase = true;
			menuFases();
		}

		else {
			iniciar();
			Ppilha->getClock().restart();
			Ppilha->push_back(new SaladeAula());
		}
		break;

	case(1):
		if (!escolhaDeFase) {

		}

		else {
			iniciar();
			Ppilha->getClock().restart();
			Ppilha->push_back(new DAFIS());
		}
		break;

	case(2):
		if (!escolhaDeFase) {
			ranking();
		}

		else {
			iniciar();
			Ppilha->getClock().restart();
			Ppilha->push_back(new E208());
		}
		break;

	case(3):
		if (!escolhaDeFase) {
			window.close();
		}

		else {
			iniciar();
		}
		break;
	};

}

void MenuIniciar::menuFases()
{
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Fase 1");
	menu[0].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Fase 2");
	menu[1].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Fase 3");
	menu[2].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Voltar");
	menu[3].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 4));

	selecionado = 0;
}

void MenuIniciar::ranking()
{
	FILE* file = fopen("Ranking.txt", "r");
	int ch = getc(file);
	while (ch != EOF)
	{

		putchar(ch);

		ch = getc(file);
	}
}
