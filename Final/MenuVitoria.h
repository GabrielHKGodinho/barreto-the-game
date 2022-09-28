#pragma once
#include "Menu.h"
#include <string>
#include <iostream>

class MenuVitoria: public Menu
{
public:
	MenuVitoria(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::View * view);
	~MenuVitoria();

	void gravarRanking();
	void enter(sf::RenderWindow& window);
	void iniciar();

	void update(float deltaTime, sf::RenderWindow & window, sf::View & view);

private:
	std::string nomeString;
	sf::String nome;
	sf::View* view;
	sf::Text texto;
};

