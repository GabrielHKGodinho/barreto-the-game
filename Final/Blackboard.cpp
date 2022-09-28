#include "Blackboard.h"



Blackboard::Blackboard(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
	Platform(nullptr, size, position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);

	sf::Vector2f entidadesize(size.x, size.y * 45.0f);
	board.setSize(entidadesize);
	board.setOrigin(entidadesize / 2.0f);
	board.setPosition(sf::Vector2f(position.x, position.y - (entidadesize.y)/2.0f + size.y));
	board.setTexture(texture);
}


Blackboard::~Blackboard()
{
}

void Blackboard::Draw(sf::RenderWindow & window)
{
	window.draw(board);
}
