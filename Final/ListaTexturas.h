#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class ListaTexturas
{
public:
	ListaTexturas();
	~ListaTexturas();

	const std::vector<sf::Texture*> getTexturas() { return texturas; }
	sf::Texture* getTextura(int pos) { return texturas[pos]; }

private:
	std::vector<sf::Texture*> texturas;
};

