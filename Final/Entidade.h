#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorColisoes.h"
#include "Entidade.h"
//#include "Player.h"

class Entidade
{
public:
	Entidade();
	Entidade(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float push=1.0f);
	virtual ~Entidade();
	float push;

	virtual void Draw(sf::RenderWindow& window);
	virtual GerenciadorColisoes GetGerenciadorColisoes() { return GerenciadorColisoes(body); }
	virtual void Update(float deltaTime) {}

	virtual void OnCollision(sf::Vector2f direction);

	void setVelocity(sf::Vector2f vel) { velocity = vel; }
	sf::Vector2f getVelocity() { return velocity; }

	sf::RectangleShape* getBody() { return &body; }

protected:
	sf::RectangleShape body;
	sf::Vector2f velocity;
};

