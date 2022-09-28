#include "Entidade.h"



Entidade::Entidade()
{
}

Entidade::Entidade(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float push)
{
	this->push = push;

	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}


Entidade::~Entidade()
{
}

void Entidade::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Entidade::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
}
