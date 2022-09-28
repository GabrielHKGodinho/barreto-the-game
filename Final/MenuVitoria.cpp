#include "MenuVitoria.h"



MenuVitoria::MenuVitoria(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::View * view):
	Menu(texture, size, position)
{
	this->view = view;
	this->position = position;
	iniciar();
}


MenuVitoria::~MenuVitoria()
{
}

void MenuVitoria::gravarRanking()
{
	FILE* Gravador = fopen("./Ranking.txt", "a+");

	fseek(Gravador, 0, SEEK_END);

	fprintf(Gravador, "\n%s %d", nomeString.c_str(), 10000/Ppilha->getScore());
}

void MenuVitoria::enter(sf::RenderWindow & window)
{
	gravarRanking();
	Ppilha->pop();
}

void MenuVitoria::iniciar()
{
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Continuar");
	menu[0].setPosition(sf::Vector2f(position.x / 2, position.y / (ITEMS + 1) * 1));

	selecionado = 0;
}

void MenuVitoria::update(float deltaTime, sf::RenderWindow& window, sf::View& view)
{
	view.setCenter(sf::Vector2f(544.0f, 596.0f));

	std::getline(std::cin, nomeString);
	enter(window);
		
}