#include "Menu.h"


Menu::Menu(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	clock.restart();
	font.loadFromFile("arial.ttf");
}


Menu::~Menu()
{
}

void Menu::imprimir(sf::RenderWindow &window)
{
	for (int i = 0; i < ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selecionado - 1 >= 0)
	{
		menu[selecionado].setFillColor(sf::Color::White);
		selecionado--;
		menu[selecionado].setFillColor(sf::Color::Red);
		clock.restart();
	}
}

void Menu::MoveDown()
{
	if (selecionado + 1 < ITEMS)
	{
		menu[selecionado].setFillColor(sf::Color::White);
		selecionado++;
		menu[selecionado].setFillColor(sf::Color::Red);
		clock.restart();
	}
}

void Menu::update(float deltaTime, sf::RenderWindow& window, sf::View& view)
{
	view.setCenter(sf::Vector2f(544.0f, 596.0f));

	if (clock.getElapsedTime().asSeconds() >= 0.2) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			MoveUp();

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			MoveDown();

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			enter( window);
	}
}
