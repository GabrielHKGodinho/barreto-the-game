#include "ListaTexturas.h"



ListaTexturas::ListaTexturas()
{
	texturas.push_back(new sf::Texture);
	texturas[0]->loadFromFile("images/blackboard.png");

	texturas.push_back(new  sf::Texture);
	texturas[1]->loadFromFile("images/table.png");

	texturas.push_back(new sf::Texture);
	texturas[2]->loadFromFile("images/window.png");

	texturas.push_back(new sf::Texture);
	texturas[3]->loadFromFile("images/chair.png");

	texturas.push_back(new sf::Texture);
	texturas[4]->loadFromFile("images/patinete.png");

	texturas.push_back(new sf::Texture);
	texturas[5]->loadFromFile("images/wall.png");

	texturas.push_back(new sf::Texture);
	texturas[6]->loadFromFile("images/tudo.png");
	texturas[6]->setSmooth(true);

	texturas.push_back(new sf::Texture);
	texturas[7]->loadFromFile("images/terraplanista.png"); 

	texturas.push_back(new sf::Texture);
	texturas[8]->loadFromFile("images/waifu.jpg");

	texturas.push_back(new sf::Texture);
	texturas[9]->loadFromFile("images/livro.png");

	texturas.push_back(new sf::Texture);
	texturas[10]->loadFromFile("images/terrap.png");

	texturas.push_back(new sf::Texture);
	texturas[11]->loadFromFile("images/mochila.png");

	texturas.push_back(new sf::Texture);
	texturas[12]->loadFromFile("images/rauli.png");

	texturas.push_back(new sf::Texture);
	texturas[13]->loadFromFile("images/ricky.png");

	texturas.push_back(new sf::Texture);
	texturas[14]->loadFromFile("images/dafis.png");
}


ListaTexturas::~ListaTexturas()
{
}
