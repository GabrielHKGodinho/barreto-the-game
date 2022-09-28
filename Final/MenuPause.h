#pragma once
#include "Menu.h"

class MenuPause: public Menu
{
public:
	MenuPause(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::View * view, sf::Vector2f playerPosition);
	~MenuPause();

	void iniciar();

	void enter(sf::RenderWindow& window);

private:
	sf::View* view;
};

