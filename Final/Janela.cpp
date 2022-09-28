#include "Janela.h"



Janela::Janela(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Platform(nullptr, size, position)
{
	sf::Vector2f entidadesize(size.x, size.y * 45.0f);
	win.setSize(entidadesize);
	win.setOrigin(entidadesize / 2.0f);
	win.setPosition(sf::Vector2f(position.x, position.y - (entidadesize.y) / 2.0f + size.y));
	win.setTexture(texture);
}


Janela::~Janela()
{
}

void Janela::Draw(sf::RenderWindow & window)
{
	window.draw(win);
}
