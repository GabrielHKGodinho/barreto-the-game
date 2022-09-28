#pragma once
#include "State.h"
#include "Entidade.h"

#define ITEMS 4

class Menu: public State, public Entidade
{
public:
	Menu(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Menu();

	void imprimir(sf::RenderWindow &window);
	virtual void MoveUp();
	virtual void MoveDown();
	virtual void update(float deltaTime, sf::RenderWindow& window, sf::View& view);
	const int GetPressedItem() const { return selecionado; }
	virtual void enter(sf::RenderWindow& window) = 0;

protected:
	sf::Clock clock;
	int selecionado;
	sf::Font font;
	sf::Text menu[ITEMS];
	sf::Vector2f position;
	sf::Vector2f playerPosition;

};

